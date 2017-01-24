#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"
#include <iostream>

// word-operations
int execute_add(Interstate* state, Instruction_entry* entry)
{
  uint8_t flags=0;
  //1- Carry
  //2- Overflow
  //4- Zero
  //8- Negative
  uint16_t result=0;
  int32_t check_result=0;

  // printf("\nstate->src= %d\n", state->src);
  // printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta +2;
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
    uint8_t flags=0;
    //1- Carry
    //2- Overflow
    //4- Zero
    //8- Negative
    uint16_t result=0;
    int32_t check_result=0;

    state->pc= state->pc + state->pc_delta +2 ;
    state->src= state->src + state->src_delta+2;
    // if (state->src==7) state->pc= state->pc +2;
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
    uint8_t flags=0;
    uint16_t result=0;
    int32_t check_result=0;

    state->dst_val*= -1;
    state->pc= state->pc + state->pc_delta +2;
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
    state->statword= state->statword | flags;

    return 0;
}
int execute_bit(Interstate* state, Instruction_entry* entry)
{
    uint8_t flags=0;
    uint16_t result=0;

    state->dst_val*= -1;
    state->pc= state->pc + state->pc_delta +2;
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
    uint8_t flags=0;
    uint16_t result=0;

    state->pc= state->pc + state->pc_delta +2;
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
    uint8_t flags=0;
    uint16_t result=0;

    state->pc= state->pc + state->pc_delta +2;
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

// bit-operations
int execute_addb(Interstate* state, Instruction_entry* entry)
{
  uint8_t flags=0;
  //1- Carry
  //2- Overflow
  //4- Zero
  //8- Negative
  uint8_t result=0;
  uint16_t check_result=0;

  // printf("\nstate->src= %d\n", state->src);
  // printf("state->dst= %d\n", state->dst);

  state->pc= state->pc + state->pc_delta +1;
  state->pc+= (state->pc)%2;
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

  // hi= (uint8_t)((state->dst_val)>>8)
  state->dst_val= (uint16_t)result;
  state->statword= state->statword | flags;

  return 0;
}
int execute_subb(Interstate* state, Instruction_entry* entry)
{
    state->src_val*= -1;
    execute_addb(state, entry);

    return 0;
}
int execute_movb(Interstate* state, Instruction_entry* entry)
{
    uint8_t flags=0;
    //1- Carry
    //2- Overflow
    //4- Zero
    //8- Negative
    uint8_t result=0;
    uint16_t check_result=0;

    state->pc= state->pc + state->pc_delta +1;
    state->pc+= (state->pc)%2;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;

    result= (uint8_t)state->src_val;

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

    state->dst_val= (uint16_t)result;
    state->statword= state->statword | flags;

    return 0;
}
int execute_cmpb(Interstate* state, Instruction_entry* entry)
{
    uint8_t flags=0;
    uint8_t result=0;
    uint16_t check_result=0;

    state->dst_val*= -1;
    state->pc= state->pc + state->pc_delta +1;
    state->pc+= (state->pc)%2;
    state->src= state->src + state->src_delta;
    state->dst= state->dst + state->dst_delta;

    result= (uint8_t)state->src_val + (uint8_t)state->dst_val;
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

//branch conditions
int execute_br(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;
    state->pc+= 2*state->pc_delta;

    return 0;
}
int execute_bne(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;
    if(((state->statword)&(1<<2)) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_beq(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;
    if(((state->statword)&(1<<2)) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bge(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);

    if((n ^ v) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_blt(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);

    if((n ^ v) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bgt(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);
    //Z|(N^V) = 0
    if((z | (n ^ v)) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_ble(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);

    if((z | (n ^ v)) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bpl(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<3)) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bmi(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<3)) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bhi(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);
    //C|Z = 0
    if((c | z) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_blos(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    int c= (state->statword)&(1<<0);
    int v= (state->statword)&(1<<1);
    int z= (state->statword)&(1<<2);
    int n= (state->statword)&(1<<3);
    //C|Z = 1
    if((c | z) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bvc(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<1)) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bvs(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<1)) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bcc(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<0)) ==0)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_bhis(Interstate* state, Instruction_entry* entry)
{
    return execute_bcc(state, entry);
}
int execute_bcs(Interstate* state, Instruction_entry* entry)
{
    state->pc+=2;

    if(((state->statword)&(1<<0)) ==1)
    {
        state->pc+= 2*state->pc_delta;
    }

    return 0;
}
int execute_blo(Interstate* state, Instruction_entry* entry)
{
    return execute_bcs(state, entry);
}

// system comands
int execute_halt(Interstate* state, Instruction_entry* entry)
{
    state->pc+= 2;
    state->statword |= 0b11100000;
    return 0;
}
int execute_wait(Interstate* state, Instruction_entry* entry)
{
    state->pc+= 0;
    return 0;
}
int execute_reset(Interstate* state, Instruction_entry* entry)
{
    state->pc= 0;
    // TODO RESET
    return 0;
}
int execute_nop(Interstate* state, Instruction_entry* entry)
{
    state->pc+= 2;
    return 0;
}
