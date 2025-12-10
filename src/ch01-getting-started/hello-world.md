# Hello World

Now that you've installed a C++ compiler, its time to write your first C++ program. It is
tradition when learning a new programming language to write a program that prints "Hello,
world!" to the screen and we'll be doing the same.

```admonish info
"Hello, world!" was first introduced as a teaching mechanism for people learning a new
programming language in Brian Kernighan's 1972 "A Tutorial Introduction to the Language
B".
```

## Creating a Project Directory

First, you'll create a new directory to store you C++ code. It is a good idea to create a
'projects' or 'dev' directory within your 'home' or 'user' directory in order to store
any project you might develop for this book and beyond. Open a terminal and run the
following commands.

#### Shell Script

```sh,icon=%gnubash,fp=Shell
mkdir ~/projects
cd ~/projects
mkdir hello_world
cd hello_world
touch main.cxx
```

#### PowerShell

```haskell,icon=,fp=PowerShell
New-Item -Path . -Name "projects" -ItemType "Directory"
Set-Location projects
New-Item -Path . -Name "hello_world" -ItemType "Directory"
Set-Location hello_world
New-Item -Path . -Name "main.cxx" -ItemType "File"
```

#### Command Prompt

```haskell,icon=,fp=CommandPrompt
mkdir "%userprofile%\projects"
cd "%userprofile%\projects"
mkdir hello_world
cd hello_world
echo. > main.cxx
```

## Writing and Running a C++ Program

Within this new 'hello_world' directory we have created a new file called *main.cxx*.
This is called a C++ source file. A C++ program is then built from one or more of these
files. We use the file extension `*.cxx` to denote that this file contains C++ source
code. If a filename contains multiple words the convention is to separate the words with
an underscore eg. *hello_world.cxx* over *helloworld.cxx*. Now open the file you have
just created and copy the code from below into the file.

```cpp,icon=%cplusplus,fp=main.cxx
{{#include examples/hello_world/main.cxx}}
```

```admonish info
C++ source files can have various different extensions such as `*.cpp`, or `*.c++`
however, for this book the `*.cxx` style will be used. Is also good practice to use the 
same extension type across a project so no matter which one you use, just be consistent.
```

Save the file and return to your terminal open to the *~/projects/hello_world* directory
and run the following commands....

.... on Linux or macOS ....

```sh,icon=%gnubash,fp=Shell
$ g++ -std=c++17 -o hello_world main.cxx
$ ./hello_world
Hello, world!
```

.... on Windows ....

```haskell,icon=,fp=CommandPrompt
:: Must be done in a 'Developer Command Prompt for VS ...' 
> cl /std:c++17 /EHsc /Fe: hello_world.exe main.cxx
> .\hello_world.exe
Hello, world!
```

If you see "Hello, world!" printed on your terminal, congratulations, you've officially
written your first C++ program!

```admonish note
- You can swap the `g++` command with the `clang++` command if you want to use the Clang
compiler instead of the GCC compiler.
- The `-std=c++17` (GCC/Clang) and `/std:c++17` flag options specify the compiler to use
the C++17 (2017) version of C++. The `-o <name>` is used to specify the name and/or
directory for the compiled program.
```

## Anatomy of a C++ Program

Let's go into some more detail on the structure of our "Hello, world!" program. The first
component to cover is:

```cpp,icon=%cplusplus,fp=main.cxx
{{#include examples/hello_world/main.cxx:3}}

{{#include examples/hello_world/main.cxx:6}}
```

This declares a function called `main`. The `main` function is known as the program's
entry point, meaning `main` is the very first function that runs in every executable C++
program. This declaration of `main` takes no parameters and returns an integer (`int`).
If there were parameters they would be declared within the parenthesis `()`. The body of
the function is wrapped in curly braces `{}`.

The body of the function contains the following two lines:

```cpp,icon=%cplusplus,fp=main.cxx
{{#include examples/hello_world/main.cxx:4:5}}
```

