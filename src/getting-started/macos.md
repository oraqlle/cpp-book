# MacOS

To install GCC and Clang on MacOS we will need Apple's developer toolchain called Xcode and a package manager for MacOS called Homebrew.

## Installation

To build almost anything on MacOS we need the Xcode developer suite. This is a set of libraries, environment configurations and binaries used at the core of all Apple software products. The full installation can be found on [Apple's developer](https://developer.apple.com/download/) page (requires a login) but this is an extremely large package requiring ~40Gb of disk space. Luckily there is a much smaller CLI package that just installs the necessary tooling for working with software from the terminal. One of these tools is the Clang compiler. To install GCC you will need the [Homebrew](https://brew.sh), a package manager which will by default install the latest stable version of the GCC formula. If you need a different version you can can check the [GCC formula page](https://formulae.brew.sh/formula/gcc#default) for available versions. To install these packages, open the 'Terminal' app and run:

```sh
# Install Xcode CLI tools
xcode-select --install

# Install Homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Add `brew` command to your PATH
(echo; echo 'eval "$(${HOMEBREW_PREFIX}/bin/brew shellenv)"') >> ${shell_profile}

# Install GCC
brew install gcc
```

## Verifying Installation

To verify the install worked for either GCC or Clang we can run the compiler programs with the version flag and ensure the install has been successful.

```sh
# Verify GCC
$ g++ --version


# Verify Clang
$ clang --version

```

> Note: The name of GNU's compiler toolchain is 'GCC' while the C++ CLI program for running the C++ compiler/build runner is called `g++`. There exists a CLI program called `gcc` but this is the GNU C Compiler. It has very similar flags and options to `g++` but will fail to link the program due to different linkage rules between C and C++. Just remember when trying to use GCC's C++ compiler to use the `g++` program.
