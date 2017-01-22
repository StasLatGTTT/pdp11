#include <stdio.h>
#include <iostream>

#include "bin_interface.h"

Bin_interface::Bin_interface(){
	size = 256;
	buffer = new int8_t[size];
}

Bin_interface::~Bin_interface(){
	delete buffer;
}

void Bin_interface::load_to_memory(Memory_unit* memory, char* filename, \
uint16_t* len, uint16_t adr) {
	int16_t prog_len = 0, num_read = 0;
	std::cout<<filename<<std::endl;
	FILE* fd = fopen(filename, "r");
	do{
		num_read = fread(buffer, 1, size, fd);
		std::cout << num_read << std::endl;
		memory->store_line(adr + prog_len, num_read, buffer);
		prog_len += num_read;
	} while(num_read == size);
	fclose(fd);
	*len = prog_len;
}

void Bin_interface::save_to_bin(Memory_unit* memory, char* filename, \
uint16_t* len, uint16_t adr) {
	FILE* fd = fopen(filename, "w");

	fclose(fd);
}
