#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"
#include <iostream>

int execute_add(Interstate* state, Instruction_entry* entry)
{
  int8_t flags=0;
  //1- Carry
  //2- Overflow
  //4- Zero
  //8- Negative
  int16_t result=0;
  int32_t check_result=0;

  printf("\nstate->src= %d\n", state->src);
  printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta;
  state->src= state->src + state->src_delta;
  state->dst= state->dst + state->dst_delta;

  result= state->src_val + state->dst_val;
  check_result= state->src_val + state->dst_val;
  if (result != check_result)
  {
      flags+= 1;
  }
  if (((state->src_val)*(state->dst_val)>0) &&(result*(state->src_val)<0))
  {
      flags+= 2;
  }
  if (result == 0)
  {
      flags+= 4;
  }
  if (result <0)
  {
      flags+= 8;
  }

  state->dst_val= result;
  state->statword= state->statword | flags;

  printf("state->src= %d\n", state->src);
  printf("state->dst= %d\n", state->dst);

  return 0;
}
