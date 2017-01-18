/*
	CPU whole memory: ram, registers, statword
*/
#pragma once

struct Memory_unit{
	int8_t* ram;
	int16_t registers[8];
	int8_t statword;
};
