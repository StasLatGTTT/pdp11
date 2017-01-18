/*
	Class to emulate CPU
*/
#pragma once

#include <cstdint>

#include "instr_decoded.h"
#include "memory_unit.h"
#include "instr_entry.h"

class proc{
	//64-bit
	memory_unit* memory;
	instruction_entry* entry;

	//32-bit
	int32_t ticks_seqential, ticks_pipelined;

public:
	proc();
	~proc();

	void step();
};
