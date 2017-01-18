/*
	Class o save data about every decoded instruction
*/
#pragma once

#include "interstate.h"
#include "instr_entry.h"

class Instructions{

public:
	Instruction_entry* decode;

	Instructions();
	~Instructions();

	//call every init_ method from below
	void init_all();

private:
	void init_add();
};
