/*
	Implementation of _fetch, _execute and _writeback of
	every possible instruction
*/
#pragma once

#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"

//fetch implementations
int fetch_two_operand_1_word(Interstate*, Memory_unit*, Instruction_entry*);
int fetch_two_operand_1_byte(Interstate*, Memory_unit*, Instruction_entry*);
int fetch_conditional_branch(Interstate*, Memory_unit*, Instruction_entry*);
// int fetch_two_operand_2(Interstate*, Memory_unit*, Instruction_entry*);

//writeback implementations
int writeback_two_operand_1_word(Interstate*, Memory_unit*, Instruction_entry*);
int writeback_two_operand_1_byte(Interstate*, Memory_unit*, Instruction_entry*);
int writeback_conditional_branch(Interstate*, Memory_unit*, Instruction_entry*);
// int writeback_two_operand_2(Interstate*, Memory_unit*, Instruction_entry*);

//two operand executions
//TODO first two tables from pdp-11 architecture wiki article
//https://en.wikipedia.org/wiki/PDP-11_architecture
int execute_add(Interstate*, Instruction_entry*);
int execute_addb(Interstate*, Instruction_entry*); //bit // DOES NOT EXIST
int execute_sub(Interstate*, Instruction_entry*);
int execute_subb(Interstate*, Instruction_entry*); //bit // DOES NOT EXIST
int execute_mov(Interstate*, Instruction_entry*);
int execute_movb(Interstate*, Instruction_entry*); //bit
int execute_cmp(Interstate*, Instruction_entry*);
int execute_cmpb(Interstate*, Instruction_entry*); //bit
int execute_bit(Interstate*, Instruction_entry*);
int execute_bitb(Interstate*, Instruction_entry*); //bit
int execute_bic(Interstate*, Instruction_entry*);
int execute_bicb(Interstate*, Instruction_entry*); //bit
int execute_bis(Interstate*, Instruction_entry*);
int execute_bisb(Interstate*, Instruction_entry*); //bit

//branch condition executions
int execute_br(Interstate*, Instruction_entry*);
int execute_bne(Interstate*, Instruction_entry*);
int execute_beq(Interstate*, Instruction_entry*);
int execute_bge(Interstate*, Instruction_entry*);//?
int execute_blt(Interstate*, Instruction_entry*);//?
int execute_bgt(Interstate*, Instruction_entry*);//?
int execute_ble(Interstate*, Instruction_entry*);//?
int execute_bpl(Interstate*, Instruction_entry*);
int execute_bmi(Interstate*, Instruction_entry*);
int execute_bhi(Interstate*, Instruction_entry*);//?
int execute_blos(Interstate*, Instruction_entry*);//?
int execute_bvc(Interstate*, Instruction_entry*);
int execute_bvs(Interstate*, Instruction_entry*);
int execute_bcc(Interstate*, Instruction_entry*);
int execute_bhis(Interstate*, Instruction_entry*);
int execute_bcs(Interstate*, Instruction_entry*);
int execute_blo(Interstate*, Instruction_entry*);
