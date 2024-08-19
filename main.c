#include "chunk.h"
#include "debug.h"

int main(int argc, const char **argv) {
  chunk_t chunk;

  init_chunk(&chunk);
  write_chunk(&chunk, OP_RETURN);

  disassemble_chunk(&chunk, "test chunk");
  free_chunk(&chunk);
}
