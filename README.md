# modern-cpp-programming-cookbook

This repository contains source code from the text
_Modern C++ Programming Cookbook_ [[1]](#1).

I have only typed up _some_ examples from the book that seem interesting or useful.

I was figuring out my own "style-guide" as I went, so no there may be little consistency.

### Organization

The repo is organized (mostly) by the chapters in the book. For example, code from the book chapter 4 is in the folder
`ch4`. If necessary, specific examples/implementations are broken out further into relevant subdirectories.

Code is stored in the source folder `src` (possible with subdirectories) with all header/implementation/test files
alongside rather than in separate `include`/`test` directory structures. I settled on using `{file_name}.hpp` for
header files and `{file_name}.cpp` for implementation files. Any tests will be written in a `{file_name}_test.cpp`
file. Not sure if this is good, but that's how I like to do it in python so here we are.

Some examples from the book build on one another.

### Build

All of the examples are compiled using meson/ninja. I'm still testing this out as well.

There should be a simple bash script `build.sh` that compiles the code based on the `meson.build` file.
Steps to compile and run (assuming the main is is `main.cpp`) would be:
- `./build.sh`
- build/main

Warning: I have only tested any of this on a Macbook using the clang compiler
`Apple clang version 13.0.0 (clang-1300.0.27.3)`.

### Testing

Most of the code is "tested" just using the `main.cpp` routine. Some examples _may_ have testing (using catch2)
if I decide it is useful.

### References
<a id="1">[1]</a>
Bancila, Marius.
Modern C++ Programming Cookbook. Second Edition.
Packt Publishing Ltd, 2020.
