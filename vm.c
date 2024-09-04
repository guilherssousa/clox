#include <stdio.h>

#include "chunk.h"
#include "common.h"
#include "compiler.h"
#include "debug.h"
#include "vm.h"

/* The choice to have a static VM instance is a concession for the book, but
 * not necessarily a sound engineering choice for a real language
 * implementation.
 *
 * If you're building a VM that's designed to be embedded in other host
 * applications, it gives the host more flexibility if you do explicitly take a
 * VM pointer and pass it around.
 * */
vm_t vm;

static void reset_stack() { vm.stack_top = vm.stack; }

void init_vm() { reset_stack(); }

void free_vm() {}

void stack_push(value_t value) {
  *vm.stack_top = value;
  vm.stack_top++;
}

value_t stack_pop() {
  vm.stack_top--;
  return *vm.stack_top;
}

static interpret_result_t run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()]);
#define BINARY_OP(op)                                                          \
  do {                                                                         \
    double b = stack_pop();                                                    \
    double a = stack_pop();                                                    \
    stack_push(a op b);                                                        \
  } while (false)

  for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("          ");
    for (value_t *slot = vm.stack; slot < vm.stack_top; slot++) {
      printf("[");
      print_value(*slot);
      printf("]");
    }
    printf("\n");

    disassemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif

    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
    case OP_CONSTANT: {
      value_t constant = READ_CONSTANT();
      stack_push(constant);
      break;
    }
    case OP_ADD:
      BINARY_OP(+);
      break;
    case OP_SUBTRACT:
      BINARY_OP(-);
      break;
    case OP_MULTIPLY:
      BINARY_OP(*);
      break;
    case OP_DIVIDE:
      BINARY_OP(/);
      break;
    case OP_NEGATE:
      stack_push(-stack_pop());
      break;
    case OP_RETURN: {
      print_value(stack_pop());
      printf("\n");

      return INTERPRET_OK;
    }
    }
  }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
};

interpret_result_t interpret(const char *source) {
  compile(source);
  return INTERPRET_OK;
};
