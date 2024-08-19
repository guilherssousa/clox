#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_valuearray(valuearray_t *array) {
  array->count = 0;
  array->capacity = 0;
  array->values = NULL;
}

/* Clear the contents of a Value Array */
void free_valuearray(valuearray_t *array) {
  FREE_ARRAY(value_t, array->values, array->capacity);
  init_valuearray(array);
}

void write_valuearray(valuearray_t *array, value_t value) {
  if (array->capacity < array->count + 1) {
    int old_capacity = array->capacity;
    array->capacity = GROW_CAPACITY(old_capacity);
    array->values =
        GROW_ARRAY(value_t, array->values, old_capacity, array->capacity);
  }

  array->values[array->count] = value;
  array->count++;
}

void print_value(value_t value) { printf("%g", value); }
