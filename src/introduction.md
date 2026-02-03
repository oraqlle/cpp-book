# Introduction

Welcome to _The C++ Programming Language_, an introductory book aimed at teaching C++.
C++ is a high-level, general purpose, multi-paradigm programming language aimed at giving
developers precise control over their programs while also being able express many kinds
of abstractions, making the C++ a very powerful language.

## Who/What is C++ for?

C++ was designed for building systems and embedded software in resources constrained
contexts. These are systems that prioritize performance, efficiency and flexibility of
use. C++ allows developers to write fast code that can run or make any kind of system.
If you want the ability to build helpful abstractions but needs to run in a constrained
environment and use resource as effectively as possible C++ will get you there.

## Who is this book for?

This book is generally aimed at people who have programmed before but can be read by
those still early in their learning journey. This is to say you should have an idea about
what a program is and understand common programming concepts. The aim is to make this
book as approachable to as many people as possible. It is possible to read this
book without any prior experience to programming but some concepts may not click as
quickly if you have never programmed before. The purpose of _this_ book is to showcase
how to program using C++ and explore the capabilities the language possesses.

> [!NOTE]
> Not every topic or capability of C++ will be explored in this book. For a comprehensive
> reference on the language explore [cppreference.com].

> [!IMPORTANT]
> *Author's note on C++ Standard Used in this Book*
>
> Currently this book only covers up to the C++17 Standard, even though C++20 (2020) and
> C++23 (2023) have been released since and C++26 (2026) is actively being written, C++17
> is the most supported version by compilers across all new changes. C++20 is nearly
> there with Modules being the main thing that remains to be implemented however, there
> is not much that was introduced C++20 that I plan to cover in the immediate draft and
> thus setting the baseline at C++17 narrows my focus to ensure the foundation is solid.
> Future versions of the book that introduce features from later standards will likely
> result in the suggested baseline being increased to C++20.

## How to Use This Book

In general, this book assumes that you're reading it in sequence from front to back.
Later chapters build on concepts in earlier chapters. Some chapters will explore creating
mini projects that combine concepts from recent chapters to allow you to get some
experience writing complete C++ programs.

> [!TIP]
> You can also search for specific content using the search button in the top left or by
> pressing the <kbd>S</kbd> key.

### Synopsis

1. Getting Started, explains how install the necessary tools for compiling C++ programs
on various platforms like Windows, macOS and Linux. It also goes through writing a
classical `"Hello, world!"` program and will discuss the anatomy of a basic C++ program
and using the CMake build system.
2. Project: Guessing Game, is the first project chapter where you will build a simple
'number guessing game'. This will introduce you to compiling and building a C++ program
and utilising various pieces from C++ at a high level, with later chapters offering more
details.
3. Common Programming Concepts, will cover the basics of the C++ language from variables
and data types to creating functions and controlling the execution flow of a program.
4. Ownership, will cover C++'s ownership model and how you are able share data or even
transfer data ownership.
5. Structured Data will look at how to create custom types using structs.

### Planned

6. In Managing Projects we'll use CMake to compile multiple files, manage dependencies
   and create libraries.
7. Custom Types explores how to create more powerful custom types and how to manage the
   lifetime of data.
8. Error Handling will look at the various ways to verify the correctness of your
   programs at compile time. We will also look at recovering from errors to prevent
   crashes.
9. Templates covers C++'s meta-programming capabilities that allow you to write code once
   and have the compiler generate the implementation for you.
10. In Functional Language Features we will look
11. The IO chapter will look deeper at C++ IO capabilities using streams and explore the
    filesystem library.
12. In the Memory chapter we will explore how to safely (and unsafely ... for science)
    control memory.
13. In Concurrency we will look at how to make our programs run in parallel using a
    myriad of concurrency concepts while ensure safe access and manipulation of shared
    data.
14. The appendices hold extra information may be of use to the reader but do not fit in
    elsewhere in the book.
    - A - Operators
    - B - Value Categories
    - C - Standard Versions
    - D - Recommended Compiler Flags
    - ~~A - Keywords~~
    - ~~D - Compilation Pipeline~~
    - ~~F - Compiler Vendors~~

### Possible Future Chapters

- IO Project, will look at utilising ideas from previous chapters in order to build a
tool that replicates a subset of the functionality of the command line tool `grep`.
- Algorithms, will showcase a few of the common algorithms available in the C++
standard library and they can be used to manipulate any of the standard containers in an
expressive and generic manner. We will also cover the concept of a range and a view and
how they allow use to write composable algorithms.
- Improved IO Project, will look at improving our IO project from Chapter 11 by
utilising the standard algorithms.
- Object Orientated Programming In C++, covers C++ support for write object orientated
code and how it contrasts to the rest of the languages features and object oriented
principles you may be familiar with from other languages.
- Date, Time and Localization, introduces C++ support for working with time and dates
how to change the locale currently being used to express said times and dates.

There is no wrong way to read this book: if you want to skip ahead, go for it! You might
have to jump back to earlier chapters if you experience any confusion. But do whatever
works for you.

An important part of the process of learning any programming language is learning how to
read the error messages the compiler displays, which can be challenging for large
codebases, especially if they are written in C++ (although this is improving). Error
messages no matter the language will offer key insight into where the compilation of a
program failed and in the case of C++, why it failed, which will guide you toward working
code. As such, I'll provide many examples that don't compile along with the error message
the compiler will show you in each situation. Know that if you enter and run a random
example, it may not compile! Make sure you read the surrounding text to see whether the
example you're trying to run is meant to error.

> [!NOTE]
> The error message style and content can be dramatically different given a different
> compiler, compiler version and standard of C++ being used.

## Source Code

The [source code] from which this book is generated
can be found on GitHub. Refer to the supporting docs on the books repo for details on how
to contribute changes, fix typos or create new content for this book.

## External Resources

- [cppreference.com]
- [Compiler Explorer](https://www.godbolt.org/)

---

<div style="font-size: 0.75em;">
  <center>
    <img src="https://img.shields.io/github/v/release/oraqlle/cpp-book?include_prereleases" alt="Current Release">
  </center>
</div>

[cppreference.com]: https://en.cppreference.com/w/
[source code]: https://codeberg.org/oraqlle/cpp-book
