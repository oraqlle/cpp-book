# Introduction

Welcome to _The C++ Programming Language_, an introductory book aimed at teaching C++.
C++ is a high-level, general purpose, multi-paradigm programming language aimed at giving
developers absolute control over their programs but also the means to design, build and
use any kind of abstraction to make the language more ergonomic and expressible with zero
penalties for what you don't use. This allows for C++ programs to be performant as well
as expressive.

## Who/What is C++ for?

C++ was designed for building systems and embedded software in resources constrained
contexts. These are systems that prioritize performance, efficiency and flexibility of
use allow the developer to write performant code that can run or make any kind of system.
If you want the ability to build helpful abstractions but needs to run in a constrained
environment and make use of every resource as effectively as possible C++ will get you
there.

## Who is this book for?

This book is generally aimed at people who have programmed in at least one other language
but regardless of which (ones). This is to say you should have an idea about what a
program is, common programming concepts, and a rough idea how a computer works but does
not restrict the background in which you learnt these concepts. I aim to make the material
as approachable as possible to anyone from any background. It is possible to read this
book without any prior experience to programming but it is _highly_ recommended you start
at an introduction to programming book or course if you have never programmed before. The
purpose of _this_ book is to showcase how the C++ language works and the various concepts
and capabilities present within the language, as apposed to teaching you about the basics
of programming using C++ as the content medium. C++ is a very **dense** language in its
entirety and and it can be much more difficult to become comfortable programming and
utilising the concepts from this particular book effectively if you do not have a
foundation for programming in general.

## How to Use This Book

In general, this book assumes that you're reading it in sequence from front to back.
Later chapters build on concepts in earlier chapters, and earlier chapters might not delve
into details on a particular topic but will revisit the topic in a later chapter.

You'll find two kinds of chapters in this book: concept chapters and project chapters. In
concept chapters, you'll learn about an aspect or concept from C++. In project chapters,
we'll build small programs together, applying what you've learned so far. Chapters ...
are project chapters; the rest are concept chapters. Add the end of a concept chapter
there will be challenges that you can complete. These are simple quiz like questions that
you can use to query your understanding of the concepts presented in the previous chapter.

> Note: You can also search for specific content using the search button in the top left
> or by pressing the <kbd>S</kbd> key.

### Synopsis

1. Getting Started, explains how install the necessary tools for compiling C++ programs
on various platforms like Windows, macOS and Linux. It also goes through writing a
classical `"Hello, world!"` program and will discuss the anatomy of a basic C++ program
and using the CMake build system.
2. Project: Guessing Game, is the first project chapter where you will build a simple
'number guessing game'. This will introduce you to compiling and building a C++ program
and utilising various pieces from C++ at a high level, with later chapters offering more
details.

### Planned

### Possible Future Chapters

3. Common Programming Concepts, will cover the basics of the C++ language from variables
and data types to creating functions and controlling the execution flow of a program.
4. Ownership, will cover C++ ownership model and how you are able share data or even
transfer data ownership.
5. Containers, will discuss some of the containers available in the standard library and
briefly discuss their capabilities, use cases and tradeoffs.
6. Error Handling, will cover how to report and handle errors in C++ in order to mitigate
the frequency of your programs crashing and keep them running despite failures occurring.
It will also tackle how to perform checks at compile time.
7. Custom Types, contains information for creating your own types and structures within
C++ and how to define operations and methods on your types. We will also begin discussing
how to manage resource lifetimes owned by custom types using RAII as well as explore the
C++ "Zero Cost Abstraction" model.
8. Managing Growing Projects, will discuss how to organise larger codebases using
namespace, headers (modules in C++20) and how to build a project for multiple
architectures.
9. Generic Programming, will introduce the idea of generic programming through the use of
templates and how to allow design reusable code that is type agnostic. We will also
discuss how to constrain generic code to types with specified functionality.
10. IO, is where you learn about IO features available in C++. This covers the concept of
a stream and how it can be used to model files, devices and even strings. You will also
learn about using the formatted strings and output functions available to C++.
11. IO Project, will look at utilising ideas from previous chapters in order to build a
tool that replicates a subset of the functionality of the command line tool `grep`.
12. Algorithms, will showcase a few of the common algorithms available in the C++
standard library and they can be used to manipulate any of the standard containers in an
expressive and generic manner. We will also cover the concept of a range and a view and
how they allow use to write composable algorithms.
13. Improved IO Project, will look at improving our IO project from Chapter 11 by
utilising the standard algorithms.
14. Memory, will discuss C++ memory model and 'abstract machine' that is used to model a
system running C++. You'll be introduced to the concept of the stack and the heap,
difference between them and how to create objects in each. You will learn how to use
C++'s pointer types and how they differ from references. Finally you will be introduced
to dynamic memory objects and how to construct them using both automatic and manual
management techniques.
15. Concurrency, will delve into the concurrency primitives possessed by C++ and how they
can be used to leverage more compute resources and build parallel and concurrent systems.
We will also explore the components and principles for maintaining synchronization
between concurrently executing code.
16. Metaprogramming, will cover metaprogramming techniques available in C++ and how to
utilise them to write code that generate more code for you. We'll cover topics like type
traits and SFINAE as well as various techniques for performing compile computation.
17. Numerics and Mathematical Calculations, will delve into the enormous support for
numerical computation and performing mathematical calculations within your programs.
18. Object Orientated Programming In C++, covers C++ support for write object orientated
code and how it contrasts to the rest of the languages features and object oriented
principles you may be familiar with from other languages.
19. Working with the Filesystem, discusses how you can use C++ to manipulate a systems
filesystem in a cross platform matter.
20. Date, Time and Localization, introduces C++ support for working with time and dates
how to change the locale currently being used to express said times and dates.
21. Regex, will explore how to use Regex in C++ to manipulate and parse strings.
22. Appendices, The appendices hold extra information may be of use to the reader but do
not fit in elsewhere in the book.
    - A - Keywords
    - B - Operators
    - C - Standard Versions
    - D - Compilation Pipeline
    - E - Value Categories
    - F - Compiler Vendors
    - G - Challenge Answers

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

> Note: the error message style and content can be dramatically different given a
> different compiler, compiler version and standard of C++ being used.

## Source Code

The [source code](https://github.com/oraqlle/cpp-book) from which this book is generated
can be found on GitHub. Refer to the supporting docs on the books repo for details on how
to contribute changes, fix typos or create new content for this book.

## External Resources

- [cppreference](https://en.cppreference.com/w/Main_Page)
- [Compiler Explorer](https://www.godbolt.org/)

---

<div style="font-size: 0.75em;">
  <center>
    <img src="https://img.shields.io/github/v/release/oraqlle/cpp-book?include_prereleases" alt="Current Release">
  </center>
</div>
