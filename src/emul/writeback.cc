#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"

int writeback_two_operand_1(Interstate* state, Memory_unit* memory,\
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

  //

  return 0;
}
