#include "memory_unit.h"

struct instruction_entry{
	char[64] description;
	int8_t opcode;
	int8_t offset;
	int8_t mode1;
	int8_t mode2;
	int8_t src;
	int8_t dst;

	int32_t (*fetch)(interstate*, memory_unit*, instruction_entry*);
	int32_t (*execute)(interstate*, instruction_entry*);
	int32_t (*writeback)(interstate*, memory_unit*, instruction_entry*);
	void (*disasm)(instruction_entry*);
};
