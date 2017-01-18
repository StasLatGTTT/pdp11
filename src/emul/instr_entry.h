/*
	Single entry for decoded instructions array
*/

#pragma once

#include "memory_unit.h"

struct Instruction_entry{
	char description[64];
	int8_t opcode;
	int8_t offset;
	int8_t mode1;
	int8_t mode2;
	int8_t src;
	int8_t dst;

	int32_t (*fetch)(Interstate*, Memory_unit*, Instruction_entry*);
	int32_t (*execute)(Interstate*, Instruction_entry*);
	int32_t (*writeback)(Interstate*, Memory_unit*, Instruction_entry*);
	void (*disasm)(Instruction_entry*);
};
