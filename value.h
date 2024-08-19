#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double value_t;

typedef struct {
  int capacity;
  int count;
  value_t *values;
} valuearray_t;

void init_valuearray(valuearray_t *array);
void free_valuearray(valuearray_t *array);
void write_valuearray(valuearray_t *array, value_t value);
void print_value(value_t value);

#endif
