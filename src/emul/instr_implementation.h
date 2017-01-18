/*
	Implementation of _fetch, _execute and _writeback of
	every possible instruction
*/

#include "interstate.h"
#include "memory_unit.h"
#include "instruction_entry.h"

//add instruction implementation
int add_fetch(interstate*, memory_unit*, instruction_entry*);
int add_execute(interstate*, instruction_entry*);
int add_writeback(interstate*, memory_unit*, instruction_entry*);
void add_disasm(instruction_entry*);
