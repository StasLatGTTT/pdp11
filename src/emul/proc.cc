#include <cstring>
#include <iostream>


#include "proc.h"
#include "bin_interface.h"

using namespace std;

/*Proc::Proc(Metadata* metadata){
	memory = new Memory_unit();
	state = new Interstate();
	decode = new Instruction_entry[65536];

	ticks_seqential = 0;
	ticks_pipelined = 0;

	meta = metadata;

	memory->PC = meta->prog_start;
	memory->SP = meta->stack_root;
}*/

Proc::Proc(Metadata* metadata, char* rom, char* prog){
	memory = new Memory_unit();
	state = new Interstate();
	instruction = new Instructions();

	ticks_seqential = 0;
	ticks_pipelined = 0;

	meta = metadata;

	/*
	int16_t GOD, DEVIL;
	GOD = 0xBEEF;
	memory->store_word(0, &GOD);
	memory->read_word(0, &DEVIL);
	std::cout<<std::hex<<GOD<<" vs. "<<DEVIL<<std::endl;
	*/
	memory->PC = meta->prog_start;
	memory->SP = meta->stack_root;

	Bin_interface* loader = new Bin_interface();
	loader->load_to_memory(memory, rom, &(meta->rom_len), 0);
	loader->load_to_memory(memory, prog, &(meta->prog_len), meta->prog_start);
	delete loader;
}

Proc::~Proc(){
	delete memory;
	delete state;
	delete instruction;
}

void Proc::step(){
	state->pc = memory->registers[7];
	uint16_t instr;
	memory->read_word(state->pc, &instr);
	entry = &(instruction->decode[instr]);
	printf("Entry[%x] inited\n", instr );

	entry->fetch(state, memory, entry);
	// printf(" -- fetch\n" );
	entry->execute(state, entry);
	// printf(" -- execute\n" );
	entry->writeback(state, memory, entry);
	// printf(" -- writeback\n" );
	printf("ASM:\t%s\n", entry->description);

}
