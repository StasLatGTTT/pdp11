#include "bin_interface.h"

Bin_interface::Bin_interface(){
	size = 256u;
	buffer = new uint8_t[size];
}

Bin_interface::~Bin_interface(){
	delete buffer;
}

void Bin_interface::load_to_memory(Memory_unit* memory, char* filename, \
uint16_t adr) {
	FILE* fd = fopen(filename, "r");

	fclose(fd);
}

void Bin_interface::save_to_bin(Memory_unit* memory, char* filename, \
uint16_t adr, uint16_t len) {
	FILE* fd = fopen(filename, "w");

	fclose(fd);
}
