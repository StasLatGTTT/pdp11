/*
	Describe interstate of instruction execution between fetch, work and
	writeback
	Asignee: Yaroslav
*/
#pragma once

#include <cstdint>

struct Interstate{
	int8_t statword;
	
	uint16_t pc;
	uint16_t pc_delta;

	uint8_t opcode;
	uint8_t mode1;//src adr mode
	uint8_t mode2;//dst adr mode

	int16_t src; //reg val
	int16_t dst; //reg val

	int16_t src_delta;
	int16_t dst_delta;

	int16_t src_val;
	int16_t src_adr;

	int16_t dst_val;
	int16_t dst_adr;
};
