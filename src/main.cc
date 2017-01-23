#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	cpu->memory->registers[1] = 2; //4
	cpu->memory->registers[2] = 4; //2

	// cpu->memory->ram[4]= 100;
	// cpu->memory->ram[2]= 50;
	int16_t val;
	// unsigned val;
	val =50;
	cpu->memory->store_word(2, &val);
	val =100;
	cpu->memory->store_word(4, &val);

	table->init_all();
	printf("Decode table initialised\n");
	// int16_t instr= 0x124a; // 0x1042
	// int16_t instr= 0b0000000000000000;
	// int16_t instr= 0b0110001001001010;//0b0000000000000000;
	// int16_t instr = 0x010a;
	int16_t instr = 0x6042;

	// cout<< "Hex 0x"<< hex << instr << "= Dec " << dec << instr << endl;
	printf("table[%x].src= \t%d\n", instr, table->decode[instr].src);
	printf("table[%x].mode1= \t%d\n", instr, table->decode[instr].mode1);
	printf("table[%x].dst= \t%d\n", instr, table->decode[instr].dst);
	printf("table[%x].mode2= \t%d\n", instr, table->decode[instr].mode2);
	printf("table[%x].descr= \t%s\n", instr, table->decode[instr].description);

	printf("\tStart:\nR1= %d\nR2= %d\nR7= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2], cpu->memory->registers[7] );

	 cpu->memory->read_word(2, &val);
	 printf("RAM[2]= %d\n", val);
	 cpu->memory->read_word(4, &val);
	 printf("RAM[4]= %d\n", val);

	entry = &(table->decode[instr]);

	entry->fetch(cpu->state, cpu->memory, entry);
	entry->execute(cpu->state, entry);
	entry->writeback(cpu->state, cpu->memory, entry);

	printf("\tResult:\nR1= %d\nR2= %d\nR7= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2], cpu->memory->registers[7] );

	//  cpu->memory->read_word(2, &val);
	//  printf("RAM[2]= %d\n", val);
	printf("cpu->state->dst_adr= %d\n",cpu->state->dst_adr);
	printf("cpu->state->dst_val= %d\n",cpu->state->dst_val);
	cpu->memory->store_word(cpu->state->dst_adr, &(cpu->state->dst_val));
	printf("cpu->memory->store_word(cpu->state->dst_adr, &(cpu->state->dst_val));\n");
	cpu->memory->read_word(cpu->state->dst_adr, &val);
	printf("cpu->memory->read_word(cpu->state->dst_adr, &val);\n");
	printf("val= %i\n", val);
	cout<< hex << val <<endl;
	cpu->memory->read_word(4, &val);
	printf("S: RAM[4]= %d\n", val);
	printf("RAM[%d]= %d\n", cpu->state->dst_adr, cpu->state->dst_val);

	delete cpu;
	return 0;
}
