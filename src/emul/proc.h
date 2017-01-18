/*
	Class to emulate CPU
*/

#include <cstdint>

#include "instr_decoded.h"
#include "memory_unit.h"

class proc{
	//64-bit
	memory_unit* memory

	//32-bit
	int32_t ticks_seqential, ticks_pipelined;

public:
	proc();
	~proc();

	step();
}
