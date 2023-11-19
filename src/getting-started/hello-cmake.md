# Hello, CMake

```admonish warning
🚧 Page Under Construction! 🏗️
```

CMake is a third-party tool used to configure and build C++ projects. While there are other tools like CMake for configuring C++ compiler toolchains, CMake is the most ubiquitous within the C++ community. CMake allows use to define one or more targets that our project produces. Targets can be an executable, library, documentation or even testing. This allows a single project to build many different outputs for different platforms from a single source. Targets can also be consumed by other targets allowing more modular builds.

## Creating a Project with CMake

To start off, go back to your projects directory and create a new directory called 'hello_cmake'.

<!-- markdownlint-disable MD014 -->

Linux, MacOS or PowerShell on Windows:

```sh
$ mkdir hello_cmake
$ cd hello_cmake
```

CMD on Windows:

```cmd
> mkdir hello_cmake
> cd hello_cmake
```

Within this directory we will need to create three new files `main.cxx`, `CMakeLists.txt` and `CMakePresets.json`. You can simply copy the contents of our original main program from the previous page into `main.cxx`. We will first look at the `CMakeLists.txt` file.

### CMake Configuration Files

A CMake project is defined by a set of 'CMakeLists.txt' files located in the source tree (directories containing your source code). These describe your projects targets, source files etc.. For a simple single file project we only need a single 'CMakeLists.txt' alongside our `main.cxx` source file. Copy the contents from [Listing 1-2](#listing1-2).

```cmake
{{#include examples/hello_cmake/CMakeLists.txt}}
```

<span id="listing1-2" class="caption">Listing 1-2: Basic CMake configuration file</span>

Let's break down our `CMakeLists.txt` file. First we specify the minimum required version of CMake this project uses. This helps to ensure that any CMake features used in the projects configuration are available to end users and collaborators.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:1}}
```

We then define the basic information about our project such as its name, description, version and what languages it uses.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:3:6}}
```

In order to mark our `main.cxx` as an executable we use the `add_executable()` function where we specify the executable's name ie. the name of the target created from the executable as well as the source file used to make the executable.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:8}}
```

Finally, we can add compilation features; such as setting the C++ Standard to use for building the target, using the `target_compile_features()` function. Here we add the builtin CMake feature `cxx_std_20` to our executable which ensures it is built using the 2020 C++ Standard.

```cmake
{{#include examples/hello_cmake/CMakeLists.txt:9}}
```

```admonish info
See [Appendix D](../appendix/standard-versions.md) for more information on C++ Standards.
```

### CMake Presets

We can also specify presets for CMake that define different configurations by a unique name. These presets can be used to configure your project to compile on multiple different platforms as well as set various flags and options depending on how your want the project to be built. This is better than writing large 'CMakeLists.txt' files with complicated conditional logic that makes just *writing* the configuration complicated. A minimalistic `CMakePresets.json` file would look similar to [Listing 1-3](#listing1-3).

```json
{{#include examples/hello_cmake/CMakePresets.json}}
```

<span id="listing1-3" class="caption">Listing 1-3: Minimalistic CMake presets file</span>

A `CMakePresets.json` file is starts with a key-value pair indicating the version of the preset engine to use from CMake. We also specify the minimum CMake version required for this project, similar to the first line [Listing 1-2](#listing1-2).

```json
{{#include examples/hello_cmake/CMakePresets.json:2:7}}
```

We then have a configuration array which stores our presets objects used for configuring our projects for different targets. All presets must have a unique name used to identify them.

```json
{{#include examples/hello_cmake/CMakePresets.json:8}}
        // ... preset objects go here
{{#include examples/hello_cmake/CMakePresets.json:13}}
```

In our preset named "default" specify where we want the resulting binary to be put. In this case we specified it to be placed in the `build/` directory at the root of our project.

```json
{{#include examples/hello_cmake/CMakePresets.json:9:12}}
```

One final thing to mention is that `CMakePresets.json` files support macro expansions which allow you to obtain common variables. The syntax for expanding a macro is to use a dollar sign (`$`) followed by the variables identifier surrounded in braces (`{}`). We can see one being used in [Listing 1-3](#listing1-3) when we specify where our binary should be built. We can see that instead of hard coding a path or using relative path we can leverage CMake knowing where our projects root is (which is where the root `CMakeLists.txt` file is located) and obtain the root of our source directory using the `sourceDir` variable, hence its expansion being used on line 11 eg. `"binaryDir": "${sourceDir}/build"`. Variable names are always in camel case.

More information of CMake's presets can be found on CMake's official documentation [cmake-presets(7)](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html).

## Building and Running a CMake Project

~

<!-- markdownlint-disable MD014 -->
