# Summary

[The C++ Programming Language](home.md)
[Introduction](introduction.md)

## Getting Started

- [Getting Started](getting-started/getting-started.md)
  - [Installation](getting-started/installation.md)
    - [Linux](getting-started/linux.md)
    - [Windows](getting-started/windows.md)
    - [MacOS](getting-started/macos.md)
  - [`Hello, World!`](getting-started/hello-world.md)
  - [`Hello, CMake!`]()

## Sample Project

- [Project: Guessing Game](getting-started/guessing-game.md)

<!-- ## A Tour of C++

- [A Tour of C++]()
  - [GCC and CMake]()
  - [Functions and Variables]() -->

## Data and Types

- [Data and Types]()
  - [Data Types]()
  - [Variables]()
  - [Mutability]()
  - [The Type System]()
    - [Value Categories]()
    - [Copies, Moves and Ownership]()
    - [Type Deduction]()  <!-- `auto` -->
    - [Storage Types and Durations]()  <!-- `static` etc. & static vs. thread vs. automatic vs. dynamic -->
    - [Type Aliasing]()
  - [C++ vs C]()  <!-- Talk about mangling and linkage -->

## Expressions and Statements

- [Expressions and Statements]()
  - [Precedence and Associativity]()
  - [Blocks]()
  - [Operators]()
  - [Equality, Ordering and Logical Operators]()
    - [Equality and Ordering]()
    - [Three Way Comparisons]()
    - [Logical Operators]()
  - [Functions]()  <!-- overloading, qualifiers -->
  - [Control Flow]()
    - [Conditional Statements]()
    - [Loops]()
      - [While Loop]()
      - [Do-While Loop]()
      - [Range-For Loop]()
      - [Index-For Loop]()
  - [Lambdas]()
  - [Compile Time Expressions]()

## Memory

- [Memory]()
  - [Pointer Types]()
    - [Unique Pointers]()
    - [Shared Pointers]()
    - [Raw Pointers]()
  - [References]()
  - [Slices]()
  - [Strings]()
    - [String Literals]()
    - [Character Slices]()
    - [String Views]()
    - [Strings]()
    - [Character Types for Strings and UTF-8]()
  - [Arrays, Vectors and Spans]()
    - [Arrays]()
    - [Vectors]()
    - [Spans]()
  - [Manual Dynamic Memory Allocations]()
    - [New and Delete]()
    - [Allocators]()
    - [C Based Memory Allocations]()

## Error Handling

- [Error Handling]()
  - [Exceptions]()
  - [Optional and Expected]()
  - [Stacktraces]()
  - [Early Termination]()  <!-- `std::exit` etc. -->

## Headers, Namespaces, Modules and Projects

- [Headers, Namespaces, Modules and Projects]()
  - [Headers]()
  - [Namespaces]()
  - [Modules]()
  - [CMake]()

## Utility Types and Functions

- [Utility Types and Functions]()
  - [Utility Types]()
    - [Fixed Width Integers]()
    - [Pair]()
    - [Tuple]()
    - [Variant]()
    - [Any]()
    - [Integer Sequences]()
    - [Function Objects]()
    - [Function Binding]()
  - [Swaps and Exchanges]()
  - [Type Functions]()
    - [Perfect Forwarding]()
    - [Type and Value Declarations]()  <!-- `decltype()` and `std::declval<T>()` -->
    - [Misc.]()  <!-- `as_const()`, `to_underlying()` and `move_if_noexcept` -->
  - [Apply and Invoke]()
  - [Source Location]()
  - [Hashing]()
  - [Character and String Conversions]()
  - [Formatting Strings]()
  - [Bit Manipulation]()

## IO

- [IO]()
  - [Streams]()
    - [Standard IO Streams]()
    - [Format Specifiers]()
    - [String Streams]()
    - [File Streams]()
  - [Synchronized IO]()
  - [C++23 Formatted Output]()
  - [C Formatted Output Function Family]()
    - [Printf]()
    - [Scanf]()

## Structures, Classes and Enumerations

- [Enumerations, Structures, Classes]()
  - [Enumerations]()
  - [Structures]()
  - [Classes]()
    - [Member Access]()
    - [Construstors and Destructors]()
      - [Construstors]()
      - [Destructors]()
      - [Default and Deleted Implementations]()
      - [RAII]()
    - [Members]()
      - [Member Access]()
      - [Fields]()
      - [Methods]()
      - [Static Members]()
      - [Operators Overloading]()
      - [Method Qualifications]()
      - [Friends]()

## Collections

- [Containers]()  <!-- - [Collections]() -->
  - [Sequence Containers]()
    - [Deque]()
    - [List]()
    - [Forward List]()
    - [Initializer List]()
  - [Ordered Containers]()
    - [Set]()
    - [Map]()
    - [Multiset and Multimap]()
  - [Unordered Containers]()
    - [Unordered Set]()
    - [Unordered Map]()
    - [Unordered Multiset and Multimap]()
  - [Flat Containers]()
    - [Flat Set]()
    - [Flat Map]()
    - [Flat Multiset and Multimap]()
  - [Container Adaptors]()
    - [Stack]()
    - [Queue]()
    - [Priority Queue]()
  - [Multidimensional Spans]()
  - [Bitset]()

## Generic Programming

- [Generic Programming]()
  - [Templates]()
    - [Generic Functions]()
    - [Generic Classes]()
    - [Generic Values]()
  - [Type Traits and Template Meta Programming]()
  - [Concepts]()
    - [Constrained Type Deduction]()  <!-- `std::integral auto a` where `std::integral` is a concept -->

## Algorithms, Iterators, Ranges and Views

- [Algorithms, Iterators, Ranges and Views]()
  - [Iterators]()
  - [Algorithms]()
  - [Ranges]()
    - [Range Algorithms]()
    - [Range Composition]()
    - [Constrained Algorithms]()
  - [Views]()

## Concurrency

- [Concurrency]()
  - [Parallel Algorithms and Execution Policies]()
  - [Atomics]()
  - [Threads]()
  - [Synchronization Techniques]()
    - [Mutexes]()
    - [Latches]()
    - [Barriers]()
    - [Semaphores]()
    - [Conditional Variables]()
  - [Coroutines]()
  - [SIMD]()
  - [Executors and Receivers]()
  - [Async]()
    - [Futures]()
    - [Promises]()
    - [Async Calls]()

## Object Orientated Programming in C++

- [Object Orientated Programming in C++]()
  - [Inheritance]()
  - [Abstract Classes]()

## Numerics and Mathematical Calculations

- [Numerics and Mathematical Calculations]()
  - [Mathematical Functions]()
  - [Mathematical Constants]()
  - [Numerical Limits]()
  - [Complex Number Type]()
  - [Valarray Type]()
  - [Pseudo Random Number Generation]()
  - [Floating Point Environment Control]()

## Working with the Filesystem

- [Working with the Filesystem]()
  - [Paths]()
  - [Directories]()
  - [Utilities]()

## Date, Time and Localization

- [Date, Time and Localization]()
  - [Clocks and Time]()
  - [Timezones]()
  - [Calenders]()
  - [Locales]()

## Regex

- [Regex]()

## Appendix

- [Appendix]()
  - [A - Keywords]()
  - [B - Operators]()
  - [C - Standard Versions]()
  - [D - Compiler Vendors]()
  - [E - Challenge Answers]()
