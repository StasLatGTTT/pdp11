#include "interstate.h"
#include "memory_unit.h"
#include "instr_entry.h"
#include "instr_implementation.h"
#include <iostream>

int fetch_two_operand_1_word(Interstate* state, Memory_unit* memory, \
    Instruction_entry* entry)
{
  int16_t val=0;
  int16_t pc=0;
  int16_t adr=0;
  int16_t nn=0;//index
  int32_t fake=0;

  //copy state
  state->mode1= entry->mode1;
  state->mode2= entry->mode2;
  state->src= memory->registers[entry->src];
  state->dst= memory->registers[entry->dst];
  state->pc= memory->registers[7];

  state->pc_delta= 0;
  state->src_delta= 0;
  state->dst_delta= 0;

  int8_t src= entry->src;
  int8_t dst= entry->dst;


  //src
  switch (entry->mode1)
  {
    case 0:
      // Rn
      // Register
      val= memory->registers[src];
      break;
    case 1:
      // @Rn
      // Register deferred
      adr= memory->registers[src];
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 2:
      // (@Rn)+
      //  Auto-increment
      adr= memory->registers[src];
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      state->src_delta= 2;
      //(memory->registers[n_reg])+= 2;
      //or +=1 for byte instruction
      //sp+=2
      //pc+=2;
      break;
    case 3:
      //@(Rn)+
      // Auto-increment deferred
      adr= memory->registers[src];
      state->src_delta= 2;
      //(memory->registers[src])+= 2;
      //allways +=2
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 4:
      //-(Rn)
      // Auto-decrement
      state->src_delta= -2;
      //(memory->registers[src])-= 2;
      //or 1, as earlier discribed
      adr= memory->registers[src] -2;
      //there is (-2) because of reg[src] no changes
      // val= memory->ram[adr];
      // CHECK ERROR !!
      memory->read_word(adr, &val);
      break;
    case 5:
      // @-(Rn)
      // Auto-decrement deferred
      state->src_delta= -2;
      // (memory->registers[src])-= 2;
      adr= memory->registers[src] -2;
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 6:
      //nnRn
      //index
      pc= memory->registers[7];
      // nn= memory->ram[pc];
      memory->read_word(pc, &nn);
      state->pc_delta= 2;
      //(memory->registers[7])+= 2;
      adr= memory->registers[src];
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      adr= adr + nn;
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 7:
      //@nnRn
      //index dereffered
      pc= memory->registers[7];
      // nn= memory->ram[pc];
      memory->read_word(pc, &nn);
      state->pc_delta= 2;
      // (memory->registers[7])+= 2;
      adr= memory->registers[src];
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // adr= memory->ram[adr+nn];
      memory->read_word(adr+nn, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
  }

  state->src_val= val;
  state->src_adr= adr;
  printf("src_reg= %d, %d, %d\n", src, adr, val);
  ///////////////////////////////////////////////////////////

  val=0;
  pc=0;
  adr=0;
  nn=0;//index



  // dst
  // it is like src, but dst
  switch (entry->mode2)
  {
    case 0:
      // Rn
      // Register
      val= memory->registers[dst];
      break;
    case 1:
      // @Rn
      // Register deferred
      adr= memory->registers[dst];
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
    //   printf("dst_reg= %d, %d, %d\n", dst, adr, val);
      break;
    case 2:
      // (@Rn)+
      //  Auto-increment
      adr= memory->registers[dst];
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      state->dst_delta= 2;
      //(memory->registers[n_reg])+= 2;
      //or +=1 for byte instruction
      //sp+=2
      //pc+=2;
      break;
    case 3:
      //@(Rn)+
      // Auto-increment deferred
      adr= memory->registers[dst];
      state->dst_delta= 2;
      //(memory->registers[dst])+= 2;
      //allways +=2
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 4:
      //-(Rn)
      // Auto-decrement
      state->dst_delta= -2;
      //(memory->registers[dst])-= 2;
      //or 1, as earlier discribed
      adr= memory->registers[dst] -2;
      //there is (-2) because of reg[dst] no changes
      // val= memory->ram[adr];
      // CHECK ERROR !!
      memory->read_word(adr, &val);
      break;
    case 5:
      // @-(Rn)
      // Auto-decrement deferred
      state->src_delta= -2;
      // (memory->registers[dst])-= 2;
      adr= memory->registers[dst] -2;
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 6:
      //nnRn
      //index
      pc= memory->registers[7];
      pc+= state->pc_delta;
      // becouse of the changes, made when src worked
      // ????
      // nn= memory->ram[pc];
      memory->read_word(pc, &nn);
      state->pc_delta= 2;
      //(memory->registers[7])+= 2;
      adr= memory->registers[dst];
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      adr= adr + nn;
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
    case 7:
      //@nnRn
      //index dereffered
      pc= memory->registers[7];
      pc+= state->pc_delta;
      // becouse of the changes, made when src worked
      // ????
      // nn= memory->ram[pc];
      memory->read_word(pc, &nn);
      state->pc_delta= 2;
      // (memory->registers[7])+= 2;
      adr= memory->registers[dst];
      // adr= memory->ram[adr];
      memory->read_word(adr, &adr);
      // adr= memory->ram[adr+nn];
      memory->read_word(adr+nn, &adr);
      // val= memory->ram[adr];
      memory->read_word(adr, &val);
      break;
  }

  state->dst_val= val;
  state->dst_adr= adr;
  printf("dst_reg= %d, %d, %d\n", dst, adr, val);

  return 0;
}
int fetch_two_operand_1_byte(Interstate* state, Memory_unit* memory, \
    Instruction_entry* entry)
{
  int8_t val=0;
  int8_t tmp_adr=0;
  int8_t nn=0;//index
  int16_t pc=0;
  int16_t adr=0;
  int32_t fake=0;

  //copy state
  state->mode1= entry->mode1;
  state->mode2= entry->mode2;
  state->src= memory->registers[entry->src];
  state->dst= memory->registers[entry->dst];
  state->pc= memory->registers[7];

  state->pc_delta= 0;
  state->src_delta= 0;
  state->dst_delta= 0;

  int8_t src= entry->src;
  int8_t dst= entry->dst;


  //src
  switch (entry->mode1)
  {
    case 0:
      // Rn
      // Register
      val= memory->registers[src];
      break;
    case 1:
      // @Rn
      // Register deferred
      adr= memory->registers[src];
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 2:
      // (@Rn)+
      //  Auto-increment
      adr= memory->registers[src];
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      state->src_delta= 1;
      if (src==6) state->src_delta= 2;
      if (src==7) state->src_delta= 2;
      //(memory->registers[n_reg])+= 2;
      //or +=1 for byte instruction
      //sp+=2
      //pc+=2;
      break;
    case 3:
      //@(Rn)+
      // Auto-increment deferred
      adr= memory->registers[src];
      state->src_delta= 2;
      //(memory->registers[src])+= 2;
      //allways +=2
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t)tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 4:
      //-(Rn)
      // Auto-decrement
      state->src_delta= -1;
      if (src==6) state->src_delta= -2;
      if (src==7) state->src_delta= -2;
      //(memory->registers[src])-= 2;
      //or 1, as earlier discribed
      adr= memory->registers[src] -2;
      //there is (-2) because of reg[src] no changes
      // val= memory->ram[adr];
      // CHECK ERROR !!
      memory->read_byte(adr, &val);
      break;
    case 5:
      // @-(Rn)
      // Auto-decrement deferred
      state->src_delta= -2;
      // (memory->registers[src])-= 2;
      adr= memory->registers[src] -2;
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t)tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 6:
      //nnRn
      //index
      pc= memory->registers[7];
      // nn= memory->ram[pc];
      memory->read_byte(pc, &nn);
      state->pc_delta= 2;
      //(memory->registers[7])+= 2;
      adr= memory->registers[src];
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t)(tmp_adr + nn);
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 7:
      //@nnRn
      //index dereffered
      pc= memory->registers[7];
      // nn= memory->ram[pc];
      memory->read_byte(pc, &nn);
      state->pc_delta= 2;
      // (memory->registers[7])+= 2;
      adr= memory->registers[src];
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t)(tmp_adr + nn);
      // adr= memory->ram[adr+nn];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
  }

  state->src_val= val;
  state->src_adr= adr;
  printf("src_reg= %d, %d, %d\n", src, adr, val);
  ///////////////////////////////////////////////////////////

  val=0;
  pc=0;
  adr=0;
  nn=0;//index



  // dst
  // it is like src, but dst
  switch (entry->mode2)
  {
    case 0:
      // Rn
      // Register
      val= memory->registers[dst];
      break;
    case 1:
      // @Rn
      // Register deferred
      adr= memory->registers[dst];
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
    //   printf("dst_reg= %d, %d, %d\n", dst, adr, val);
      break;
    case 2:
      // (@Rn)+
      //  Auto-increment
      adr= memory->registers[dst];
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      state->dst_delta= 1;
      if (dst==6) state->dst_delta= 2;
      if (dst==7) state->dst_delta= 2;
      //(memory->registers[n_reg])+= 2;
      //or +=1 for byte instruction
      //sp+=2
      //pc+=2;
      break;
    case 3:
      //@(Rn)+
      // Auto-increment deferred
      adr= memory->registers[dst];
      state->dst_delta= 2;
      //(memory->registers[dst])+= 2;
      //allways +=2
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 4:
      //-(Rn)
      // Auto-decrement
      state->dst_delta= -1;
      if (dst==6) state->dst_delta= -2;
      if (dst==7) state->dst_delta= -2;
      //(memory->registers[dst])-= 2;
      //or 1, as earlier discribed
      adr= memory->registers[dst] -2;
      //there is (-2) because of reg[dst] no changes
      // val= memory->ram[adr];
      // CHECK ERROR !!
      memory->read_byte(adr, &val);
      break;
    case 5:
      // @-(Rn)
      // Auto-decrement deferred
      state->src_delta= -2;
      // (memory->registers[dst])-= 2;
      adr= memory->registers[dst] -2;
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 6:
      //nnRn
      //index
      pc= memory->registers[7];
      pc+= state->pc_delta;
      // becouse of the changes, made when src worked
      // ????
      // nn= memory->ram[pc];
      memory->read_byte(pc, &nn);
      state->pc_delta= 2;
      //(memory->registers[7])+= 2;
      adr= memory->registers[dst];
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) (tmp_adr + nn);
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
    case 7:
      //@nnRn
      //index dereffered
      pc= memory->registers[7];
      pc+= state->pc_delta;
      // becouse of the changes, made when src worked
      // ????
      // nn= memory->ram[pc];
      memory->read_byte(pc, &nn);
      state->pc_delta= 2;
      // (memory->registers[7])+= 2;
      adr= memory->registers[dst];
      // adr= memory->ram[adr];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) (tmp_adr + nn);
      // adr= memory->ram[adr+nn];
      memory->read_byte(adr, &tmp_adr);
      adr= (int16_t) tmp_adr;
      // val= memory->ram[adr];
      memory->read_byte(adr, &val);
      break;
  }

  state->dst_val= val;
  state->dst_adr= adr;
  printf("dst_reg= %d, %d, %d\n", dst, adr, val);

  return 0;
}
int fetch_conditional_branch(Interstate* state, Memory_unit* memory, \
    Instruction_entry* entry)
{
    state->pc= memory->registers[7];
    state->statword= memory->statword;
    state->pc_delta= (int16_t)entry->offset;

    return 0;
}
