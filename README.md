# `clox`

A Lox implementation written in C. This book follows the "Crafting Interpreters" book
and it aims to complete the baseline implementation reference for the C compiler and 
pass all tests from the [Lox test suite](https://github.com/munificent/craftinginterpreters/tree/master/test).

## Structure

This project contains 3 fundamental steps to compiling and running Lox projects:

- A Front End Compiler that reads Lox and outputs IR
- A portable Intermediate Representation called Bytecode
- A Virtual Machine for executing the IR generated

## Additional Challenges

### Bytecode
- [ ] Replace encoding of line information to something akin to run-length encoding
- [ ] Implement a `OP_CONSTANT_LONG` instruction to store 24-bit numbers.
- [ ] Hardcore mode: Replace `stdlib.h` heap allocator methods.

### VM
- [ ] Remove `OP_NEGATE` and use `OP_SUBTRACT`
- [ ] Dynamically grow the stack as needed to avoid Stack overflow.
