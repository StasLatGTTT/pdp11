/*
	Class o save data about every decoded instruction
*/
#pragma once

#include "interstate.h"
#include "instr_entry.h"

class instructions{

public:
	instruction_entry* decode;

	instructions();
	~instructions();

	//call every init_ method from below
	void init_all();

private:
	void init_add();
};
