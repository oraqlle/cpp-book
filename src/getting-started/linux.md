# Linux

Installing GCC and Clang on most Linux systems is relatively trivial. Most of the time it requires just installing the GCC or Clang package and some supporting developer tooling packages. These are often bundled together to make installation as simple as possible.

## Installing

Depending on your platform you will use a different package manager and package upstream repository. These might have slightly different names for packages, especially bundle packages. Consult your platforms docs for the most seamless way to install a C++ compiler if the below commands fail.

```sh
# Debian, Ubuntu, ElementaryOS, Linux Mint, Pop!_OS (APT)
sudo apt install build-essential gdb clang llvm

# RedHat, CentOS, Fedora (DNF)
sudo dnf install make automake gcc gcc-c++ kernel-devel gdb clang llvm 

# Arch, Manjaro (Pacman)
sudo pacman -Sy base-devel gdb clang llvm

# OpenSUSE (Zypper)
sudo zypper install -t pattern devel_basis
sudo zypper install gdb clang llvm
```

## Verifying Installation

To verify the install worked for either GCC or Clang we can run the compiler programs with the version flag and ensure the install has been successful.

```sh
# Verify GCC
$ g++ --version
g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Verify Clang
$ clang --version
Ubuntu clang version 14.0.0-1ubuntu1.1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

> Note: The name of GNU's compiler toolchain is 'GCC' while the C++ CLI program for running the C++ compiler/build runner is called `g++`. There exists a CLI program called `gcc` but this is the GNU C Compiler. It has very similar flags and options to `g++` but will fail to link the program due to different linkage rules between C and C++. Just remember when trying to use GCC's C++ compiler to use the `g++` program.
