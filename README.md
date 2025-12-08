# The C++ Programming Language

This repository contains the source code for "The C++ Programming Language" mdBook. This book is available online or can be built locally and served in your browser. The structure of this book is inspired by the ["Rust Programming Language" Book](https://doc.rust-lang.org/book/).

## Building

To build this book you need [mdBook](https://rust-lang.github.io/mdBook/index.html) a tool for creating books with Markdown. mdBook can be installed using Cargo - Rust's package manager.

```sh
cargo install mdbook
```

You can build this book you must clone this repository using Git. You can then build it and even serve it to localhost to view in your browser. The serve command will produce a localhost you can view.

```sh
$ git clone https://github.com/oraqlle/cpp-book.git
$ cd cpp-book

# Build ...
$ mdbook build

# ... or serve build and serve locally
$ mdbook serve --open
```

## Contributors and Authors

- Tyler Swann
