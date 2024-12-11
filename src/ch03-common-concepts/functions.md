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
$    return 0;
// --snip--
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
$    return 0;
// --snip--
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
$    return 0;
// --snip--
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
$    return 0;
// --snip--
}
```

## Overloading

In C++ you can overload functions of the same name to have different implementations
as long as the type signature of the function is different. This is because the type
signature is part of the functions symbol and thus functions with the same name but
different parameters (and possibly return type) is an entirely different function.

```cpp
$#include <iomanip>
$#include <iostream>
$#include <sstream>
$#include <string>
// --snip--

auto another_one(int const x, int const y) -> std::string {
$    auto ss = std::stringstream {};
$    ss << "x: " << x << ", y: " << y << "\n";
$    return ss.str();
// --snip--
}

auto another_one(float const x, float const y) -> std::string {
    auto ss = std::stringstream {};
    ss << std::setprecision(4) 
       << "x: "
       << x
       << ", y: "
       << y
       << "\n";

    return ss.str();
}

auto main() -> int {
    std::cout << "Main function!\n";

    std::cout << another_one(7, 6);
    std::cout << another_one(7.456575654f, 6.0f);
$    return 0;
// --snip--
```

This concept also extends to C++ operators, which can also be overloaded to have custom
functionality between custom types. Operators are overloaded using the `operator` keyword
as the function name, suffixed with the operator we wish to overload. Operator overload
functions can only take two parameters except unary operators, which can only take one.

```cpp
#include <iostream>
#include <ostream>
#include <utility>
// --snip--

auto operator<<(std::ostream& os, std::pair<int, int> p) -> std::ostream& {
    auto const [x, y] = p;
    os << "x: " << x << ", y: " << y << "\n";
    return os;
}

auto main() -> int {
    auto const p = std::pair {7, 6};

    std::cout << p << "\n";
    return 0;
// --snip--
}
```

```admonish warning
There are a few operators that cannot be overloaded such as scope lookup (`::`), and
member access operators (`.`, `->`, `.*` and `->*`).
```

