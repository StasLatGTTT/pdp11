#include <cstring>

#include "memory_unit.h"

Memory_unit::Memory_unit(){
	ram = new int8_t[65536];
}

Memory_unit::~Memory_unit(){
	delete ram;
}

int32_t Memory_unit::read_word(int16_t adr, int16_t* dst){
	int16_t hi = (int16_t) ram[adr + 1], lo = (int16_t) ram[adr];
	*dst = (hi << 8) + lo;
	return -1;
}

int32_t Memory_unit::store_word(int16_t adr, int16_t* src){
	int16_t hi = (*src) / 256, lo = (*src) % 256;
	ram[adr + 1] = (int8_t) hi;
	ram[adr] = (int8_t) lo;
	return -1;
}

int32_t Memory_unit::read_byte(int16_t adr, int8_t* dst){
	*dst = ram[adr];
	return -1;
}

int32_t Memory_unit::store_byte(int16_t adr, int8_t* src){
	ram[adr] = *src;
	return -1;
}

void Memory_unit::read_line(int16_t adr, int16_t len, int8_t* dst){
	memcpy(dst, &ram[adr], len);
}

void Memory_unit::store_line(int16_t adr, int16_t len, int8_t* src){
	memcpy(&ram[adr], src, len);
}
