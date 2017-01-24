#include <cstring>

#include "memory_unit.h"

Memory_unit::Memory_unit(){
	ram = new uint8_t[65536];
}

Memory_unit::~Memory_unit(){
	delete ram;
}

int32_t Memory_unit::read_word(uint16_t adr, uint16_t* dst){
	uint16_t hi = (uint16_t) ram[adr + 1], lo = (uint16_t) ram[adr];
	*dst = (hi << 8) + (0x00FF & lo);
	return -1;
}

int32_t Memory_unit::store_word(uint16_t adr, uint16_t* src){
	if (adr < write_protected) return -1;
	uint16_t hi = ((uint16_t)(*src)) / 256, lo = ((uint16_t)(*src)) % 256;
	ram[adr + 1] = (uint8_t) hi;
	ram[adr] = (uint8_t) lo;
	return -1;
}

int32_t Memory_unit::read_byte(uint16_t adr, uint8_t* dst){
	*dst = ram[adr];
	return -1;
}

int32_t Memory_unit::store_byte(uint16_t adr, uint8_t* src){
	ram[adr] = *src;
	return -1;
}

void Memory_unit::read_line(uint16_t adr, uint16_t len, uint8_t* dst){
	memcpy(dst, &ram[adr], len);
}

void Memory_unit::store_line(uint16_t adr, uint16_t len, uint8_t* src){
	memcpy(&ram[adr], src, len);
}

uint16_t Memory_unit::swap_bytes(uint16_t byte){
	uint16_t new_byte = (byte & 0x00FF) << 8;
	new_byte += (byte & 0xFF00) / 256;
	return new_byte;
}
