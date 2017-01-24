#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

using namespace std;

int main(int argc, char** argv){

	char rom[32] = "config/rom.bin";
	char prog[32] = "config/program.bin";

	Metadata* meta = new Metadata();
	meta->prog_start = 0x2000; //2^13 = 8192
	meta->stack_root = 0xbfff; //2^15 + 2^14 - 1 = 32767
	meta->vram_map = 0xc000; //2^15 + 2^14 = 49152
	meta->vram_len = 0x1000; //2^12 = 4096
	meta->io_map = 0xe000; //2^15 + 2^14 + 2^13 = 57344
	meta->io_map = 0x400; //2**10 = 1024

	Proc* cpu = new Proc(meta, rom, prog);

	// uint16_t instr = 0x010a;
	// uint16_t instr = 0x0001;
	uint16_t var, instr = 0x0001;
	int8_t d= -2;
	printf("TEST= %x, %d\n", d, d);
	var= (int16_t)d;
	printf("TEST= %x, %d\n", var, var);
	d= 0;
	d= (int8_t)(var & 0x00FF);
	var&= 0x00FF;
	// printf("TEST= %x, %d\n", d, d);
	printf("TEST= %x, %d\n", var, var);
	// instr= (instr)<<8;
	// uint16_t instr = 0x6042;
	// uint16_t instr= 0xffff;
	cpu->memory->store_word(0x0000, &instr);

	cpu->memory->registers[7]=0;
	// printf("Step is to be passed\n" );
	printf("PC= %d\n", cpu->memory->registers[7]);
	cpu->step();
	// printf("Step passed\n" );
	printf("PC= %d\n", cpu->memory->registers[7]);


	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;
	delete meta;

	return ret;
}
