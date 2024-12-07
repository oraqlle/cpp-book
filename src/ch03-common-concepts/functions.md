# Functions

```admonish warning
🚧 Page Under Construction! 🏗️
```

Functions are fundamental to programming as they allow us to write reusable pieces of
code. We have already been using a function in the examples we have shown so far, that
is the `main()` function which is called by our OS to start the program. We have also
seen a function in `constexpr` example.

Functions are defined by introducing a type (or `auto`) followed by the functions name,
a(n optional) comma-seperated list of parameters surrounded in parenthesis followed by
the body of the function in (curly-)braces. We call a function through its name and
suffixing parenthesis to it.

```cpp
$#include <iostream>
// --snip--

auto another_one() {
    std::cout << "Another one!\n";
}

auto main() -> int {
    std::cout << "Main function!\n";

    another_one();
}
```

```admonish abstract
A function must be declared before it can be used as the compiler has to know the
function symbol (name + parameter and return types) exists however, it does not have to
defined. Note that the return type must be explicitly stated so the return type can be
deduced.

~~~cpp
$#include <iostream>
// --snip--

// declaration
auto another_one() -> void;

auto main() -> int {
    std::cout << "Main function!\n";

    another_one();
}

// definition
auto another_one() -> void {
    std::cout << "Another one!\n";
}
~~~
This mechanism is a result of how C and thus C++ code was and still is compiled and
linked together. It allows you to state a symbol existed in a public header (declare)
but define it later in a source file which was usually built into a binary library with
the linker then connected the calls to the function to the location in the library.
```

## Parameters

Parameters are a way to pass information into functions. The type of each parameter must
be specified, using the same syntax we saw to declare a variable
(without an initializer).

```cpp
$#include <iostream>
// --snip--

auto another_one(int const x, int const y) {
    std::cout << "x: " << x << ", y: " << y << "\n";
}

auto main() -> int {
    std::cout << "Main function!\n";

    another_one(7, 6);
}
```

```admonish tip
As we saw in the `constexpr` example from the previous page, function parameters may also
be declared with `auto` but this can sometimes make hard to know what the type of the
parameter is supposed to be.
```

## Return Values

Functions can also return values using the `return` keyword. The type of the return value
is indicated either before the functions name (C-style) or using a trailing return type,
like we've been using for `main()`. When a function doesn't a value, it's return type is
`void`.

```cpp
$#include <iostream>
$#include <sstream>
$#include <string>
// --snip--

auto another_one(int const x, int const y) -> std::string {
    auto ss = std::stringstring{};
    ss << "x: " << x << ", y: " << y << "\n";
    return ss.str();
}

auto main() -> int {
    std::cout << "Main function!\n";

    std::cout << another_one(7, 6);
}
```

