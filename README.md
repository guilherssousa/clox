# `clox`

A Lox implementation written in C. This book follows the "Crafting Interpreters" book
and it aims to complete the baseline implementation reference for the C compiler and 
pass all tests from the [Lox test suite](https://github.com/munificent/craftinginterpreters/tree/master/test).

## Additional Challenges

- [ ] Replace encoding of line information to something akin to run-length encoding
- [ ] Implement a `OP_CONSTANT_LONG` instruction to store 24-bit numbers.
- [ ] Hardcore mode: Replace `stdlib.h` heap allocator methods.
