#include <iostream>

#include "emul/proc.h"
#include "gui/emulator.h"

using namespace std;

int main(int argc, char** argv){
	cout<<"Hello world!"<<endl;

	proc* cpu = NULL;
	Emulator_App emulator(argc, argv, cpu);
	int ret = emulator.run();

	//delete cpu;

	return ret;
}
