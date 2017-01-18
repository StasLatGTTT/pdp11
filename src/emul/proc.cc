#include "proc.h"

Proc::Proc(){
	memory = new Memory_unit();
	state = new Interstate();
	decode = new Instruction_entry[65536];
}

Proc::~Proc(){
	delete memory;
	delete state;
	delete decode;
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
