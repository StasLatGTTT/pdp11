#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

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

	cpu->memory->registers[0] = 1;
	cpu->memory->registers[1] = 1;

	delete cpu;
	return 0;
}
