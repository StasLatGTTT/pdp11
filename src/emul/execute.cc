#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"
#include <iostream>

int execute_add(Interstate* state, Instruction_entry* entry)
{
  int8_t overflow=0; //for future
  int16_t result=0;
  printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta;
  state->src= state->src + state->src_delta;
  state->dst= state->dst + state->dst_delta;
  result= state->src_val + state->dst_val;
  state->dst_val= result;
   printf("state->dst= %d\n", state->dst);

  return 0;
}
