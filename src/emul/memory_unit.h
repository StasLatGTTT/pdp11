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
	uint8_t* ram;
public:
	uint16_t registers[8];
	uint8_t statword;

	Memory_unit();
	~Memory_unit();

	//read/write data from ram with respect to endianness
	int32_t read_word(uint16_t adr, uint16_t* dst);
	int32_t store_word(uint16_t adr, uint16_t* src);
	int32_t read_byte(uint16_t adr, uint8_t* dst);
	int32_t store_byte(uint16_t adr, uint8_t* src);

	//read/write data lines - to endianness respect
	void read_line(uint16_t adr, uint16_t len, uint8_t* dst);
	void store_line(uint16_t adr, uint16_t len, uint8_t* src);

	uint16_t swap_bytes(uint16_t);
};
