#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

using namespace std;

int main(int argc, char** argv){

	Metadata* meta = new Metadata();


	Proc* cpu = new Proc(meta);

	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	delete cpu;
	delete meta;

	return ret;
}
