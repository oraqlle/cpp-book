# Hello World

```admonish warning
🚧 Page Under Construction! 🏗️
```

Now that you've installed a C++ compiler, its time to write your first C++ program. It is tradition when learning a new programming language to write a program that prints "Hello, world!" to the screen and we'll be doing the same.

```info
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
> cl main.cxx
> .\main.exe
Hello, world!
```

If you see "Hello, world!" printed on your terminal, congratulations, you've officially written your first C++ program!

```admonish note
You can swap the `g++` with `clang++` if you want to use the Clang compiler instead of the GCC compiler.
```

## Anatomy of a C++ Program

~
