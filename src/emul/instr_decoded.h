/*
	Class o save data about every decoded instruction
*/

#include "interstate.h"
#include "instruction_entry.h"

class instructions{

public:
	instruction_entry* decode;

	instructions();
	~instructions();

	//call every init_ method from below
	init_all();

private:
	init_add();
}
