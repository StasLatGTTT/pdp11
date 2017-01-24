/*
	Describe interstate of instruction execution between fetch, work and
	writeback
	Asignee: Yaroslav
*/
#pragma once

#include <cstdint>

struct Interstate{
	uint8_t statword;

	uint16_t pc;
	int16_t pc_delta;

	uint8_t opcode;
	int8_t offset;
	uint8_t mode1;//src adr mode
	uint8_t mode2;//dst adr mode

	uint16_t src; //reg val
	uint16_t dst; //reg val

	int16_t src_delta;
	int16_t dst_delta;

	uint16_t src_val;
	uint16_t src_adr;

	uint16_t dst_val;
	uint16_t dst_adr;
};
