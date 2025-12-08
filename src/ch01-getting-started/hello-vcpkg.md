# Hello, vcpkg

While CMake can be used to build your project and help to customize its configuration for
different platforms and uses, it is not very good at managing packages. For this reason
we will be using another tool built for this purpose called vcpkg. It is an open-source
project developed at Microsoft that interacts directly with CMake.

## Setting Up CMake Project with vcpkg

To get started we are going to create another new directory in our parent directory
`projects/`.

```sh
$ mkdir hello_vcpkg
$ cd hello_vcpkg
```

We can then copy all files from the previous pages project into this new directory, these
are the `main.cxx`, `CMakeLists.txt` and `CMakePresets.json` files. We can then
initialise a new vcpkg project using the command.

```sh
$ vcpkg new --application
```

This will create two new files `vcpkg.json` and `vcpkg-configuration.json`. The
`vcpkg.json` will currently be empty but it is used to specify dependencies. It can also
declare available features for downstream users of your project if it is setup as a
library however, this is not relevant to us right now. The `vcpkg-configuration.json` is
used to specify the source location of packages as well as lock the version of the source
to a particular version to make reproducible builds easier, which is important in
production software however, we can largely ignore that file.

The next thing we'll do is ensure that CMake is aware of vcpkg so the two tools can work
together. CMake supports a notion of a toolchain file which specifies which underlying
tools CMake must use which assist in building projects across different systems and helps
determine how to build the packages your project requests. We can specify the vcpkg
toolchain in our `CMakePresets.json` by adding the file's path to CMake's variable cache.
This can be done by adding the `"cacheVariables` object below the `"binaryDir"` entry in
our `CMakePresets.json` file with an entry in the new object for the variable
`CMAKE_TOOLCHAIN_FILE`. This can be seen in [Listing 1-6](#listing1-6).

<span id="listing1-6" class="caption">Listing 1-6: `CMakePresets.json` with vcpkg toolchain file added to CMake cache.</span>

```json
{{#include examples/hello_vcpkg/CMakePresets.json}}
```

This leverages the `$env{}` macro which obtains environment variables, in this case the
variable `$VCPKG_ROOT` variable which is where our vcpkg install lives.

```admonish warning
Make sure to have a comma at the end of the line for the `"binaryDir"` entry. 
```

## Adding Packages

Let us add a package to our project. For this example we are going to use the fast
formatting and I/O library [`{fmt}`](https://github.com/fmtlib/fmt). To add dependencies
we simply need to add an entry into `vcpkg.json` called `"dependencies"` which is an
array of objects or strings representing our projects dependencies. We can do this with
the following command:

```sh
vcpkg add port fmt
```

We can also more add a minimum version constraint to dependencies by converting the newly
added dependency from string a into an object similar to [Listing 1-7](#listing1-7).

<span id="listing1-7" class="caption">Listing 1-7: `vcpkg.json` specifying `{fmt}` as a dependency with a minimum version constraint.</span>

```json
{{#include examples/hello_vcpkg/vcpkg.json}}
```

The [full reference for `vcpkg.json`](https://learn.microsoft.com/en-us/vcpkg/reference/vcpkg-json)
contains more details related to controlling your projects setup and dependencies.

Next, we need to tell CMake that `{fmt}` exists and we'd like to use it. To do this we
must tell CMake to find the package using the `find_package()` in the projects
`CMakeLists.txt` file.

```haskell
{{#include examples/hello_vcpkg/CMakeLists.txt:1:11}}
```

Because `{fmt}` will be a required package for our project we must tell CMake to fail if
it cannot be found which is why we pass the `REQUIRED` keyword to the function. We also
pass in the `CONFIG` keyword to indicate for CMake to use the packages provided
configuration file which is what allows vcpkg to manipulate how the packages CMake
targets are made. We then must add `{fmt}` (more specifically, a target from `{fmt}`) to
our projects executable target. We can do this with the `target_link_libraries()`
function. This function first takes the name of the target we want to add libraries to,
we then specify the names of the targets we wish to link using, ensuring to specify a
scope keyword eg. one of `PRIVATE`, `PUBLIC` or `INTERFACE`. Linking a library simply
means adding it to another target. In [Listing 1-8](#listing1-8) we use `PRIVATE`
scoping for adding `{fmt}` to our executable because the usage of `{fmt}` is limited to
the internals of our projects resulting binary and will not be exposed.

<span id="listing1-8" class="caption">Listing 1-8: Example executable using `{fmt}`.</span>

```haskell
# ... rest of CMakeLists.txt

{{#include examples/hello_vcpkg/CMakeLists.txt:10:13}}
```

You may also notice we are linking `fmt::fmt` not just `fmt` in the call to
`target_link_libraries()`. This is because the first `fmt` is a namespace for the package
found through `find_package()`. We then access the target named `fmt` and link it to our
executable.

With all that done we can now use `{fmt}` in our `main.cxx` file.
[Listing 1-9](#listing1-9) is an example program that uses `{fmt}` which you can copy
into the projects `main.cxx`.

<span id="listing1-9" class="caption">Listing 1-9: Example executable using `{fmt}`.</span>

```cpp
{{#include examples/hello_vcpkg/main.cxx}}
```

```admonish note
The use of two braces in the format string of `fmt::println()` is so the one pair is
actually printed in th output. Normally braces have a special meaning in `{fmt}` but if
we need a literal `'{'` or `'}'` we use two. 
```

## Building and Running with vcpkg

If we copy over the presets file from the bottom of the previous page, we can build our
smalle package using presets. This is because of the `"vcpkg"` preset which links CMake
to vcpkg together such that CMake can find packages installed with vcpkg.

```sh
$ cmake -S . -B build/<platform> --preset=linux
$ cmake --preset=default
$ cmake --build build/<platform>
$ ./build/<platform>/hello_vcpkg  # ... or .\build\windows-x[86|64]\Debug\hello_vcpkg.exe on Windows
Hello, vcpkg from {fmt}
```

