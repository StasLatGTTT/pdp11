/*
	Implementation of _fetch, _execute and _writeback of
	every possible instruction
*/
#pragma once

#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"

//fetch implementations
int fetch_two_operand_1(Interstate*, Memory_unit*, Instruction_entry*);
int fetch_two_operand_2(Interstate*, Memory_unit*, Instruction_entry*);

//writeback implementations
int writeback_two_operand_1_(Interstate*, Memory_unit*, Instruction_entry*);
int writeback_two_operand_2(Interstate*, Memory_unit*, Instruction_entry*);

//two operand executions
//TODO first two tables from pdp-11 architecture wiki article
//https://en.wikipedia.org/wiki/PDP-11_architecture
int execute_add(Interstate*, Instruction_entry*);
