/*
	Describe interstate of instruction execution between fetch, work and
	writeback
	Asignee: Yaroslav
*/

struct interstate{
	uint8_t opcode;
	uint8_t mode1;
	uint8_t src;
	uint8_t mode2;
	uint8_t dst;
}
