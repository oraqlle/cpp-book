# Creating Structures

```admonish warning
🚧 Page Under Construction! 🏗️
```

To declare a struct we use the `struct` keyword followed by the name of the new type.
Members are defined inside curly braces using the same variable and function declaration
syntax we have seen previously; although variables do not need an initializer and thus
`auto` is less powerful in member variable declarations. The entire struct is capped by a
semicolon.

```cpp
$#include <string>
$
struct Person {
    bool alive;
    std::size_t age;
    std::string name;
    std::string email;
};
$
$auto main() -> int {
$    return 0;
$}
```

We can then create an *instance* of the struct using an aggregate initializer. This is
the process of giving concrete value to the member variables using a brace-initializer
list. The order in which we initialize member variables is the same as the order member
variables are declared in.

```cpp
$#include <string>
$
$struct Person {
$    bool alive;
$    std::size_t age;
$    std::string name;
$    std::string email;
$};
$
auto main() -> int {
    auto const p = Person {
        true,
        23,
        "John Doe",
        "johnd@example.com"
    };
$
$    return 0;
}
```

To access member variables we use the *member access operator* (`.`). If your object is
not constant you can also assign new values to members through the dot operator.

```cpp
$#include <string>
$
$struct Person {
$    bool alive;
$    std::size_t age;
$    std::string name;
$    std::string email;
$};
$
auto main() -> int {
    auto p = Person {
        true,
        23,
        "John Doe",
        "johnd@example.com"
    };

    p.email = "jdoe@sample.com";
$
$    return 0;
}
```

```admonish tip
You can mark individual member variables as `const` so only certain data can be modified.
```

Functions can return structs just like builtin types. Here we have a function that
creates a `Person`.

```cpp
$#include <string>
$#include <string_view>
$
$struct Person {
$    bool alive;
$    std::size_t age;
$    std::string name;
$    std::string email;
$};
$
auto make_person(std::string_view const name, std::string_view const email) -> Person {
    return Person {
        true,
        0,
        std::string{ name },
        std::string{ email }
    };
}

auto main() -> int {
    auto const p = make_person(
            "John Doe",
            "johnd@example.com"
    );
$
$    return 0;
}
```

For simple structs like this, the compiler will generate a few *constructors* for us such
as a *default constructor* and a *copy constructor*. These allow these simple types to be
copied or constructed in a default state without having to specify this process
ourselves.

```cpp
$#include <string>
$#include <string_view>
$
$struct Person {
$    bool alive;
$    std::size_t age;
$    std::string name;
$    std::string email;
$};
$
$auto make_person(std::string_view const name, std::string_view const email) -> Person {
$    return Person {
$        true,
$        0,
$        std::string{ name },
$        std::string{ email }
$    };
$}
$
auto main() -> int {
    auto const p1 = make_person(
            "John Doe",
            "johnd@example.com"
    );
    
    // Default construct
    auto p2 = Person {};

    // Copy
    auto p3 = p1;
$
$    return 0;
}
```

```admonish example title="Constructors"
We will explore constructors *Chapter 8 - Custom Types* and how we can use them to control
the initialization of our own types. We will also explore how to disable certain
constructors to disallow certain behaviours from our types.
```

