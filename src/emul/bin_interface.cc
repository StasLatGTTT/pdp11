#include <stdio.h>
#include <iostream>

#include "bin_interface.h"

Bin_interface::Bin_interface(){
	size = 256;
	buffer = new uint8_t[size];
}

Bin_interface::~Bin_interface(){
	delete buffer;
}

void Bin_interface::load_to_memory(Memory_unit* memory, char* filename, \
uint16_t* len, uint16_t adr) {
	uint16_t num_read = 0;
	FILE* fd = fopen(filename, "r");
	do{
		num_read = fread(buffer, 1, size, fd);
		memory->store_line(adr + *len, num_read, buffer);
		*len += num_read;
	} while(num_read == size);
	fclose(fd);
}

void Bin_interface::save_to_bin(Memory_unit* memory, char* filename, \
uint16_t* len, uint16_t adr) {
	FILE* fd = fopen(filename, "w");

	fclose(fd);
}
