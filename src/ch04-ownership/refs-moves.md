# References and Moves

## Reference Semantics

So how do dynamic objects like `string` interact with C++ copy semantics? Well, they obey
the same rules, the data is copied into a new heap location, creating two distinct
objects.

```cpp
$#include <iostream>
$#include <string>
// --snip--

auto foo(const std::string s) {
    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
}

auto main() -> int {
    const auto s = std::string{"hello"};

    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";

    foo(s);

$    return 0;
// --snip--
}
```

This is fine for primitive values that are small in size eg. `int`, `bool` etc.
which are small but a `string` can get really big and copying it's data every time; when
say pass it to a function, takes \\(O(n)\\) time. What if we could refer to the same data
without copying it? This is where references come into effect. As their name suggests
reference allow us to refer to another object and treat ourselves as said object.
References are declared by suffxing an ampersand (`&`) to a type declaration on a
variable or parameter.

<!-- diagram of s1 and s2 pointing to same data -->

```cpp
$#include <iostream>
$#include <string>
// --snip--

auto foo(const std::string& s) {
    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
}

auto main() -> int {
    const auto s1 = std::string{"hello"};
    const auto& s2 = std::string{"hello"};

    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
    foo(s2);

$    return 0;
// --snip--
}
```

> [!NOTE]
> Binding a referencing to another reference doesn't create a reference to a reference.
> This is because references pass information through themselves thus the new reference
> points the original object.

References have a few special semantics, for one references; once bound, cannot be
rebound and thus will refer to the same object for the references lifetime. References
can also not refer to nothing, they must be bound at construction. This makes references
super effective at sharing data safely however, you do have to be careful as C++ does not
guarantee a reference does not outlive the object it refers to and thus you can have a
*dangling reference* which refers to a non-existent object and is invalid to use.

This is particularly important to consider when returning references from functions as
we as programmers must ensure the object being referred to is not cleaned up when the
function returns.

```cpp

$#include <iostream>
$#include <sstream>
$#include <string>
// --snip--

auto foo(const std::string& s) -> const std::string& {
    auto ss = std::stringstream{};
    ss << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
    return ss.str(); // error: returning reference to temporary
}

auto main() -> int {
    const auto s = std::string{"hello"};

    std::cout << "Address of s: " << static_cast<const void*>(s.data()) << "\n";
    std::cout << foo(s);

$    return 0;
// --snip--
}
```

```sh
cmake -S . -B build --preset=<platform>
cmake --build build
[ 50%] Building CXX object CMakeFiles/main.dir/main.cxx.o
/home/user/projects/ownership/main.cxx: In function ‘const std::string& foo(const std::string&)’:
/home/user/projects/ownership/main.cxx:9:18: error: returning reference to temporary [-Werror=return-local-addr]
    9 |     return ss.str(); // error: returning reference to temporary
      |            ~~~~~~^~
cc1plus: all warnings being treated as errors
gmake[2]: *** [CMakeFiles/main.dir/build.make:76: CMakeFiles/main.dir/main.cxx.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/main.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
```

If you need to return something out of a function and it was allocated in the lifetime of
the function and won't exist beyond the function, the return type should not be a
reference but a plain value.

## Move Semantics

C++ has another method for control data ownership called *move semantics* which allows
you to transfer ownership of data to another object. This will leave the previously
owning object in a *default initialized state* or its empty state. Moves; contrary to the
name, moves don't move data but rather *transfer* ownership of data. To make a object
*movable* we need to turn it into what is called an *x-value expression*  ie. a temporary
value, such that the compiler can correctly resolve the move. This is done with the
`std::move()` function found in the `<utility>` header.

```cpp
$#include <iostream>
$#include <string>
$#include <utility>
// --snip--

constexpr auto str_addr(const std::string& s) -> const void* {
    return static_cast<const void*>(s.data());
}

auto main() -> int {
    auto s1 = std::string{"hello this is a really long string"};
    std::cout << sizeof(s1) << "\n";
    
    std::cout << "String: " << s1 << " | addr: " << str_addr(s1) << "\n";
    const auto s2 = std::move(s1);

    std::cout << "String: " << s1 << " | addr: " << str_addr(s1) << "\n";
    std::cout << "String: " << s2 << " | addr: " << str_addr(s2) << "\n";

$    return 0;
// --snip--
}
```

> [!NOTE]
> We have to make `s1` non-`const` to see the behaviour I specified above because if `s1`
> were `const` deleted the stored data would violate the invariant that `s1` is `const`
> as we would have mutated it thus `const` data will invoke a copy not a *move*.
> 
> This restriction is due to moves not being *destructive* in C++ which would mean `s1`
> would become an invalid object and generate a compiler warning if we accessed it after
> moving from it.

