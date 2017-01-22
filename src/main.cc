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

	long long unsigned i =0, j =0;
	int8_t bw=0, op=0;
	int16_t op4 =0;
	int8_t mode_src, mode_dst, res_src, res_dst;

	for (i=0; i<65536; i++)
	{
		op4= i & 0xF000;

		if(op4 ==0x1000)
		{
			j= i;
			while (1)
			{
				//
				cpu->decode[i].src= res_src;
				cpu->decode[i].dst= res_dst;
				cpu->decode[i].mode1= mode_src;
				cpu->decode[i].mode2= mode_dst;
				cpu->decode[i].fetch= res_dst;
				cpu->decode[i].dst= res_dst;
				cpu->decode[i].dst= res_dst;

				cpu->decode[i].fetch= fetch_two_operand_1_word;
				cpu->decode[i].execute= execute_mov;
				cpu->decode[i].writeback= writeback_two_operand_1_word;
			}

		}


	}

	cpu->memory->registers[7] = 100;
	cpu->memory->registers[1] = 4; //4
	cpu->memory->registers[2] = 2;

	printf("R1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	//  fetch_two_operand_1_word(cpu->state, cpu->memory, &entry);
	//  execute_mov(cpu->state, &entry);
	//  writeback_two_operand_1_word(cpu->state, cpu->memory, &entry);

	Instruction_entry entry;
	int16_t instr= (1<<1)+(1<<6)+(1<<12);
	// entry = &(cpu->decode[instr]);
	//
	// entry->fetch(cpu->state, cpu->memory, entry);
	// entry->execute(cpu->state, entry);
	// entry->writeback(cpu->state, cpu->memory, entry);

	printf("\tResult:\nR1= %d\nR2= %d\n", cpu->memory->registers[1],\
	 cpu->memory->registers[2] );

	delete cpu;
	return 0;
}

void two_operand_init_1(Proc* cpu, long long unsigned i)
{
	// all int8_t
	cpu->decode[i].src= res_src;
	cpu->decode[i].dst= res_dst;
	cpu->decode[i].mode1= mode_src;
	cpu->decode[i].mode2= mode_dst;
	cpu->decode[i].fetch= res_dst;
	cpu->decode[i].dst= res_dst;
	cpu->decode[i].dst= res_dst;
}
