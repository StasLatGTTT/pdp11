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

  // printf("\nstate->src= %d\n", state->src);
  // printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta;
  state->src= state->src + state->src_delta;
  state->dst= state->dst + state->dst_delta;

  result= state->src_val + state->dst_val;
  check_result= state->src_val + state->dst_val;

  if ((1<<16)& check_result)
  {
      flags+= 1;
  }
  if (((state->src_val)*(state->dst_val)>0) &&(result*(state->src_val)<=0))
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

  // printf("state->src= %d\n", state->src);
  // printf("state->dst= %d\n", state->dst);

  return 0;
}

int execute_sub(Interstate* state, Instruction_entry* entry)
{
    state->src_val*= -1;
    execute_add(state, entry);

    return 0;
}

int execute_mov(Interstate* state, Instruction_entry* entry)
{
    int8_t flags=0;
    //1- Carry
    //2- Overflow
    //4- Zero
    //8- Negative
    int16_t result=0;
    int32_t check_result=0;

    state->pc= state->pc + state->pc_delta;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;

    result= state->src_val;

    //No Carru-flag for this operation
    //Overflow-flag =0 for this operation

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

    return 0;
}

int execute_cmp(Interstate* state, Instruction_entry* entry)
{
    int8_t flags=0;
    int16_t result=0;
    int32_t check_result=0;

    state->dst_val*= -1;
    state->pc= state->pc + state->pc_delta;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;

    result= state->src_val + state->dst_val;
    check_result= state->src_val + state->dst_val;

    if ((1<<8)& check_result)
    {
        flags+= 1;
    }
    if (((state->src_val)*(state->dst_val)>0) &&(result*(state->src_val)<=0))
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
    state->statword= state->statword | flags;

    return 0;
}

int execute_bit(Interstate* state, Instruction_entry* entry)
{
    int8_t flags=0;
    int16_t result=0;

    state->dst_val*= -1;
    state->pc= state->pc + state->pc_delta;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;

    result= state->src_val & state->dst_val;

    if (((state->src_val)*(state->dst_val)>0) &&(result*(state->src_val)<=0))
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
    state->statword= state->statword | flags;

    return 0;
}

int execute_bic(Interstate* state, Instruction_entry* entry)
{
    int8_t flags=0;
    int16_t result=0;

    state->pc= state->pc + state->pc_delta;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;
    //D &= ^S
    result= (state->dst_val)&(~(state->src_val));


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

    return 0;
}

int execute_bis(Interstate* state, Instruction_entry* entry)
{
    int8_t flags=0;
    int16_t result=0;

    state->pc= state->pc + state->pc_delta;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;
    result= (state->dst_val)|(state->src_val);

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

    return 0;
}

int execute_addb(Interstate* state, Instruction_entry* entry)
{
  int8_t flags=0;
  //1- Carry
  //2- Overflow
  //4- Zero
  //8- Negative
  int8_t result=0;
  int16_t check_result=0;

  // printf("\nstate->src= %d\n", state->src);
  // printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta;
  state->src= state->src + state->src_delta;
  state->dst= state->dst + state->dst_delta;

  result= state->src_val + state->dst_val;
  check_result= state->src_val + state->dst_val;

  if ((1<<8)& check_result)
  {
      flags+= 1;
  }
  if (((state->src_val)*(state->dst_val)>0) &&(result*(state->src_val)<=0))
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

  return 0;
}
