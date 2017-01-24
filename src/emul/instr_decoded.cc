#include "instr_decoded.h"
#include "instr_implementation.h"
#include <iostream>
#include <string.h>



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

	//  std::printf("decode[%llu]\n", i);
	// std::cout<< "decode[ " << std::hex << i << " ]" <<std::endl;

}

void conditional_branch_init(Instructions* i_table, long long unsigned i)
{
	i_table->decode[i].offset= 	(i & 0x00FF)>>0;// 0 000. 000 0. 1111. 1111
}

void two_operand_descript_1(Instructions* i_table, long long unsigned i)
{
	char buffer[8];
	switch (i_table->decode[i].mode1)
	{
		case 0:
			strcat((i_table->decode[i].description), "R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), " ");
			break;
		case 1:
			strcat((i_table->decode[i].description), "(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 2:
			strcat((i_table->decode[i].description), "(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ")+ ");
			break;
		case 3:
			strcat((i_table->decode[i].description), "@(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ")+ ");
			break;
		case 4:
			strcat((i_table->decode[i].description), "-(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 5:
			strcat((i_table->decode[i].description), "@-(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 6:
			strcat((i_table->decode[i].description), "nn(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 7:
			strcat((i_table->decode[i].description), "@nn(R");
			sprintf(buffer, "%d", (i_table->decode[i].src) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
	}

	switch (i_table->decode[i].mode2)
	{
		case 0:
			strcat((i_table->decode[i].description), "R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), " ");
			break;
		case 1:
			strcat((i_table->decode[i].description), "(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 2:
			strcat((i_table->decode[i].description), "(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ")+ ");
			break;
		case 3:
			strcat((i_table->decode[i].description), "@(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ")+ ");
			break;
		case 4:
			strcat((i_table->decode[i].description), "-(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 5:
			strcat((i_table->decode[i].description), "@-(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 6:
			strcat((i_table->decode[i].description), "nn(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
		case 7:
			strcat((i_table->decode[i].description), "@nn(R");
			sprintf(buffer, "%d", (i_table->decode[i].dst) );
			strcat((i_table->decode[i].description), buffer);
			strcat((i_table->decode[i].description), ") ");
			break;
	}

}

void conditional_branch_descript(Instructions* i_table, long long unsigned i)
{
	char buffer[8];
	sprintf(buffer, "%d", (i_table->decode[i].offset) );
	// NO %X !!!
	strcat((i_table->decode[i].description), "0x");
	strcat((i_table->decode[i].description), buffer);

}

void Instructions::init_all()
{
	// std::printf("\tvoid Instructions::init_all() - OK\n" );
	long long unsigned i=0, j=0;
	uint8_t bw=0, op=0;
	uint16_t op4 =0;
	uint16_t op4_2 =0;
	uint8_t mode_src, mode_dst, res_src, res_dst;

	for (i=0; i<(1<<16); i++)
	{
		op4= i & 0xF000;
		switch (op4)
		{
		// two operand instructions
			case 0x1000:
				std::printf("\tcase 0x1*** - OK\n" );
				j =i;
				for (i =j; i<(j+(1<<12)); i++)
				{
					strcat((decode[i].description), "MOV ");
					two_operand_init_1(this, i);
					decode[i].fetch= fetch_two_operand_1_word;
					decode[i].execute= execute_mov;
					decode[i].writeback= writeback_two_operand_1_word;
					two_operand_descript_1(this, i);
				}
				break;

			case 0x2000:
				std::printf("\tcase 0x2*** - OK\n" );
				j =i;
				for (i =j; i<(j+(1<<12)); i++)
				{
					strcat((decode[i].description), "CMP ");
					two_operand_init_1(this, i);
					decode[i].fetch= fetch_two_operand_1_word;
					decode[i].execute= execute_cmp;
					decode[i].writeback= writeback_two_operand_1_word;
					two_operand_descript_1(this, i);
				}
				break;

			case 0x3000:
				std::printf("\tcase 0x3*** - OK\n" );
				j =i;
				for (i =j; i<(j+(1<<12)); i++)
				{
					strcat((decode[i].description), "BIT ");
					two_operand_init_1(this, i);
					decode[i].fetch= fetch_two_operand_1_word;
					decode[i].execute= execute_bit;
					decode[i].writeback= writeback_two_operand_1_word;
					two_operand_descript_1(this, i);
				}
				break;

			case 0x4000:
				std::printf("\tcase 0x4*** - OK\n" );
				j =i;
				for (i =j; i<(j+(1<<12)); i++)
				{
					strcat((decode[i].description), "BIC ");
					two_operand_init_1(this, i);
					decode[i].fetch= fetch_two_operand_1_word;
					decode[i].execute= execute_bic;
					decode[i].writeback= writeback_two_operand_1_word;
					two_operand_descript_1(this, i);
				}
				break;

			case 0x5000:
					std::printf("\tcase 0x5*** - OK\n" );
					j =i;
					for (i =j; i<(j+(1<<12)); i++)
					{
						strcat((decode[i].description), "BIS ");
						two_operand_init_1(this, i);
						decode[i].fetch= fetch_two_operand_1_word;
						decode[i].execute= execute_bis;
						decode[i].writeback= writeback_two_operand_1_word;
						two_operand_descript_1(this, i);
					}
					break;

			case 0x6000:
					std::printf("\tcase 0x6*** - OK\n" );
					j =i;
					for (i =j; i<(j+(1<<12)); i++)
					{
						strcat((decode[i].description), "ADD ");
						two_operand_init_1(this, i);
						decode[i].fetch= fetch_two_operand_1_word;
						decode[i].execute= execute_add;
						decode[i].writeback= writeback_two_operand_1_word;
						two_operand_descript_1(this, i);
					}
					break;

			case 0xE000:
					std::printf("\tcase 0xE*** - OK\n" );
					j =i;
					for (i =j; i<(j+(1<<12)); i++)
					{
						strcat((decode[i].description), "SUB ");
						two_operand_init_1(this, i);
						decode[i].fetch= fetch_two_operand_1_word;
						decode[i].execute= execute_sub;
						decode[i].writeback= writeback_two_operand_1_word;
						two_operand_descript_1(this, i);
					}
					break;

			// branch conditions
			case 0x0000:
					// std::printf("\tcase 0x0*** - OK\n" );
					op4_2= i & 0x0F00;
					switch (op4_2)
					{
						case 0x0100:
							std::printf("\tcase 0x01** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BR ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_br;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0200:
							std::printf("\tcase 0x02** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BNE ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bne;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0300:
							std::printf("\tcase 0x03** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BEQ ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_beq;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0400:
							std::printf("\tcase 0x04** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BGE ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bge;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0500:
							std::printf("\tcase 0x05** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BLT ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_blt;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0600:
							std::printf("\tcase 0x06** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BGT ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bgt;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0700:
							std::printf("\tcase 0x07** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BLE ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_ble;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;


					}
					break;

			// branch conditions
			case 0x8000:
					// std::printf("\tcase 0x0*** - OK\n" );
					op4_2= i & 0x0F00;
					switch (op4_2)
					{
						case 0x0000:
							std::printf("\tcase 0x80** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BPL ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bpl;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0100:
							std::printf("\tcase 0x81** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BMI ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bmi;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0200:
							std::printf("\tcase 0x82** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BHI ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bhi;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0300:
							std::printf("\tcase 0x83** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BLOS ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_blos;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0400:
							std::printf("\tcase 0x84** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BVC ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bvc;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0500:
							std::printf("\tcase 0x85** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BVS ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bvs;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0600:
							std::printf("\tcase 0x86** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BCC ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bcc;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;

						case 0x0700:
							std::printf("\tcase 0x87** - OK\n" );
							j =i;
							for (i =j; i<(j+(1<<8)); i++)
							{
								strcat((decode[i].description), "BCS ");
								conditional_branch_init(this, i);
								decode[i].fetch= fetch_conditional_branch;
								decode[i].execute= execute_bcs;
								decode[i].writeback= writeback_conditional_branch;
								conditional_branch_descript(this, i);
							}
							//
							break;


					}
					break;


				default:
					// define every unknown code as NOP
					strcat((decode[i].description), "UNDEFINED ASM ");
					decode[i].fetch= fetch_system;
					decode[i].execute= execute_nop;
					decode[i].writeback= writeback_system;
					break;

		}

	}

	// initialise system comands
	//HALT
	i= 0x0000;
	strcat((decode[i].description), "HALT ");
	decode[i].fetch= fetch_system;
	decode[i].execute= execute_halt;
	decode[i].writeback= writeback_system;
	//WAIT
	i= 0x0001;
	strcat((decode[i].description), "WAIT ");
	decode[i].fetch= fetch_system;
	decode[i].execute= execute_wait;
	decode[i].writeback= writeback_system;
	//RESET
	i= 0x0005;
	strcat((decode[i].description), "RESET ");
	decode[i].fetch= fetch_system;
	decode[i].execute= execute_reset;
	decode[i].writeback= writeback_system;
	//NOP
	i= 0x00a0;
	strcat((decode[i].description), "NOP ");
	decode[i].fetch= fetch_system;
	decode[i].execute= execute_nop;
	decode[i].writeback= writeback_system;
}
