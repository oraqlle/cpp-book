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
  - [`Hello, CMake!`](getting-started/hello-cmake.md)

## Sample Project

- [Project: Guessing Game](getting-started/guessing-game.md)

## Common Programming Concepts

- [Common Programming Concepts](common-concepts/common-concepts.md)
  - [Variables and Mutability](common-concepts/vars-mut.md)
  - [Data Types](common-concepts/data-types.md)
  - [Functions](common-concepts/functions.md)
  - [Comments](common-concepts/comments.md)
  - [Control Flow](common-concepts/control-flow.md)

## Ownership

- [Ownership](ownership/ownership.md)
  - [What is ownership?](ownership/what-is-it.md)
  - [References and Moves](ownership/refs-moves.md)
  - [Spans](ownership/spans.md) <!-- and std::string_view -->

## Containers

- [Containers](containers/containers.md)
  - [Storing a Sequence of Items with Vectors](containers/vector.md)
  - [Encoding Text with Strings](containers/string.md)
  - [Storing Ordered Keys with Associated Values with Maps](containers/map.md)
  - [Storing Keys with Associated Values with Unordered Maps](containers/unordered_map.md)
  - [Adapting the Interface of Containers](containers/adaptors.md)
  - [Storing and Manipulating Individual Bits](containers/bitset.md)
  - [Multidimensional Representation of Linear Storage](containers/mdspan.md)

## Error Handling

- [Error Handling](errors/errors.md)
  - [Compile Time Checks](errors/compile-time-checks.md)
  - [Exceptions](errors/exceptions.md)
  - [Stacktraces and Stack Unwinding](errors/stacktraces.md)
  - [Errors as Values](errors/eav.md)
  - [Abnormal Termination](errors/abnormal-termination.md)

## Custom Types

- [Custom Types](custom-types/custom-types.md)
  - [Structuring Related Data](custom-types/structs.md)
  - [Member Access](custom-types/member-access.md)
  - [Creating and Using Methods on Structures](custom-types/methods.md)
  - [Classes](custom-types/classes.md)
  - [Access Modifiers](custom-types/access-modifiers.md)
  - [Constructors, Destructors and RAII](custom-types/raii.md)

## Managing Growing Projects

- [Managing Growing Projects](managing-projects/managing-projects.md)
  - [Namespaces](managing-projects/namespaces.md)
  - [Headers](managing-projects/headers.md)
  - [Modules (C++20)](managing-projects/modules.md)
  - [CMake](managing-projects/cmake.md)

## Generic Programming

- [Generic Programming](generics/generics.md)
  - [Templates](generics/templates.md)
    - [Template Functions](generics/template-func.md)
    - [Template Classes](generics/template-classes.md)
    - [Other Templates](generics/other-templates.md)
  - [Constraining Templates with Concepts](generics/concepts.md)
  - [Parameter Packs](generics/param-packs.md)
  - [Type Erasure](generics/type-erasure.md)
  - [Sum Types](generics/sum-types.md)

## IO

- [IO](io/io.md)
  - [Streams](io/streams.md)
  - [Files](io/files.md)
  - [Formatted String Output (C++20/23)](io/fromatted-strings.md)

## IO Project

- [Project: IO Project](io/io-project.md)

## Algorithms

- [Algorithms](algorithms/algorithms.md)
  - [Iterators](algorithms/iterators.md)
  - [Generic Algorithms](algorithms/generic-algos.md)
  - [Ranges and Constrained Algorithms](algorithms/ranges.md)
  - [Views and Composition](algorithms/views.md)

## Improved IO Project

- [Project: Improving Our IO Project with Algorithms](algorithms/improved-io-project.md)

## Memory

- [Memory](memory/memory.md)
  - [C++ Memory Model](memory/memory-model.md)
  - [Stack vs. Heap](memory/stack-vs-heap.md)
  - [Storage Duration Types](memory/storage-duration-types.md)
  - [Dynamic Resource Allocation](memory/resources.md)
    - [Smart Pointers](memory/smart-pointers.md)
  - [Addresses and Pointers](memory/pointers.md)
    - [Obtaining an Objects Address](memory/addressof.md)
    - [Allocators](memory/allocators.md)
    - [Manual Memory Management](memory/manual-memory.md)

## Concurrency

- [Concurrency](concurrency/concurrency.md)
  - [Running Code Simultaneously](concurrency/basics.md)
  - [Concurrency vs. Parallelism vs. Asynchronous](concurrency/terminology.md)
  - [Parallel Algorithms and Execution Policies](concurrency/par-algos.md)
  - [Threads](concurrency/threads.md)
  - [Atomics](concurrency/atomics.md)
  - [Synchronization Techniques](concurrency/sync-techniques.md)
    - [Semaphores](concurrency/semaphores.md)
    - [Mutexes](concurrency/mutexes.md)
    - [Locks](concurrency/locks.md)
    - [Latches](concurrency/latches.md)
    - [Barriers](concurrency/barriers.md)
    - [Conditional Variables](concurrency/cond-vars.md)
  - [Coroutines](concurrency/coroutines.md)
  - [Async](concurrency/async.md)
  - [SIMD](concurrency/simd.md)
  - [Executors, Senders and Receivers](concurrency/executors-senders-receivers.md)

## Metaprogramming

- [Metaprogramming](meta/meta.md)
  - [Type Traits and SFINAE](meta/type-traits.md)
  - [Compile Time Computation](meta/comptime.md)
  - [Index Sequences](meta/index-seqs.md)

## Numerics and Mathematical Calculations

- [Numerics and Mathematical Calculations](numerics/numerics.md)
  - [Mathematical Functions](numerics/math-func.md)
  - [Mathematical Constants](numerics/numbers.md)
  - [Numerical Limits](numerics/numeric-limits.md)
  - [Complex Number Type](numerics/complex-numbers.md)
  <!-- - [Valarray Type](numerics/.md) -->
  - [Pseudo Random Number Generation](numerics/rand.md)
  - [Floating Point Environment Control](numerics/fp-env.md)

## Object Orientated Programming in C++

- [Object Orientated Programming in C++](oop/oop.md)
  - [Inheritance](oop/inheritance.md)
  - [Abstract Classes](oop/abstract-classes.md)

## Working with the Filesystem

- [Working with the Filesystem](fs/fs.md)
  - [Paths](fs/paths.md)
  - [Directories](fs/directories.md)
  - [Utilities](fs/utils.md)

## Date, Time and Localization

- [Date and Time](time/date-time.md)
  - [Clocks and Time](time/clocks.md)
  - [Timezones](time/timezones.md)
  - [Calenders](time/calendars.md)
  - [Locales](time/locales.md)

## Regex

- [Regex](regex/regex.md)

## Appendix

- [Appendix](appendix/appendicies.md)
  - [A - Keywords](appendix/keywords.md)
  - [B - Operators](appendix/operators.md)
  - [C - Standard Versions](appendix/standard-versions.md)
  - [D - Value Categories](appendix/value-categories.md)
  - [E - Compiler Vendors](appendix/compiler-vendors.md)
  - [F - Compilation Pipeline](appendix/compilation-pipeline.md)
  - [G - The C++ Runtime](appendix/runtime.md)
  - [H - Challenge Answers](appendix/callenge-answers.md)
