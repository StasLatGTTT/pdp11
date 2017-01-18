/*
	Class to emulate CPU
*/
#pragma once

#include <cstdint>

#include "instr_decoded.h"
#include "memory_unit.h"
#include "instr_entry.h"

class Proc{
	//64-bit
	Memory_unit* memory;
	Instruction_entry* entry;
	Instruction_entry* decode;
	Interstate* state;

	//32-bit
	int32_t ticks_seqential, ticks_pipelined;

public:
	Proc();
	~Proc();

	void step();
};
