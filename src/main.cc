#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

using namespace std;

int main(int argc, char** argv){

	Metadata meta;

	
	Proc* cpu = new Proc(4095, 4096);

	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;

	return ret;
}
