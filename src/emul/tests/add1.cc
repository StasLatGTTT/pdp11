#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

#include "emul/instr_implementation.h"
#include "emul/memory_unit.h"

using namespace std;

/*
int main(int argc, char** argv){
	Proc* cpu = new Proc(4095, 4096);

	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;

	return ret;
}
//*/

int main(int argc, char** argv){
	Proc* cpu = new Proc(4095, 4096);

	int32_t fake = 0;

	cpu->memory->registers[1] = (int16_t)2;
	cpu->memory->registers[2] = (int16_t)4;

	int16_t var = 10;
	cpu->memory->store_word(4, &var);
	var = 20;
	cpu->memory->store_word(10, &var);

	var = 30;
	cpu->memory->store_word(2, &var);

	printf("R1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	Instruction_entry entry;
	entry.mode1 = 0;
	entry.mode2 = 4;
	entry.src = 1;
	entry.dst = 2;

	fetch_two_operand_1(cpu->state, cpu->memory, &entry);
	execute_add(cpu->state, &entry);
	writeback_two_operand_1(cpu->state, cpu->memory, &entry);

	printf("\tResult:\nR1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	cpu->memory->read_word(4, &var);
	printf("ram[4]= %d\n", var);
	cpu->memory->read_word(10, &var);
	printf("ram[10]= %d\n", var);

	cpu->memory->read_word(2, &var);
	printf("ram[2]= %d\n", var);
	cpu->memory->read_word(30, &var);
	printf("ram[30]= %d\n", var);


	delete cpu;
	return 0;
}
