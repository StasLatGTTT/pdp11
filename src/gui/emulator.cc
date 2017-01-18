#include "emulator.h"

Emulator_App::Emulator_App(int argc, char** argv, proc* cpu){
	this->cpu = cpu;
	this->argc = argc;
	this->argv = argv;
}

Emulator_App::~Emulator_App(){};

int Emulator_App::run(){
	QApplication app(argc, argv);

	QTextEdit tedit;
	tedit.show();

	return app.exec();
}
