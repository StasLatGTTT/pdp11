#include "gui_test.h"

using namespace std;

int everything(int t){
	int b = t * t % (t + t);
	cout<<"Everything is "<< b <<endl;
	return b;
}
