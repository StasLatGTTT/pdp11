#include "emulator.h"

#include "../../ui_testwidget.h"

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

	//QTextEdit tedit;
	//tedit.show();

	QWidget *widget = new QWidget;
	Ui::TestWidget ui;
	ui.setupUi(widget);

	widget->show();

	return emul_app->exec();
}
