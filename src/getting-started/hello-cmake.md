# Hello, CMake

CMake is a third-party tool used to configure and build C++ projects. While there are
other tools like CMake for configuring C++ compiler toolchains, CMake is the most
ubiquitous within the C++ community. CMake allows use to define one or more targets that
our project produces. Targets can be an executable, library, documentation or even
testing. This allows a single project to build many different outputs for different
platforms from a single source. Targets can also be consumed by other targets allowing
more modular builds.

## Creating a Project with CMake

To start off, go back to your `projects/` directory and create a new directory called
'hello_cmake'.

```sh
$ mkdir hello_cmake
$ cd hello_cmake
```

Within this directory we will need to create three new files `main.cxx`, `CMakeLists.txt`
and `CMakePresets.json`. For the `main.cxx` file you can copy the below code which is
identical to the one found on the previous page except printing slightly different
content.

```cpp
{{#include examples/hello_cmake/main.cxx}}
```

We will first look at the `CMakeLists.txt` file.

### CMake Configuration Files

A CMake project is defined by a set of 'CMakeLists.txt' files located in the source tree
(directories containing your source code). These describe your projects targets, source
files etc.. For a simple single file project we only need a single 'CMakeLists.txt'
alongside our `main.cxx` source file. Copy the contents from [Listing 1-2](#listing1-2).

<span id="listing1-2" class="caption">Listing 1-2: Basic CMake configuration file.</span>

```cmake
{{#include examples/hello_cmake/CMakeLists.txt}}
```

Let's break down our `CMakeLists.txt` file. First we specify the minimum required version
of CMake this project uses. This helps to ensure that any CMake features used in the
projects configuration are available to end users and collaborators.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:1}}
```

We then define the basic information about our project such as its name, description,
version and what languages it uses.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:3:6}}
```

In order to mark our `main.cxx` as an executable we use the `add_executable()` function
where we specify the executable's name ie. the name of the target created from the
executable as well as the source file used to make the executable.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:8}}
```

Finally, we can add compilation features; such as setting the C++ Standard to use for
building the target, using the `target_compile_features()` function. Here we add the
builtin CMake feature `cxx_std_20` to our executable which ensures it is built using the
2020 C++ Standard.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:9}}
```

```admonish info
See [Appendix D](../appendix/standard-versions.md) for more information on C++ Standards.
```

### CMake Presets

