# Variables and Mutability

```admonish warning
🚧 Page Under Construction! 🏗️
```

We first saw variables in our mini [guessing game project](../ch02-guessing-game/guessing-game.md#storing-data-with-variables)
where we used them to store the guess of the user and create our PRNG etc.. Let's exlore
what happens when we try to modify constant data and when we would want to allow
mutations.

```admonish danger
By default, variables are mutable, allowing you to modify them freely. While this offers
great flexibiliy and ease of programming, it is beneficial to opt-in to immutabilty using
the `const` keyword which data that does not need to change, cannot change; opting to
remove the `const` keyword when data needs to be mutable.
```

Create a new (or use an existing project) with a `main.cxx` and `CMakeLists.txt` etc.
like we did for our previous programs; or use an existing one, and we'll explore
mutability. Change the name of the target to `main` in the CMakeLists.txt, as I'll be
using this as the target name from (near) all examples from now on in the book.

```haskell
cmake_minimum_required(VERSION 3.22)

project(main
    VERSION 0.1.0
    DESCRIPTION "C++ Book Example"
    LANGUAGES CXX)

add_executable(main main.cxx)
target_compile_features(main PRIVATE cxx_std_20)
```

In your `main.cxx`, write the following program. When we try to compile this we should
get an error like so.

```cpp
#include <iostream>

auto main() -> int {
    auto const x = 42;

    std::cout << x << std::endl;
    x = 43;
    std::cout << x << std::endl;
    
    return 0;
}
```

When we try to compile this we should get an error like so:

```sh
$ cmake -S . -B build --preset=<platform>
$ cmake --build build
[ 50%] Building CXX object CMakeFiles/main.dir/main.cxx.o
/home/tyler/dev/cpp-book_hello_cmake/main.cxx: In function ‘int main()’:
/home/tyler/dev/cpp-book_hello_cmake/main.cxx:7:7: error: assignment of read-only variable ‘x’
    7 |     x = 43;
      |     ~~^~~~
gmake[2]: *** [CMakeFiles/main.dir/build.make:76: CMakeFiles/main.dir/main.cxx.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/main.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
```

It is vital that we catch errors like this are compile time as it prevents us writing bad
and security vulnerable code. Constant data is also easier to reason about as we can
assume that no part of the program will modify this piece of data. The benefits of this
do not emerge properly until we introduce functions and have to share data across the
function boundaries where we expect the function to not mutate data passed to it even
though the surrounding scope might. More on this later.

Even though immutable data is easier to reason about, mutating data is where the fun
parts of computation occur. We can see that by dropping the `const` we can mutate the
variable freely.

```cpp
#include <iostream>

auto main() -> int {
    auto x = 42;

    std::cout << x << std::endl;
    x = 43;
    std::cout << x << std::endl;
    
    return 0;
}
```

With it compiling to...

```sh
$ cmake -S . -B build --preset=<platform>
$ cmake --build build
$ ./build/main
42
43
```

## Constant Expressions

C++ allows for us to define constants whose value is computed at compile time using the
`constexpr` keyword. This allows you to define variables that are the result of some
computation but have the value ready at runtime instead of peforming the computation
perform during runtime. `constexpr` are naturally immutable.

To actually see this feature in action, we need to look at the assembly generated for
code using `constexpr` and code without. Take below, we see two numbers, one is
is a `constexpr` and is initialized to some expression; even containing a function call,
and another initialized to a simple number but immediately changed to the same expression
value.

```cpp
#include <iostream>

auto constexpr sum(auto const n) {
    auto acc {0};
    for (auto i {0}; i < n; ++i) {
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

```asm
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
stack frame. Thats not even to mention the instructions needed to run `sum()` (take a
look at the link below for the full assembly). The difference is quite distinguishable.

[`constexpr` example](https://www.godbolt.org/z/sPq9Khzba)

While the example above is simple (and a little contrived\*), `constexpr` has become
a very powerful feature of C++ and is capable of computing super complex expressions
at compile time, even expression involving objects that typically interact with runtime
only enities like the heap however, we'll learn more about this in future chapters.

```admonish abstract
\*This initialization and immediate change is necessary to force the compiler to generate
the unoptimized assembly I wanted to show off. Compilers have gotten so good that
regardless of `constexpr` or no `constexpr`, a variable directly initialized to this
expression will casue the compiler to optimize the whole thing away into the result
of the expression and directly initialize the variable with that value.

In fact, it completely removes the definition of `sum()` as it is only used in these
expressions which run at compile time, so there is no need to store the functions code
in the resulting binary if it is never used again. Setting the second value to a
temporary value disallows the compiler to make these optimizations.

It's amazing how much heavy lifting compilers are able to do for us.
```

```admonish note
It should be noted that `constexpr` only indicates to the compiler that this expression
could be computable at compile time but makes no guaruntee that it will. For that,
`consteval` was introduced.
```

## Static Variables

~

