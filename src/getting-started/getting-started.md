# Getting Started

To get started with C++ you will need a compiler that can turn your C++ source code into an executable. There are many compilers available regardless of what system your are on and many of the compilers can be found on many different systems. The choice of a compiler is largely dependant on the availability of the compiler and how well it meets your requirements.

```admonish info
For this book, the usage GNU `g++` compiler will be used if demonstrating compiler commands. For most projects, a build system like CMake is used to abstract these differences.
```

## Available C++ Compilers

|              Compiler             |                                                                                 Description                                                                                 | Windows | Linux | MacOS |
|:---------------------------------:|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------:|:-----:|:-----:|
|   GNU Compiler Collection (GCC)   | A collection of compiler technologies for many different languages including C, C++, Objective-C, Ada, D and Go. Part of the GNU project and the default compiler on Linux. |  ✅[^1]  |   ✅   |   ✅   |
|               Clang               |                               A compiler frontend and build runner that is a part of the LLVM Project. Used to compile C, C++ and Objective-C.                              |  ✅[^2]  |   ✅   |   ✅   |
| Microsoft Visual Compilers (MSVC) |                               Microsoft's proprietary compiler toolchain for building C and C++. Usually installed with the Visual Studio IDE.                              |    ✅    |   ❌   |   ❌   |

<!-- ```admonish warning
This table is incomplete.
``` -->

- [^1]: via MinGW or Cygwin
- [^2]: via Visual Studio, MinGW or Cygwin
