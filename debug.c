#include <stdio.h>

#include "debug.h"

void disassemble_chunk(chunk_t *chunk, const char *name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassemble_instruction(chunk, offset);
  }
}

static int simple_instruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

/* Read the instruction opcode and print it, also return the next instruction
 * offset */
int disassemble_instruction(chunk_t *chunk, int offset) {
  printf("%04d ",
         offset); /* Permits a hexdump-like view of the instruction addresses */

  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
  case OP_RETURN:
    return simple_instruction("OP_RETURN", offset);
  default:
    printf("Unknown opcode %d\n", instruction);
    return offset + 1;
  }
}
