/*
	class to read and write files to memory_unit
*/

#include <iostream.h>
#include <cstdint>

#include "Memory_unit.h"

class Bin_interface{
	int32_t size;
	uint8_t* buffer;

public:
	Bin_interface();
	~Bin_interface();

	void load_to_memory(Memory_unit*, char*, int16_t);
	void save_to_bin(Memory_unit*, char*, int16_t, int16_t);
}
