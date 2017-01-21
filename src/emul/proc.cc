#include <cstring>

#include "proc.h"
#include "bin_interface.h"

Proc::Proc(uint16_t stack, uint16_t prog){
	memory = new Memory_unit();
	state = new Interstate();
	decode = new Instruction_entry[65536];

	ticks_seqential = 0;
	ticks_pipelined = 0;

	this->stack = stack;
	this->prog = prog;
}

Proc::Proc(uint16_t stack, uint16_t prog, char* bin){
	memory = new Memory_unit();
	state = new Interstate();
	decode = new Instruction_entry[65536];

	ticks_seqential = 0;
	ticks_pipelined = 0;

	this->stack = stack;
	this->prog = prog;

	Bin_interface* loader = new Bin_interface();
	loader->load_to_memory(memory, bin, &(this->prog_len), prog);
	delete loader;
}

Proc::~Proc(){
	delete memory;
	delete state;
	delete[] decode;
}

void Proc::step(){
	state->pc = memory->registers[7];
	int16_t instr;
	memory->read_word(state->pc, &instr);
	entry = &(decode[instr]);

	entry->fetch(state, memory, entry);
	entry->execute(state, entry);
	entry->writeback(state, memory, entry);
}
