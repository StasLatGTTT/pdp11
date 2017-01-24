/*
	Single entry for decoded instructions array
*/

#pragma once

#include "memory_unit.h"

struct Instruction_entry{
	char description[64];
	uint8_t opcode;
	int8_t offset; //critical fix
	uint8_t mode1;
	uint8_t mode2;
	uint8_t src;
	uint8_t dst;

	int32_t (*fetch)(Interstate*, Memory_unit*, Instruction_entry*);
	int32_t (*execute)(Interstate*, Instruction_entry*);
	int32_t (*writeback)(Interstate*, Memory_unit*, Instruction_entry*);
	void (*disasm)(Instruction_entry*);
};
