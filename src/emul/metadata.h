#include <cstdint>

struct Metadata{
	uint16_t prog_start;
	uint16_t prog_len;
	uint16_t rom_len;
	uint16_t stack_root;
	uint16_t vram_map;
	uint16_t vram_len;
	uint16_t io_map;
	uint16_t io_len;
};
