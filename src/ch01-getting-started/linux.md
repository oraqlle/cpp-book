# Linux

Installing GCC and Clang on most Linux systems is relatively trivial. Most of the time it
requires just installing the GCC or Clang package and some supporting developer tooling
packages. These are often bundled together to make installation as simple as possible.

## Installing

Depending on your distribution you will use a different package manager and package
upstream repository, therefore some package names might be different than what is listed
below. Consult your platforms docs for the most seamless way to install a C++ compiler if
the below commands fail.

```sh
# Debian, Ubuntu, ElementaryOS, Linux Mint, Pop!_OS (APT)
$ sudo apt install build-essential gdb clang llvm cmake

# RedHat, CentOS, Fedora (DNF)
$ sudo dnf install make automake gcc gcc-c++ kernel-devel gdb clang llvm cmake

# Arch, Manjaro (Pacman)
$ sudo pacman -Sy base-devel gdb clang llvm cmake

# OpenSUSE (Zypper)
$ sudo zypper install -t pattern devel_basis
$ sudo zypper install gdb clang llvm cmake
```

## Verifying Installation

To verify the install worked for either GCC or Clang we can run the compiler programs
with the version flag and ensure the install has been successful. You should get
something like the following output:

```sh
# Verify GCC
$ g++ --version
g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Verify Clang
$ clang++ --version
Ubuntu clang version 14.0.0-1ubuntu1.1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

```admonish note
Any details displayed from verifying a given newly installed tool may differ to what is
displayed in this book.
```

```admonish tip
- The name of GNU's compiler toolchain is 'GCC' aka GNU Compiler Collection. This is in
contrast to the CLI tool called `gcc` which stands for GNU C Compiler.
- The C++ compiler from GCC is called `g++`. Make sure to use this command when compiling
C++ code.
```

## Installing CMake

We will also want a tool to help manage larger projects and allow us to build on
different machines from the same source. CMake is one such build tool for C++ projects.
It is used to manage different configurations for a projects. You would have already
installed CMake when you installed the C++ compilers earlier as we added CMake to the
install list. You can verify by running:

```sh
$ cmake --version
cmake version 3.25.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## Installing vcpkg

We will also need some way to install external libraries. While many different tools
exist the tool vcpkg was chosen for this book. vcpkg is an open source tool developed by
Microsoft used for downloading and managing C++ libraries with CMake. We can install, add
it to our `PATH` and validate the install using the following commands:

```sh
cd ~
mkdir bin
cd bin
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
printf '\n# >>> vcpkg >>>\nexport VCPKG_ROOT="$HOME/bin/vcpkg"\nexport PATH="$VCPKG_ROOT:$PATH"\n# <<< vcpkg <<<\n' >> ~/.bashrc
source ~/.bashrc
```

### Verify vcpkg

```sh
$ vcpkg --version
vcpkg package management program version 2023-10-18-27de5b69dac4b6fe8259d283cd4011e6d20a84ce

See LICENSE.txt for license information.
```

