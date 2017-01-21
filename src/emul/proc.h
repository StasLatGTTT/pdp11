/*
	Class to emulate CPU
*/
#pragma once

#include <cstdint>

#include "instr_decoded.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "metadata.h"

class Proc{
	//64-bit
	Instruction_entry* entry;
	Instruction_entry* decode;
	Interstate* state;

public:
	Memory_unit* memory;
	//32-bit
	int32_t ticks_seqential, ticks_pipelined;
	uint16_t stack, prog, prog_len;
	Metadata meta;

	Proc(uint16_t, uint16_t);
	Proc(uint16_t, uint16_t, char*);
	~Proc();

	void step();
};
