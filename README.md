# lc2k-compiler
⚙️ Compiler for C to LC2K (Little Computer 2000) assembly

Pay no mind, this is a side project. This README.md is in development as I build.

## Notes:

Development Methodology:

1. Choose a small subset of the source language that we can compile directly to assembly.
2. Write as many test cases as necessary to cover the chosen subset of the language.
3. Write a compiler that accepts an expression (in the chosen subset of the source language) and outputs the equivalent sequence of assembly instructions.
4. Ensure that the compiler is functional, i.e. it passes all the tests that are written beforehand.
5. Refactor the compiler, if necessary, making sure that none of the tests are broken due to incorrect refactoring.
6. Enlarge the subset of the language in a very small step and repeat the cycle by writing more tests and extending the compiler to meet the newly-added requirements.

## Resources:
- https://craftinginterpreters.com
- https://norasandler.com/2017/11/29/Write-a-Compiler.html
- http://scheme2006.cs.uchicago.edu/11-ghuloum.pdf (supports above article)
- https://github.com/rui314/chibicc
- https://llvm.org/docs/tutorial/ (a tad bit overkill)
