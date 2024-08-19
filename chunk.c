#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void init_chunk(chunk_t *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void free_chunk(chunk_t *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
}

void write_chunk(chunk_t *chunk, uint8_t byte) {
  /* Check if Chunk has space for allocating one more Byte */
  if (chunk->capacity < chunk->count + 1) {
    int old_capacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(old_capacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, old_capacity, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;
  chunk->count++;
}
