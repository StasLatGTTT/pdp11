/*
	Describe interstate of instruction execution between fetch, work and
	writeback
	Asignee: Yaroslav
*/
#pragma once

#include <cstdint>

struct Interstate{
	uint16_t pc;

	uint8_t opcode;
	uint8_t mode1;
	uint8_t mode2;

	int16_t src;
	int16_t dst;
};
