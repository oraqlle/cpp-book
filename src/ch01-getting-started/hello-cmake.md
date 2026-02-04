# Hello, CMake

CMake is a third-party tool used to configure and build C++ projects. While there are
other tools like CMake for configuring C++ compiler toolchains, CMake is the most
ubiquitous within the C++ community. CMake allows use to define one or more targets that
our project produces. Targets can be an executable, library, documentation or even
testing. This allows a single project to build many different outputs for different
platforms from a single source. Targets can also be consumed by other targets allowing
more modular builds.

## Adapting our hello_world Project

To start off, go back to your `projects/hello_world` directory and create a new file
`CMakeLists.txt`.

```sh,icon=%gnubash,fp=Shell
cd ~/projects/hello_world
touch CMakeLists.txt
```

```haskell,icon=,fp=PowerShell
Set-Location projects/hello_world
New-Item -Path . -Name "CMakeLists.txt" -ItemType "File"
```

```haskell,icon=,fp=CommandPrompt
cd ~/projects/hello_world
echo. > CMakeLists.txt
```

### CMake Configuration Files

A CMake project is defined by a set of 'CMakeLists.txt' files located in the source tree
(directories containing your source code). These describe your projects targets, source
files etc.. For a simple single file project we only need a single 'CMakeLists.txt'
alongside our `main.cxx` source file. Copy the contents from below.

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include examples/hello_world/CMakeLists.txt}}
```

Let's break down our `CMakeLists.txt` file. First we specify the minimum required version
of CMake this project uses. This helps to ensure that any CMake features used in the
projects configuration are available to end users and collaborators.

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include examples/hello_world/CMakeLists.txt:1}}
```

We then define the basic information about our project such as its name, description,
version and what languages it uses.

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include examples/hello_world/CMakeLists.txt:3:6}}
```

In order to mark our `main.cxx` as an executable we use the `add_executable()` function
where we specify the executable's name ie. the name of the target created from the
executable as well as the source file used to make the executable.

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include examples/hello_world/CMakeLists.txt:8}}
```

Finally, we can add compilation features; such as setting the C++ Standard to use for
building the target, using the `target_compile_features()` function. Here we add the
builtin CMake feature `cxx_std_17` to our executable which ensures it is built using the
2017 C++ Standard.

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include examples/hello_world/CMakeLists.txt:9}}
```

> [!TIP]
> See [Appendix C](/appendix/standard-versions.md) for more information on C++ Standards.

<!--
### CMake Presets

We can also specify presets for CMake that define different configurations by a unique
name. These presets can be used to configure your project to compile on multiple
different platforms as well as set various flags and options depending on how your want
the project to be built. This is better than writing large 'CMakeLists.txt' files with
complicated conditional logic that makes just *writing* the configuration complicated.

More information of CMake's presets can be found on CMake's official documentation
[cmake-presets(7)](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html).
-->

## Building and Running a CMake Project

When building a CMake project we have to perform two steps. The first step is to
configure the project. What this does is generate the build recipe(s) for your project
according to your 'CMakeLists.txt' files. A recipes are the instructions used to
actually compile your project with a single recipe being used to build one or more
targets. CMake then builds one or more of these targets according to a recipe.

For our project we only have a single target which also happens to correspond to our
single preset so we can simply run the following to build our recipe.

```sh
$ cmake -S . -B build
-- The CXX compiler identification is GNU 11.4.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user/projects/hello_world/build
```

We can then build the target using the following command:

```sh
$ cmake --build build
[ 50%] Building CXX object CMakeFiles/hello_world.dir/main.cxx.o
[100%] Linking CXX executable hello_world
[100%] Built target hello_world
```

This will produce a binary called `hello_world` in the `build/` directory on Linux and
macOS and the `build/Debug/` directory on Windows. We can run our program like normal.

```sh
$ ./build/hello_world  # ... or .\build\Debug\hello_world.exe on Windows
Hello, World!
```

> [!TIP]
> The reason for Windows based builds having an additional intermediate directory
> `Debug/` for the output is because the underlying builder(s) used on Windows can be
> configured to output both debug and release builds from the same recipe which is
> controlled with CMake's `--config=<config>` flag during the build step. You can test
> creating a 'Release' build by running the following command which should now produce
> and executable in the `build\Release\` directory.
>
> ```haskell,icon=,fp=CommandPrompt
> cmake --build build --config=Release
> ```

## Adding Compiler Flags to CMake Build

Remember in the previous chapter how I stated that it is good to specify warning flags in
your C++ builds to catch common bugs. We seem to have abandoned them when introducing
CMake, do not fret, we will reinstate them now.

```haskell,icon=%cmake,CMakeLists.txt
{{#include examples/hello_world/CMakeLists2.txt}}
```

Yes, CMake has conditionals and yes they look a little weird but this is greatly the
extent I will be discussing CMake until
[chapter 06](/ch06-larger-projects/larger-projects.md) when we look multi-file project
structures.

