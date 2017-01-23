/*
	CPU whole memory: ram, registers, statword
*/
#pragma once

#include <cstdint>

#define R0 registers[0]
#define R1 registers[1]
#define R2 registers[2]
#define R3 registers[3]
#define R4 registers[4]
#define R5 registers[5]
#define R7 registers[6]
#define R8 registers[7]

#define SP registers[0x06]
#define PC registers[0x07]

class Memory_unit{
	int8_t* ram;
public:
	int16_t registers[8];
	int8_t statword;

	Memory_unit();
	~Memory_unit();

	//read/write data from ram with respect to endianness
	int32_t read_word(int16_t adr, int16_t* dst);
	int32_t store_word(int16_t adr, int16_t* src);
	int32_t read_byte(int16_t adr, int8_t* dst);
	int32_t store_byte(int16_t adr, int8_t* src);

	//read/write data lines - to endianness respect
	void read_line(int16_t adr, int16_t len, int8_t* dst);
	void store_line(int16_t adr, int16_t len, int8_t* src);

	uint16_t swap_bytes(uint16_t);
};
