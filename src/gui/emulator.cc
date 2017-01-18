#include "emulator.h"

Emulator_App::Emulator_App(int argc, char** argv, Proc* cpu){
	this->cpu = cpu;
	this->argc = argc;
	this->argv = argv;
}

Emulator_App::~Emulator_App(){
	delete emul_app;
};

int Emulator_App::run(){
	emul_app = new QApplication(argc, argv);

	QTextEdit tedit;
	tedit.show();

	return emul_app->exec();
}
