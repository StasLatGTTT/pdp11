/*
	Class to emulate CPU
*/

#include <cstdint>

#include "interstate.h"

class proc{
	//64-bit
	int8_t* memory;

	//32-bit
	int32_t ticks_seqential, ticks_pipelined;

	//16-bit
	int16_t[8] registers;

	//8-bit
	int8_t statword;
}
