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

	int8_t fake = 0;

	cpu->memory->registers[7] = 100;
	cpu->memory->registers[1] = 4;
	cpu->memory->registers[2] = 2;

	printf("R1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	Instruction_entry entry;
	entry.mode1 = 0;
	entry.mode2 = 0;
	entry.src = 1;
	entry.dst = 2;

	// fetch_two_operand_1_word(cpu->state, cpu->memory, &entry);
	// execute_add(cpu->state, &entry);
	// writeback_two_operand_1_word(cpu->state, cpu->memory, &entry);
	fetch_two_operand_1_byte(cpu->state, cpu->memory, &entry);
	execute_addb(cpu->state, &entry);
	writeback_two_operand_1_byte(cpu->state, cpu->memory, &entry);

	printf("\tResult:\nR1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	delete cpu;
	return 0;
}
