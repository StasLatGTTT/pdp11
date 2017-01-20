/*
	Implementation of _fetch, _execute and _writeback of
	every possible instruction
*/
#pragma once

#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"

//add instruction implementation
int add_fetch(Interstate*, Memory_unit*, Instruction_entry*);
int add_execute(Interstate*, Instruction_entry*);
int add_writeback(Interstate*, Memory_unit*, Instruction_entry*);
void add_disasm(Instruction_entry*);
