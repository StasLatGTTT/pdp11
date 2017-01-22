#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

#include "emul/instr_implementation.h"
#include "emul/memory_unit.h"

using namespace std;

// int main(int argc, char** argv){
// 	Proc* cpu = new Proc(4095, 4096);
//
// 	Emulator_App emulator(argc, argv, cpu);
// 	int ret = emulator.run();
//
// 	delete cpu;
//
// 	return ret;
// }

int main(int argc, char** argv){
	Proc* cpu = new Proc(4095, 4096);

	// Instructions *table;
	Instructions* table;
	table= new Instructions;
	Instruction_entry *entry;

	cpu->memory->registers[7] = 100;
	cpu->memory->registers[1] = 4; //4
	cpu->memory->registers[2] = 2; //2

	table->init_all();
	printf("Decode table initialised\n");
	printf("table[0x1042].src= %d\n", table->decode[0x1042].src);
	printf("table[0x1042].mode1= %d\n", table->decode[0x1042].mode1);
	printf("table[0x1042].dst= %d\n", table->decode[0x1042].dst);
	printf("table[0x1042].mode2= %d\n", table->decode[0x1042].mode2);
	printf("\tStart:\nR1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );


	int16_t instr= 0x1042;
	entry = &(table->decode[instr]);

	entry->fetch(cpu->state, cpu->memory, entry);
	entry->execute(cpu->state, entry);
	entry->writeback(cpu->state, cpu->memory, entry);

	printf("\tResult:\nR1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	delete cpu;
	return 0;
}
