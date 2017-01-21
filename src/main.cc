#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

using namespace std;

int main(int argc, char** argv){

	Metadata* meta = new Metadata();


	Proc* cpu = new Proc(meta);

	meta->prog_start = 0x2000; //2^13 = 8192
	meta->stack_root = 0xbfff; //2^15 + 2^14 - 1 = 32767
	meta->vram_map = 0xc000; //2^15 + 2^14 = 49152
	meta->vram_len = 0x1000; //2^12 = 4096
	meta->io_map = 0xe000; //2^15 + 2^14 + 2^13 = 57344
	meta->io_map = 0x400; //2**10 = 1024

	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;
	delete meta;

	return ret;
}
