/*
	Class o save data about every decoded instruction
*/

class instructions{
	struct instruction_entry{
		char[64] description;
		int8_t opcode;
		int8_t offset;
		int8_t mode1;
		int8_t mode2;
		int8_t src;
		int8_t dst;
	};

public:
	instruction_entry* decode;

	instructions();
	~instructions();

	//call every init_ method from below
	init_all();

private:
	init_add();
}
