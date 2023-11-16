# MacOS

To install GCC and Clang on MacOS we will need Apple's developer toolchain called Xcode and a package manager for MacOS called Homebrew.

## Installation

To build almost anything on MacOS we need the Xcode developer suite. This is a set of libraries, environment configurations and binaries used at the core of all Apple software products. The full installation can be found on [Apple's developer](https://developer.apple.com/download/) page (requires a login) but this is an extremely large package requiring ~40Gb of disk space. Luckily there is a much smaller CLI package that just installs the necessary tooling for working with software from the terminal. One of these tools is the Clang compiler. To install GCC you will need the [Homebrew](https://brew.sh), a package manager which will by default install the latest stable version of the GCC formula. If you need a different version you can can check the [GCC formula page](https://formulae.brew.sh/formula/gcc#default) for available versions. To install these packages, open the 'Terminal' app and run:

```sh
# Install Xcode CLI tools
$ xcode-select --install

# Install Homebrew
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Add `brew` command to your PATH
$ (echo; echo 'eval "$(${HOMEBREW_PREFIX}/bin/brew shellenv)"') >> ${shell_profile}

# Install GCC
$ brew install gcc cmake
```

## Verifying Installation

To verify the install worked for either GCC or Clang we can run the compiler programs with the version flag and ensure the install has been successful.

```sh
# Verify GCC
$ g++-13 --version
g++-13 (Homebrew GCC 13.2.0) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Verify Clang
$ clang++ --version
Apple clang version 15.0.0 (clang-1500.0.40.1)
Target: x86_64-apple-darwin22.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

```admonish note
- The name of GNU's compiler toolchain is 'GCC' aka GNU Compiler Collection. This is in contrast to the CLI tool called `gcc` which stands for GNU C Compiler.
- The C++ compiler from GCC is called `g++`. Make sure to use this command when compile C++ code.
- You must specify the versioned `g++` command in order to use the Homebrew version of the command. You can find the default version installed by running `brew info gcc`. We must do this because the regular `g++` command redirects back to Apple's Clang implementation.
```

## Installing CMake

We will also want a tool to help manage larger projects and allow us to build on different machines from the same source. CMake is one such build tool for C++ projects. It is used to manage different configurations for a projects. You would have already installed CMake when you installed the C++ compilers earlier with Homebrew as we added CMake to the install list. You can verify by running:

```sh
$ cmake --version
cmake version 3.25.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## Installing `vcpkg`

We will also need some way to install external libraries. While many different tools exist the tool `vcpkg` was chosen for this book. `vcpkg` is an open source tool developed by Microsoft used for downloading and managing C++ libraries with CMake. We can install, add it to our `PATH` and validate the install using the following commands:

<!-- markdownlint-disable MD014 -->

```sh
$ cd ~
$ mkdir bin
$ cd bin
$ git clone https://github.com/Microsoft/vcpkg.git
$ ./vcpkg/bootstrap-vcpkg.sh
$ echo '\n# >>> vcpkg >>>\nexport VCPKG_ROOT="$HOME/bin/vcpkg"\nexport PATH="$VCPKG_ROOT:$PATH"\n# >>> vcpkg >>>\n' >> ~/.zshrc
$ source ~/.zshrc
$ vcpkg --version
vcpkg package management program version 2023-10-18-27de5b69dac4b6fe8259d283cd4011e6d20a84ce

See LICENSE.txt for license information.
```

<!-- markdownlint-disable MD014 -->

```admonish note
Any details displayed from verifying a given newly installed tool may differ to what is displayed in this book.
```