We can also specify presets for CMake that define different configurations by a unique
name. These presets can be used to configure your project to compile on multiple
different platforms as well as set various flags and options depending on how your want
the project to be built. This is better than writing large 'CMakeLists.txt' files with
complicated conditional logic that makes just *writing* the configuration complicated. A
minimalistic `CMakePresets.json` file would look similar to [Listing 1-3](#listing1-3).

<span id="listing1-3" class="caption">Listing 1-3: Minimalistic CMake presets file.</span>

```json
{{#include examples/hello_cmake/CMakePresets.json}}
```

A `CMakePresets.json` file is starts with a key-value pair indicating the version of the
preset engine to use from CMake. We also specify the minimum CMake version required for
this project, similar to the first line [Listing 1-2](#listing1-2).

```json
{{#include examples/hello_cmake/CMakePresets.json:2:7}}
```

We then have a configuration array which stores our presets objects used for configuring
our projects for different targets. All presets must have a unique name used to identify
them.

```json
{{#include examples/hello_cmake/CMakePresets.json:8}}
        // ... preset objects go here
{{#include examples/hello_cmake/CMakePresets.json:13}}
```

In our preset named "default" specify where we want the resulting binary to be put. In
this case we specified it to be placed in the `build/` directory at the root of our
project.

```json
{{#include examples/hello_cmake/CMakePresets.json:9:12}}
```

One final thing to mention is that `CMakePresets.json` files support macro expansions
which allow you to obtain common variables. The syntax for expanding a macro is to use a
dollar sign (`$`) followed by the variables identifier surrounded in braces (`{}`). We
can see one being used in [Listing 1-3](#listing1-3) when we specify where our binary
should be built. We can see that instead of hard coding a path or using relative path we
can leverage CMake knowing where our projects root is (which is where the root
`CMakeLists.txt` file is located) and obtain the root of our source directory using the
`sourceDir` variable, hence its expansion being used on line 11 eg.
`"binaryDir": "${sourceDir}/build"`. Variable names are always in camel case.

More information of CMake's presets can be found on CMake's official documentation
[cmake-presets(7)](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html).

## Building and Running a CMake Project

When building a CMake project we have to perform two steps. The first step is to
configure the project. What this does is generate the build recipe(s) for your project
according to your 'CMakeLists.txt' files. A recipes are the instructions used to
actually compile your project with a single recipe being used to build one or more
targets. CMake then builds one or more of these targets according to a recipe.

For our project we only have a single target which also happens to correspond to our
single preset so we can simply run the following to build our recipe.

```sh
$ cmake --preset=default
-- The CXX compiler identification is GNU 11.4.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user/projects/hello_cmake/build
```

~~~admonish info
If you do not want to use presets you can manually build the project with the following
command.

```sh
$ cmake -S . -B build
```
~~~

We can then build the target using the following command:

```sh
$ cmake --build build
[ 50%] Building CXX object CMakeFiles/hello_cmake.dir/main.cxx.o
[100%] Linking CXX executable hello_cmake
[100%] Built target hello_cmake
```

This will produce a binary called `main` in the `build/` directory on Linux and MacOS and
the `build/Debug/` directory on Windows. We can run our program like normal.

```sh
$ ./build/hello_cmake  # ... or .\build\Debug\hello_cmake.exe on Windows
Hello, CMake!
```

~~~admonish tip
The reason for Windows based builds having an additional intermediate directory `Debug/`
for the output is because the underlying builder(s) used on Windows can be configured to
output both debug and release builds from the same recipe which is controlled with
CMake's `--config=<config>` flag during the build step. You can test creating a 'Release'
build by running the following command which should now produce and executable in the
`build\Release\` directory.

```console
> cmake --build build --config=Release
```
~~~

## Compiling with Flags (Optional)

Often we want to have specific flags set for the compiler(s) we are using but because
each compiler has different flags available it can become difficult to have parity across
compilers. Luckily presets make this much easier. We can create hidden presets that
define a set of compiler flags for each compiler, platform or even just custom
configurations for the same compiler. We can then use the `"inherits"` array in any
preset that we want the flags to apply to by giving it the name of the hidden flag
preset. We can see this in action in [Listing1-4](#listing1-4) which defines a general
setup for Linux, MacOS and Windows with some of the most common flags set which helps to
prevent some of the most common errors when programming. I would recommend using this
`CMakePresets.json` file as a base starting point for all your projects. Each platform as
a preset for a debug build plus a release build as well as x64 and x86 builds for the
Windows platform. [Listing 1-5](#listing1-5) demonstrates the commands needed to
configure, build and run the executable target for ech preset.

```admonish note
These presets are for tailored for a single executable target and may not be robust to
handle exporting libraries.
```

<span id="listing1-4" class="caption">Listing 1-4: Base `CMakePresets.json` for a single cross-platform executable target with compiler flags set.</span>

```json
{{#include examples/guessing_game/CMakePresets.json}}
```

<span id="listing1-5" class="caption">Listing 1-5: Commands for building with [Listing 1-4's](#listing1-4) presets.</span>

```sh
# Linux (release)
$ cmake --preset=linux  # configure
$ cmake --build --preset=linux  # build
$ ./build/linux/release/main  # execute

# Linux (debug)
$ cmake --preset=debug-linux  # configure
$ cmake --build --preset=debug-linux  # build
$ ./build/linux/debug/main  # execute

# --------------------------------------------

# MacOS (release)
$ cmake --preset=macos  # configure
$ cmake --build --preset=macos  # build
$ ./build/macos/release/main  # execute

# MacOS (debug)
$ cmake --preset=debug-macos  # configure
$ cmake --build --preset=debug-macos  # build
$ ./build/macos/debug/main  # execute

# --------------------------------------------

# Windows [x64] (Release)
> cmake --preset=windows  # configure
> cmake --build --preset=windows --config=Release  # build
> .\build\windows\x64\Release\main.exe  # execute

# Windows [x64] (Debug)
> cmake --preset=windows  # configure
> cmake --build --preset=windows --config=Debug  # build
> .\build\windows\x64\Debug\main.exe  # execute

# --------------------------------------------

# Windows [x86] (Release)
> cmake --preset=windows  # configure
> cmake --build --preset=windows --config=Release  # build
> .\build\windows\x86\Release\main.exe  # execute

# Windows [x86] (Debug)
> cmake --preset=windows  # configure
> cmake --build --preset=windows --config=Debug  # build
> .\build\windows\x86\Debug\main.exe  # execute
```

