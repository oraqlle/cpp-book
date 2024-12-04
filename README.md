# The C++ Programming Language

This repository contains the source code for "The C++ Programming Language" mdBook. This book is available online or can be built locally and served in your browser. The structure of this book is inspired by the ["Rust Programming Language" Book](https://doc.rust-lang.org/book/).

## Building

To build this book you need [mdBook](https://rust-lang.github.io/mdBook/index.html) a tool for creating books with Markdown. mdBook can be installed using Cargo - Rust's package manager.

```sh
cargo install mdbook --vers "0.4.40" --locked
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

## Code of Conduct, License & Contributing

Refer to the [Code of Conduct](/CODE_OF_CONDUCT.md) and the [License](/LICENSE) for this repository for the expected behavior of contributors and users of the repository. If you have any concerns reach out to me (Tyler Swann) on Teams or follow standard M procedures for issues you are having within the team, branch or MDN. If you wish to contribute, follow the [contributing guide](/CONTRIBUTING.md).

