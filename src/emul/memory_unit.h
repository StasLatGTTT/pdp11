/*
	CPU whole memory: ram, registers, statword
*/
#pragma once

#include <cstdint>

class Memory_unit{
	int8_t* ram;
public:
	int16_t registers[8];
	int8_t statword;

	Memory_unit();
	~Memory_unit();

	int32_t read_word(int16_t adr, int16_t* dst);
	int32_t store_word(int16_t adr, int16_t* src);
	int32_t read_byte(int16_t adr, int8_t* dst);
	int32_t store_byte(int16_t adr, int8_t* src);
};
