# Hello World

Now that you've installed a C++ compiler, its time to write your first C++ program. It is tradition when learning a new programming language to write a program that prints "Hello, world!" to the screen and we'll be doing the same.

```admonish info
"Hello, world!" was first introduced as a teaching mechanism for people learning a new programming language in Brian Kernighan's 1972 "A Tutorial Introduction to the Language B".
```

## Creating a Project Directory

First, you'll create a new directory to store you C++ code. It is a good idea to create a 'projects' or 'dev' directory within you home or user directory in order to store any project you might develop for this book an beyond. Open a terminal and run the following commands.

Linux, MacOS or PowerShell on Windows:

```sh
$ mkdir ~/projects
$ cd ~/projects
$ mkdir hello_world
$ cd hello_world
```

CMD on Windows:

```cmd
> mkdir "%userprofile%\projects"
> cd "%userprofile%\projects"
> mkdir hello_world
> cd hello_world
```

## Writing and Running a C++ Program

Within this new 'hello_world' directory we will create a new file called *main.cxx*. This is called a C++ source file. A C++ program is then built from one or more of these files. We use the file extension `*.cxx` to denote that this file contains C++ source code. If a filename contains multiple words the convention is to separate the words with an underscore eg. *hello_world.cxx* over *helloworld.cxx*. Now open the file you have just created and copy the code from [Listing 1-1](#listing1-1) into the file.

<span id="listing1-1" class="caption">Listing 1-1: Program the prints `Hello, world!`</span>

```cpp
{{#include examples/hello_world/main.cxx}}
```

```admonish info
C++ source files can have various different extensions such as `*.cpp`, or `*.c++` however, for this book the `*.cxx` style will be used. Is also good practice to use the same extension type across a project so no matter which one you use, just be consistent.
```

Save the file and return to your terminal open to the *~/projects/hello_world* directory and run the following command.

On Linux or MacOS

```sh
$ g++ -std=c++20 -o hello_world main.cxx
$ ./hello_world
Hello, world!
```

On Windows

```console
:: Must be done in a 'Developer Command Prompt for VS ...' 
> cl /std:c++20 /EHsc /Fe: hello_world.exe main.cxx
> .\hello_world.exe
Hello, world!
```

If you see "Hello, world!" printed on your terminal, congratulations, you've officially written your first C++ program!

```admonish note
- You can swap the `g++` command with the `clang++` command if you want to use the Clang compiler instead of the GCC compiler.
- The `-std=c++20` (GCC/Clang) and `/std:c++20` flag options specify the compiler to use the C++20 (2020) version of C++. The `-o <name>` is used to specify the name and/or directory for the compiled program.
```

## Anatomy of a C++ Program

Let's go into some more detail on the structure of our "Hello, world!" program. The first component to cover is:

```cpp
{{#include examples/hello_world/main.cxx:3}}
{{#include examples/hello_world/main.cxx:4}}

{{#include examples/hello_world/main.cxx:7}}
```

This declares a function called `main`. The `main` function is known as the program's entry point, meaning `main` is the very first function that runs in every executable C++ program. This declaration of `main` takes no parameters and returns an integer (`int`). If there were parameters they would be declared within the parenthesis `()`. The body of the function is wrapped in curly braces `{}`.

The body of the function contains the following two lines:

```cpp
{{#include examples/hello_world/main.cxx:5:6}}
```

The second line returns a status code from `main` to the operating system (OS) indicating whether the program run successfully or not. A status code of `0` indicates the program ran was successfully with any other value indicating the program failed.

The first line is where the action occurs! We start by accessing the symbol `cout` from the namespace `std` "(usually pronounced *stood*) using the namespace resolution operator `::`. `cout` is a global character output stream that is linked to `stdout` ie. your terminal's output (you'll learn more about streams and IO in [Chapter 10](./../io/io.md)).

We can push characters through the stream using the `<<` operator where the left argument must be an output stream and the right argument is a series of characters, numbers or a string. In this case we are pushing the string literal `"Hello, world!\n"` through the stream. We use the `\n` character to specify a newline to be printed after our string has been written to the terminal.

You'll notice that we end the line with a semicolon `;`. Semicolon's are used to indicate the end of an expression.

```admonish note
The operator `<<` has been overloaded for use with `cout` (and other output streams), as such it is only defined to work with types that ship with C++. You would need to provide you own definition for custom types which will be described in more detail during [Chapter 7](./../custom-types/custom-types.md)
```

You'll also notice at the top of the file the following line:

```cpp
{{#include examples/hello_world/main.cxx:1}}
```

This is a preprocessor instruction, more specifically it is an instruction use to import the 'iostream' library into our program. This is where the symbol for the `cout` output stream comes from. We include libraries by utilising the preprocessor directive `#include` which basically copies and pastes the contents of the file indicating within the `<>` symbols into our program, which in this case is the file 'iostream'. Assume this file's location (and the location of any others used in the same manner) is known to your compiler unless specified otherwise. Files imported using `#include` are known as headers.

## Compiling and Running Are Separate Steps

You may notice that it took two separate steps in order to run our program. This is because C++ is a compiled language, meaning that our source code is transformed into something else. In the case of C++, the compiler will generate binary machine code for our target platform; which in this case is our own device before running. This means the generate (machine) code is specific to the target and you cannot transferred and run on a different computer if its architecture is different. This allows the compiler to optimise your code for the target platform but does require the additional step.

This is in contrast to interpreted languages; like Python, Ruby, JavaScript etc., which will perform the conversion while the program is running but this in turn requires another program; the interpreter, to run alongside yours, taking up extra resources but it usually means your programs are more portable as they can run on anywhere the interpreter can. These are some trade-offs made when designing or using a language.

For simple programs, directly using a C++ compiler (like `g++`) is fine, but as your project grows you'll want to manage all the options and make it easy to share your code. Next, we'll introduce you to the CMake tool, which will help you write manage much larger projects.
