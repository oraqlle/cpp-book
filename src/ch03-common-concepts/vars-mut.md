# Variables and Mutability

We first saw variables in our mini [guessing game project](/ch02-guessing-game/guessing-game.md#storing-data-with-variables)
where we used them to store the guess of the user and create our PRNG etc.. Let's explore
what happens when we try to modify constant data and when we would want to allow
mutations.

<!--
> [!CAUTION]
> By default, variables are mutable, allowing you to modify them freely. While this
> offers great flexibiliy and ease of programming, it is beneficial to opt-in to
> immutabilty using the `const` keyword which data that does not need to change, cannot
> change; opting to remove the `const` keyword when data needs to be mutable.
-->

Create a new project have done before, with a `main.cxx` and `CMakeLists.txt` and add the
following contents. This will act as out scratchbook project for tinkering with examples.
I won't always go into super detail about what changes will be made between various
topics but most examples will have a full example with some being hidden behind snips
which can be exposed using the 'eye' button in a codeblock.

```haskell,icon=%cmake,fp=CMakeLists.txt
cmake_minimum_required(VERSION 3.22)

project(main
    VERSION 0.1.0
    DESCRIPTION "C++ Book Examples"
    LANGUAGES CXX)

add_executable(main main.cxx)
target_compile_features(main PRIVATE cxx_std_17)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
```

```cpp,icon=%cplusplus,fp=main.cxx
#include <iostream>

auto main() -> int {
    return 0;
}
```

## Declaring Variables and Constants

To start with we will explore how your declare variables and constants and what happens
when you try to change the value for each. Below outlines a program that declares a
constant with the name `x` and assigns it the value `42` and displays the result. Very
straight forward, basically the same as 'Hello, world!'. We then reassign `x` to `43` and
print the result. The question is, would this compile? Let's take a look.

```cpp,icon=%cplusplus,fp=main.cxx
$#include <iostream>
$
auto main() -> int {
    const auto x = 42;
    std::cout << x << "\n";

    x = 43;
    std::cout << x << "\n";
$    
$    return 0;
}
```

 When we try to compile the above we should get an error like so:

```sh,icon=%gnubash,fp=Shell
$ cmake -S . -B build
...
$ cmake --build build
[ 50%] Building CXX object CMakeFiles/main.dir/main.cxx.o
/home/user/projects/common/main.cxx: In function ‘int main()’:
/home/user/projects/common/main.cxx:7:7: error: assignment of read-only variable ‘x’
    7 |     x = 43;
      |     ~~^~~~
gmake[2]: *** [CMakeFiles/main.dir/build.make:76: CMakeFiles/main.dir/main.cxx.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/main.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
```

The answer is a definitive no. Why? Because `x` in this program is a constant meaning its
value does not change over its lifetime. If `x` is meant to change we drop the `const`
keyword, allowing `x` to be mutated and thus making it a *variable*.

```cpp,icon=%cplusplus,fp=main.cxx
$#include <iostream>
$
auto main() -> int {
    auto x = 42;
    std::cout << x << std::endl;

    x = 43;
    std::cout << x << std::endl;
$    
$    return 0;
}
```

```sh,icon=%gnubash,fp=Shell
$ cmake -S . -B build
...
$ cmake --build build
...
$ ./build/main
42
43
```

<!--
## Constant Expressions

C++ allows for us to define constants whose value is computed at compile time using the
`constexpr` keyword. This allows you to define variables that are the result of some
computation but have the value ready at runtime instead of performing the computation
perform during runtime. `constexpr` are naturally immutable.

To actually see this feature in action, we need to look at the assembly generated for
code using `constexpr` and code without. Take below, we see two numbers, one is
is a `constexpr` and is initialized to some expression; even containing a function call,
and another initialized to a simple number but immediately changed to the same expression
value.

```cpp,icon=%cplusplus,fp=main.cxx
#include <iostream>

auto constexpr sum(auto const n) {
    auto acc = 0;
    for (auto i = 0; i < n; ++i) {
        acc += 1;
    }

    return acc;
}

auto main() -> int {
    auto constexpr x = (42 + 7) / sum(23);
    auto y = 6;
    y = (42 + 7) / sum(23);

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    
    return 0;
}
```

This generates the following assembly (at least for GCC-14):

```haskell,icon=,fp=x86_64
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 2
        mov     DWORD PTR [rbp-8], 6
        mov     edi, 23
        call    auto sum<int>(int)
        mov     ecx, eax
        mov     eax, 49
        cdq
        idiv    ecx
        mov     DWORD PTR [rbp-8], eax
        mov     esi, 2
```

The place of interest is the 5th and 6th line and then the lines 8-14. The first set are
the variables `x` and `y` being initialized. Line 6 makes sense because we initialized
the value with a literal `6`, but line 5 shows `2`. Compare this to the lines 8-14 which
show the process of calling the `sum()` function, calculating and moving the result into
registers, a division call (`idiv`) and finally pushing the result onto the variable on
stack frame. That's not even to mention the instructions needed to run `sum()` (take a
look at the link below for the full assembly). The difference is quite distinguishable.