The second line returns a status code from `main` to the (OS) indicating whether the
program run successfully or not. A status code of `0` indicates the program ran was
successfully with any other value indicating the program failed.

The first line is where the action occurs! We start by accessing the symbol `cout` from
the namespace `std` "(usually pronounced *stood*) using the namespace resolution operator
`::`. `cout` is a global character output stream that is linked to `stdout` ie. your
terminal's output (you'll learn more about streams and IO in later chapters).
.

We can push characters through the stream using the `<<` operator where the left argument
must be an output stream and the right argument is a series of characters, numbers or a
string. In this case we are pushing the string literal `"Hello, world!\n"` through the
stream. We use the `\n` character to specify a newline to be printed after our string
has been written to the terminal.

You'll notice that we end the line with a semicolon `;`. Semicolon's are used to indicate
the end of an expression.

```admonish note
The operator `<<` has been overloaded for use with `cout` (and other output streams), as
such it is only defined to work with C++'s primitive and standard library types. You
would need to provide you own definition for custom types. 
```

You'll also notice at the top of the file the following line:

```cpp,icon=%cplusplus,fp=main.cxx
{{#include examples/hello_world/main.cxx:1}}
```

This is a preprocessor instruction, more specifically it is an instruction use to import
the 'iostream' library into our program. This is where the symbol for the `cout` output
stream comes from. We include libraries by utilising the preprocessor directive
`#include` which basically copies and pastes the contents of the file indicating within
the `<>` symbols into our program, which in this case is the file 'iostream'. Assume this
file's location (and the location of any others used in the same manner) is known to your
compiler unless specified otherwise. Files imported using `#include` are known as
headers.

## Compiler Flags

Compilers have a great many flags that you can provide to turn or off certain features,
compile in a different mode or introduce instrumentation to track various properties
about program or library. Because each compiler has different options and specifies them
in different ways, there is no universal set of flags that you can specify to all
compilers and because of how many options there are, it would be ludicrous to try and
outline them all here. However, it is good practice to turn on all the warnings such
that you can identify problematic code and remove it when appropriate.

GCC and Clang have an almost identical set of flags with MSVC being the outlier. The
flags I'd highly recommend specify whenever compiling C++ is as follows for each of the
compilers.

#### GCC and Clang

* `-Wall` - Turn 'all' warnings on
* `-Wextra` - Turn 'extra' warnings on
* `-Werror` - Turn warnings into errors (very harsh)
* `-Wpedantic` - Ensure strict ISO C++ Standard is Followed

```sh,icon=%gnushell,fp=Shell
g++ -std=c++17 -Wall -Wextra -Werror -Wpedantic -o hello_world main.cxx
```

#### MSVC

* `/W4` - Warning Level 4

```haskell,icon=,fp=CommandPrompt
cl /std:c++17 /W4 /EHsc /Fe: hello_world.exe main.cxx
```

## Compiling and Running Are Separate Steps

You may notice that it took two separate steps in order to run our program. This is
because C++ is a compiled language, meaning that our source code is transformed into
something else. In the case of C++, the compiler will generate binary machine code for
our target platform; which in this case is our own device before running. This means the
generate (machine) code is specific to the target and you cannot transferred and run on a
different computer if its architecture is different. This allows the compiler to optimise
your code for the target platform but does require the additional step.

This is in contrast to interpreted languages; like Python, Ruby, JavaScript etc., which
will perform the conversion while the program is running but this in turn requires
another program; the interpreter, to run alongside yours, taking up extra resources but
it usually means your programs are more portable as they can run on anywhere the
interpreter can. These are some trade-offs made when designing or using a language.

For simple programs, directly using a C++ compiler (like `g++`) is fine, but as your
project grows you'll want to manage all the options and make it easy to share your code.
Next, we'll introduce you to the CMake tool, which will help you write manage much larger
projects.

