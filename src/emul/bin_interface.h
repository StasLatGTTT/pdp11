/*
	class to read and write files to memory_unit
*/

#include <iostream>
#include <cstdint>

#include "memory_unit.h"

class Bin_interface {
	uint32_t size;
	uint8_t* buffer;

public:
	Bin_interface();
	~Bin_interface();

	void load_to_memory(Memory_unit*, char*, uint16_t*, uint16_t);
	void save_to_bin(Memory_unit*, char*, uint16_t*, uint16_t);
};
