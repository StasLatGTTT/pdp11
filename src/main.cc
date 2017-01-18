#include <iostream>
#include <QApplication>
#include <QTextEdit>

using namespace std;

int main(int argc, char** argv){
	//cout<<"Hello world!"<<endl;
	QApplication app(argc, argv);

	QTextEdit tedit;
	tedit.show();

	return app.exec();
}
