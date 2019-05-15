## brainfuck interpreter

---

__brainfuck__ is an esoteric programming language created in 1993 by Urban Müller, and is notable for its extreme minimalism.The language consists of only eight simple commands and an instruction pointer. While it is fully Turing complete, it is not intended for practical use, but to challenge and amuse programmers. Brainfuck simply requires one to break commands into microscopic steps.The language's name is a reference to the slang term brainfuck, which refers to things so complicated or unusual that they exceed the limits of one's understanding. [Wikipedia](https://en.wikipedia.org/wiki/Brainfuck)

---
*This interpreter operates on buffer of size 4096. Change buffer size for programs that require more space to perate on.*

**To compile:** `gcc -Wall -Werror -Wextra brainfuck.c -o bf`

**To run:** `./bf "brainfuck program here`
