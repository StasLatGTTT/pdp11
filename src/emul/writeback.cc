#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"

int writeback_two_operand_1_word(Interstate* state, Memory_unit* memory,\
   Instruction_entry* entry)
{
    memory->registers[7]= state->pc;
    memory->registers[entry->src]= state->src;
    memory->registers[entry->dst]= state->dst;
    memory->statword= state->statword;

  if (entry->mode2 != 0)
  {
    // memory->ram[state->dst_adr]= state->dst_val;
    memory->store_word(state->dst_adr, &(state->dst_val));
  }
  else
  {
    memory->registers[entry->dst] = state->dst_val;
  }

  return 0;
}

int writeback_two_operand_1_byte(Interstate* state, Memory_unit* memory,\
   Instruction_entry* entry)
{
    int8_t tmp_val =0;
    tmp_val= (int8_t)(state->dst_val);

    memory->registers[7]= state->pc;
    memory->registers[entry->src]= state->src;
    memory->registers[entry->dst]= state->dst;
    memory->statword= state->statword;

  if (entry->mode2 != 0)
  {
    // int8_t tmp_val =0;
    // memory->ram[state->dst_adr]= state->dst_val;
    // tmp_val= (int8_t)(state->dst_val)
    memory->store_byte(state->dst_adr, &tmp_val);
  }
  else
  {
    // memory->registers[entry->dst] = state->dst_val;
    memory->registers[entry->dst]= (((memory->registers[entry->dst])>>8)<<8)+\
     state->dst_val;
  }

  return 0;
}

int writeback_conditional_branch(Interstate* state, Memory_unit* memory,\
   Instruction_entry* entry)
{
    memory->registers[7]= state->pc;

    return 0;
}
