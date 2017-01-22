#include "instr_decoded.h"
#include "instr_implementation.h"
#include <iostream>


Instructions::Instructions()
{
	decode = new Instruction_entry[65536];
}

Instructions::~Instructions()
{
	delete[] decode;
}

void two_operand_init_1(Instructions* i_table, long long unsigned i)
{
	// all int8_t
	// Word/Byte(1) opcode(3) mode_src(3) src(3) mode_dst(3) dst(3)
	// b opc src src dst dst
	i_table->decode[i].dst=		(i & 0x0007)>>0;// 0 000. 000 0.00 00.0 111
	i_table->decode[i].mode2=	(i & 0x0038)>>3;// 0 000. 000 0.00 11.1 000
	i_table->decode[i].src=		(i & 0x01c0)>>6;// 0 000. 000 1.11 00.0 000
	i_table->decode[i].mode1=	(i & 0x0e00)>>9;// 0 000. 111 0.00 00.0 000

	// if((i_table->decode[i].mode1 ==0) &&(i_table->decode[i].mode2 ==0)\
	//  && (i_table->decode[i].src ==1))
	//  {
	// 	 std::printf("decode[%llu]= %d\n", i, i_table->decode[i].dst);
	//  }
	//  std::printf("decode[%llu]\n", i);
	// std::cout<< "decode[ " << std::hex << i << " ]" <<std::endl;

}

// // Logical one
//
// void Instructions::init_all()
// {
// 	long long unsigned i;
// 	for (i=0; i<(1<<16); i++)
// 	{
// 		init_add(i);
// 	}
// }

// // Stable one
//
// void Instructions::init_all()
// {
// 	long long unsigned i=0, j =0;
// 	int8_t bw=0, op=0;
// 	int16_t op4 =0;
// 	int8_t mode_src, mode_dst, res_src, res_dst;
//
// 	for (i=0; i<(1<<16); i++)
// 	{
// 		op4= i & 0xF000;
//
// 		if(op4 ==0x1000)
// 		{
// 			j= i;
// 			for (i; i<(1<<12); i++)
// 			{
// 				//
// 				two_operand_init_1(this, i);
//
// 				decode[i].fetch= fetch_two_operand_1_word;
// 				decode[i].execute= execute_mov;
// 				decode[i].writeback= writeback_two_operand_1_word;
//
// 			}
//
// 		}
//
//
// 	}
// }

void Instructions::init_all()
{
	std::printf("\tvoid Instructions::init_all() - OK\n" );
	long long unsigned i=0, j=0;
	int8_t bw=0, op=0;
	int16_t op4 =0;
	int8_t mode_src, mode_dst, res_src, res_dst;

	for (i=0; i<(1<<16); i++)
	{
		op4= i & 0xF000;
		switch (op4)
		{
			case 0x1000:
				std::printf("\tcase 0x1000 - OK\n" );
				j =i;
				for (i =j; i<(j+(1<<12)); i++)
				{
					// std::printf("\t\t inside case 0x1000:\n" );
					// if (i== 0x1042) std::printf("\tdecode[0x1042] - OK\n" );
					two_operand_init_1(this, i);
					decode[i].fetch= fetch_two_operand_1_word;
					decode[i].execute= execute_mov;
					decode[i].writeback= writeback_two_operand_1_word;
				}
				break;

			// case 0x2000:
			// 	for (i; i<(1<<12); i++)
			// 	{
			// 		two_operand_init_1(this, i);
			// 		decode[i].fetch= fetch_two_operand_1_word;
			// 		decode[i].execute= execute_cmp;
			// 		decode[i].writeback= writeback_two_operand_1_word;
			// 	}
			// 	break;

			
		}

	}
}
