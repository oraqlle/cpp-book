# Hello World

```admonish warning
🚧 Page Under Construction! 🏗️
```

Now that you've installed a C++ compiler, its time to write your first C++ program. It is tradition when learning a new programming language to write a program that prints "Hello, world!" to the screen and we'll be doing the same.

```admonish info
"Hello, world!" was first introduced as a teaching mechanism for people learning a new programming language in Brian Kernighan's 1972 "A Tutorial Introduction to the Language B".
```

## Creating a Project Directory

First, you'll create a new directory to store you C++ code. It is a good idea to create a 'projects' or 'dev' directory within you home or user directory in order to store any project you might develop for this book an beyond. Open a terminal and run the following commands.

<!-- markdownlint-disable MD014 -->

Linux, MacOS or PowerShell on Windows:

```sh
$ mkdir ~/projects
$ cd ~/projects
$ mkdir hello_world
$ cd hello_world
```

CMD on Windows:

```cmd
> mkdir "%USERPROFILE%\projects"
> cd /d "%USERPROFILE%\projects"
> mkdir hello_world
> cd hello_world
```

<!-- markdownlint-disable MD014 -->

## Writing and Running a C++ Program

Within this new 'hello_world' directory we will create a new file called *main.cxx*. This is called a C++ source file. A C++ program is then built from one or more of these files. We use the file extension `*.cxx` to denote that this file contains C++ source code. If a filename contains multiple words the convention is to separate the words with an underscore eg. *hello_world.cxx* over *helloworld.cxx*. Now open the file you have just created and copy the code from [Listing 1-1](#listing1-1) into the file.

```cpp
{{#include examples/hello_world/main.cxx}}
```

<span id="listing1-1" class="caption">Listing 1-1: Program the prints `Hello, world!`</span>

```admonish info
C++ source files can have various different extensions such as `*.cpp`, or `*.c++` however, for this book the `*.cxx` style will be used. Is also good practice to use the same extension type across a project so no matter which one you use, just be consistent.
```

Save the file and return to your terminal open to the *~/projects/hello_world* directory and run the following command.

On Linux or MacOS

```sh
$ g++ -std=c++20 -o main main.cxx
$ ./main
Hello, world!
```

On Windows

```cmd
> cl /std:c++20 main.cxx
> .\main.exe
Hello, world!
```

If you see "Hello, world!" printed on your terminal, congratulations, you've officially written your first C++ program!

```admonish note
- You can swap the `g++` command with the `clang++` command if you want to use the Clang compiler instead of the GCC compiler.
- The `-std=c++20` (GCC/Clang) and `/std:c++20` flag options specify the compiler to use the C++20 (2020) version of C++. The `-o <name>` is used to specify the output directory/name for the compiled program.
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

If you come from a programming background using languages like Python, Ruby or JavaScript you may be wondering why we must perform two steps in order to run our program. This is because C++ is an *ahead-of-time (AOT) compiled language*. When you run software, it must be in a format that the computer understands ie. machine code which is a binary representation of your program as assembly code however, the assembly used by different machines is dependent on the instruction set used by a CPU. This means you need to compile code different for different machines. All programs have to be converted into machine code at some point but when they are depends on the language and platform. Predominately, programs are either compiled or interpreted.

### Interpretation

Languages like Python, Ruby and JavaScript are examples of interpreted languages in which each line of the program is converted or *interpreted* as machine code and executed on-the-fly which the program is running. This means a secondary program; which is the languages interpreter or runtime engine, must be run alongside your program. This has the benefit of allowing the interpreted language to target any host platform the interpreter supports allowing much greater language, distribution, adoption and availability meaning you can run your code the same way regardless of the platform. It also means any resources used in the interpreted program are managed by the interpreter; usually in the form of a Garbage Collector, instead of the programmer. This makes these languages far less prone to resource mismanagement but you lose explicit control of those resources. Interpreted languages are also much slower than compiled languages by virtue of:

1. You must run a secondary program in order to run your own program
2. Garbage collection can interrupt the usual program flow and use up CPU cycles and finally
3. It takes time while your program is actually running for the interpreter convert your source code to machine code.

This makes interpreted languages extremely flexible and able to  and much easier to use but are much bulkier and incur a much greater overhead in order to run. Because of this, many techniques have been utilised by interpreters in order to make interpreted languages faster. This mostly involves introducing some form of compilation into the execution pipeline in order to save time while the program is running. The two main techniques include bytecode compilation and Just-In-Time compilation (JIT).

Bytecode compilation involves compiling source code into a intermediate language often known as bytecode. This acts as a form of machine code but instead of being dependent on the target platform they are used by a bytecode interpreter. This allows you to have the benefit of compiling your code into a simpler format that is more easily interpreted by the interpreter but still have the advantages of an interpreter like automatic resource management. Languages like Java, C# and Kotlin use this model.

The other technique is to implement a JIT compiler. Per the usual means of interpreted languages, the source code is converted to bytecode either AOT (Java etc.) or on the fly (JavaScript etc.). This bytecode is then analysed in order to see if sections would benefit from compilation based on the programs runtime behaviour. This allows your system to dynamic decide which sections of code need to be compiled based on usage.

### Compilation

So why would you ever fully compile? Well, the obvious place is when you make an interpreter. If you want to have an interpreted language that is as fast as possible you should make your interpreter as optimized as possible for any given platform it is running on. You do not want your interpreter to be actively being interpreted itself! Okay so more generally, in situations where you cannot afford to have a secondary program running in order to run your own but surely this is just limited to things like operating systems, compilers, interpreters, infrastructure, video games, drivers, browsers, simulation engines, embedded devices .... that's beginning to become a large list. It turns out that almost every application in software can benefit from reducing the overhead of there software but this has its own set of tradeoffs.

So what makes compiled languages faster?

1. We've already discussed the lower overhead due to not being run on an interpreter.
2. Fully compiled languages is that the compiler knows much more about the target platform and can optimise the generated machine code for that platform. This largely includes leveraging the different specialised instructions available on a given platform for utilising specialised hardware on a CPU.
3. Compiled languages also typically require manually acquiring resources from the OS which in turn makes you; the programmer, responsible for returning them back before the program terminates. This means you only use what you ask for and nothing more.
4. Finally, compiled programs run on the actual hardware of the system meaning there is much less indirection between your code and the systems actual execution of said program.

All of this allows you to write much faster and/or efficient programs (with a little practice).