[`constexpr` example](https://www.godbolt.org/z/61hsYb14P)

While the example above is simple (and a little contrived\*), `constexpr` has become
a very powerful feature of C++ and is capable of computing super complex expressions
at compile time, even expression involving objects that typically interact with runtime
only entities like the heap however, we'll learn more about this in future chapters.

> [!IMPORTANT]
> \*This initialization and immediate change is necessary to force the compiler to
> generate the unoptimized assembly I wanted to show off. Compilers have gotten so good
> that regardless of `constexpr` or no `constexpr`, a variable directly initialized to
> this expression will cause the compiler to optimize the whole thing away into the
> result of the expression and directly initialize the variable with that value.
>
> In fact, it completely removes the definition of `sum()` as it is only used in these
> expressions which run at compile time, so there is no need to store the functions code
> in the resulting binary if it is never used again. Setting the second value to a
> temporary value disallows the compiler to make these optimizations.
>
> It's amazing how much heavy lifting compilers are able to do for us.

> [!NOTE]
> It should be noted that `constexpr` only indicates to the compiler that this expression
> could be computable at compile time but makes no guarantee that it will. For that,
> `consteval` was introduced.
-->

## Type Deduction

It is time to address the elephant in the room, `auto`. You may be asking;
* "What is this peculiar keyword and why are we declaring constants and variables with
   it?"
* "I thought C++ was a typed language, where are the types?" etc..

All valid questions and if we are to continue using `auto` we should address what it is
doing. `auto` does *not* introduce dynamically typed variables into C++, the type is
still there it is just *inferred* by the compiler. This is a mechanism called *type
deduction* and it allows for the type of many expressions to be resolved by the compiler
rather than the programmer. This feature was introduced with C++11 allows for simpler
expressions to be written in the language.

Take a look at the example below, both lines declare a variable with one explicitly
stating the type of `x` while the other lets the compiler deduce the type of `y` for you
but with both variables having the type `int`.

```cpp,icon=%cplusplus
int x = 5;
auto y = 6;
```

As discussed in the chapter 02, you can still mark the type of an expression explicit by
making it explicitly known on the right hand side of the equals sign, like we did for
`std::string`.

```cpp,icon%cplusplus
int x = 5;
auto y = int{6};
```

## Storage Duration

The primary goal of variables (and constants) is to store data. Whether that be numbers,
characters, memory address etc.. How long a variable is around for (known as its
lifetime) is determined by where space for the data was made available from and can be
labelled by one of three categories known as "storage durations".

So far we have seen data with *automatic storage duration*, which means the lifetime of
that data is tied directly to the scope it was declared in. Currently we have only been
working in the scope of the `main()` function, thus when we `return` from `main()`, the
variables we have declared will become unavailable.

Soon we will look at data that has *dynamic storage duration*. This is data whose
lifetime is managed manually by the program and thus by the programmer. You must
explicitly request the space for the data and remember to return it once you no longer
require it.

These two storage duration categories are often tied to the notion of the stack and the
free store respectively. Data with automatic storage duration is allocated on the stack
allowing for the usual mechanisms of the stack to handle the allocation and deallocation
of the slots used for the data, and the free store being the region in which dynamic data
is located.

One we haven't looked at yet is *static storage duration*. This is data that is encoded
directly in the binary of a program and thus lives for the entire duration of the
program. To give data this storage duration we declare it with the `static` keyword.
Global variables declared outside of a functions are implicitly `static`.

