# Introduction

Welcome to _The C++ Programming Language_, an introductory book aimed at teaching C++. C++ is a high-level, general purpose, multi-paradigm programming language aimed at giving developers absolute control over their programs but also the means to design, build and use any kind of abstraction to make the language more ergonomic and expressible with zero penalties for what you don't use. This allows for C++ programs to be performant as well as expressive.

## Who/What is C++ for?

C++ was designed for building systems and embedded software in resources constrained contexts. These are systems that prioritize performance, efficiency and flexibility of use allow the developer to write performant code that can run or make any kind of system. If you want the ability to build helpful abstractions but needs to run in a constrained environment and make use of every resource as effectively as possible C++ will get you there.

## Who is this book for?

This book is generally aimed at people who have programmed in at least one other language but regardless of which (ones). This is to say you should have an idea about what a program is, common programming concepts, and a rough idea how a computer works but does not restrict the background in which you learnt these concepts. I aim to make the material as approachable as possible to anyone from any background. It is possible to read this book without any prior experience to programming but it is _highly_ recommended you start at an introduction to programming book or course if you have never programmed before. The purpose of _this_ book is to showcase how the C++ language works and the various concepts and capabilities present within the language, as apposed to teaching you about the basics of programming using C++ as the content medium. C++ is a very **dense** language in its entirety and and it can be much more difficult to become comfortable programming and utilising the concepts from this particular book effectively if you do not have a foundation for programming in general.

## How to Use This Book

In general, this book assumes that you’re reading it in sequence from front to back. Later chapters build on concepts in earlier chapters, and earlier chapters might not delve into details on a particular topic but will revisit the topic in a later chapter.

You’ll find two kinds of chapters in this book: concept chapters and project chapters. In concept chapters, you’ll learn about an aspect or concept from C++. In project chapters, we’ll build small programs together, applying what you’ve learned so far. Chapters ... are project chapters; the rest are concept chapters. Add the end of a concept chapter there will be challenges that you can complete. These are simple quiz like questions that you can use to query your understanding of the concepts presented in the previous chapter.

>Note: You can also search for specific content using the search button in the top left or by pressing the <kbd>S</kbd> key.

### Synopsis

- Chapter 1 - Getting Started, explains how install the necessary tool for compiling C++ programs on the given platform. It also goes through writing a classical `"Hello, world!"` program and even gives a breakdown of the components of a program.
- Chapter 2  - Project: Guessing Game, is the first project chapter where you will build a simple 'number guessing game'. This will introduce you to compiling and building a C++ program and utilising various pieces from C++ at a high level with later chapters offering more detail later.
- Chapter 3 - Data and Types, will cover the C++ type system and how it is used to model data. It will also cover various semantics that arise in different context when using C++. You will also learn a bit about the difference between C++ and its predecessor language C.
- Chapter 4 - Expressions and Statements, covers the most basic constructs you will encounter and use in your C++ programs. These are the expressions and statements used to build and control the execution of your program.
- Chapter 5 - Memory, will discuss C++ memory model and 'abstract machine' that is used to model a system running C++. You will learn how to use C++'s pointer types and create and use blocks of memory. You'll be introduced into the stack and dynamic memory, difference between them and how to create data in each. You will look into reference types and there semantics with C++ and hwo the eliminate common misuses and bugs that pointers introduce. You will discover C++ slice types and how they can be used to store sequences of elements and their relationship to pointers. You will then look at the various string representations in C++ and how they are used to encode data and the consequences of using them. Next you will look into C++ library based sequence containers the the different use cases for each of them and the consequences of their use. Finally you will be introduced to manual memory management that is leveraged under the hood of many of the concepts mentioned earlier in the chapter.
- Chapter 6 - Error Handling, will cover how to handle errors in C++ to mitigate the frequency of crashes and keep your programs running despite failures.
- Chapter 7 - Headers, Namespaces and Modules, will discuss how to organise and utilise external code and how C++ ties everything together.
- Chapter 8 - Utility Types and Functions, will introduce some useful utilities available to C++ programs that make writing code much easier and allow you to properly leverage the type system.
- Chapter 9 - IO, is where you learn about IO features available in C++. This covers the concept of a stream and how it can be used to model files, devices and even strings. You will also learn about using the formatted print family of functions available to C++ and even the C family of formatted printing.
- Chapter 10 - Enumerations, Structures and Classes, contains information for creating your own types and structures within C++. These include enumeration types, basic aggregate structures and classes. We'll discuss how to provide different functionality for your types and how to ensure safe resource management through RAII.
- Chapter 11 - Containers, will discuss some of the available containers in the standard library and briefly discuss their capabilities, use cases and tradeoffs.
- Chapter 12 - Generic Programming, will introduce the idea generic programming through the use of templates and how to allow design reusable code that is type agnostic.
- Chapter 13 - Algorithms, Iterators, Ranges and Views, will showcase a few of the common algorithms available in the C++ standard library and they can be used to manipulate data structures and containers in an expressive manner. We will also cover the concept of a range and a view and how they allow use to write generic code.
- Chapter 14 - Concurrency, will delve into the concurrency primitives possessed by C++ and how they can be used to leverage more compute resources and build realtime systems. We will also explore the components and principles for maintaining synchronization between concurrently executing code.
- Chapter 15 - Object Orientated Programming In C++, covers C++ support for write object orientated code and how it contrasts to the rest of the languages features and object oriented principles you may be familiar with from other languages.
- Chapter 16 - Numerics and Mathematical Calculations, will delve into the enormous support for numerical computation and performing mathematical calculations within your programs.
- Chapter 17 - Working with the Filesystem, discusses how you can use C++ to manipulate a systems filesystem in a cross platform matter (no need to worry about incompatible file separators).
- Chapter 18 - Date, Time and Localization, introduces C++ support for working with time and dates how to change the locale currently being used to express said times and dates.
- Chapter 19 - Regex, will explore how to use Regex in C++ to manipulate and parse strings.
- Chapter 20 - Appendix, The appendices hold extra information may be of use to the reader but do not fit with the book.
  - A - Keywords
  - B - Operators
  - C - Standard Versions
  - D - Compilation Pipeline
  - E - Value Categories
  - F - Compiler Vendors
  - G - Challenge Answers

There is no wrong way to read this book: if you want to skip ahead, go for it! You might have to jump back to earlier chapters if you experience any confusion. But do whatever works for you.

An important part of the process of learning any programming language is learning how to read the error messages the compiler displays, which can be challenging for large codebases, especially if they are written in C++ (although this is improving). Error messages no matter the language will offer key insight into where the compilation of a program failed and in the case of C++, why it failed, which will guide you toward working code. As such, I'll provide many examples that don’t compile along with the error message the compiler will show you in each situation. Know that if you enter and run a random example, it may not compile! Make sure you read the surrounding text to see whether the example you’re trying to run is meant to error.

> Note: the error message style and content can be dramatically different given a different compiler, compiler version and standard of C++ being used.

## Source Code

The [source code](https://github.com/oraqlle/cpp-book) from which this book is generated can be found on GitHub. Refer to the supporting docs on the books repo for details on how to contribute changes, fix typos or create new content for this book.

## External Resources

- [cppreference](https://en.cppreference.com/w/Main_Page)
- [Compiler Explorer](https://www.godbolt.org/)

---

<div style="font-size: 0.75em;">
  <center>
    <img src="https://img.shields.io/github/v/release/oraqlle/cpp-book?include_prereleases" alt="Current Release">
  </center>
</div>
