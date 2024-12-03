# Installation

Each platform or Operating System (OS) has a different set of compiler tools so the
following sub-chapters will outline how to get setup on each platform.

## Available C++ Compilers

|              Compiler             |                                                                                 Description                                                                                 | Windows | Linux | MacOS |
|:---------------------------------:|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------:|:-----:|:-----:|
|   GNU Compiler Collection (GCC)   | A collection of compiler technologies for many different languages including C, C++, Objective-C, Ada, D and Go. Part of the GNU project and the default compiler on Linux. |  ✅[^1]  |   ✅   |   ✅   |
|               Clang               |                               A compiler frontend and build runner that is a part of the LLVM Project. Used to compile C, C++ and Objective-C.                              |  ✅[^2]  |   ✅   |   ✅   |
| Microsoft Visual Compilers (MSVC) |                               Microsoft's proprietary compiler toolchain for building C and C++. Usually installed with the Visual Studio IDE.                              |    ✅    |   ❌   |   ❌   |

```admonish info
Note: The use of `$` or `>` as the first character on a line in any code block for a
shell (commands etc.) is used to indicate the prompt with the command following. This is
used to clarify a shell code block that contains commands and the (generally) expected
output. You do not need to copy the `$` or `>` when running commands.
```

- [^1]: via MinGW or Cygwin
- [^2]: via Visual Studio, MinGW or Cygwin

