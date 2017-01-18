/*
	Class o save data about every decoded instruction
*/

class instructions{
	struct instr{
		char[64] description;
		int8_t opcode;
		int8_t offset;
		int8_t mode1;
		int8_t mode2;
		int8_t src;
		int8_t dst;
	};

public:
	instr* decode;
	instructions();
	~instructions();

	init_all();

private:
	init_add();
	init_sub();
}
