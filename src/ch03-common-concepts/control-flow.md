# Control Flow

```admonish warning
🚧 Page Under Construction! 🏗️
```

Control flow is how we get our programs to do interesting things, it allows us to write
programs that do different things depending on conditions (branch) or easily repeat code
(loops). C++ also has various relational and logical operators used to construct
conditional expressions used by the control flow statements. You can read about them in
[Appendix B](../appendix/B-operators.md).

## Branches

### if statements

An `if` statement is the simplest control flow structure, it allows us to execute a piece
of code as long as a condition is `true`. `if` statements are declared using the `if`
keyword followed by the conditional expression in parenthesis. The code to execute is
contained in braces like function definitions.

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto const x = 6;

    if (x % 2 == 0) {
        std::cout << "Even\n";
    }

$    return 0;
// --snip--
}
```

We can add an alternative branch using the `else` keyword after the closing the brace of
the `if` the block. This branch will run if the condition in the `if` statement is
`false`. 

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto const x = 5;

    if (x % 2 == 0) {
        std::cout << "Even\n";
    } else {
        std::cout << "Odd\n";
    }

$    return 0;
// --snip--
}
```

We can create a multiple branches based on various conditions using an `else if`
statement. These declared after the initial `if` statement.

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto const x = 5;

    if (x % 2 == 0) {
        std::cout << "Even\n";
    } else if (x % == 5) {
        std::cout << "5 multiple\n";
    } else {
        std::cout << "Odd\n";
    }

$    return 0;
// --snip--
}
```

### switch statements

`switch` statements are a way to mix control flow with enums. `switch` statements are
given a enum object which are then matched against different cases ie. enum variants.
There is a `default` case that is used if no case is match, the equivelent of `else`
from `if` statements.

The cases of a `switch` statements automatically fallthrough to the next case if you do
not use a `break` statement to escape from the `switch`.

```cpp
$#include <iostream>
// --snip--

enum class colour : char {
    red,
    green,
    blue
};

auto main() -> int {
    auto const c = colour::red;
    
    switch (c) {
        case colour::red:
            std::cout << "red\n";
            break;
        case colour::green:
            std::cout << "green\n";
            break;
        case colour::blue:
            std::cout << "blue\n";
            break;
        default:
            std::cout << "unknown\n";
            break;
    }

$    return 0;
// --snip--
}
```

```admonish note
Because enums are fundamentally based on an underlying integral type, `switch` statements
thus can work on any integral type like `char` or `int` however, you have to be sure to
cover all the cases as there is no formally notion of pattern matching over integral
ranges.
```

## Loops

### while loop

`while` loops are the fundamental looping construct in C++. A `while` loops will repeat
as long as the condition remains `true`.

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto i = 0uLL;
    auto acc = 0uLL;

    while (i < 10) {
        acc += i;
        i += 1;
    }

    std::cout << "Sum: " << acc << "\n";

$    return 0;
// --snip--
}
```

There is another `while` loop called a `do-while` loop. This has the same semantics as
a `while` loop but the loop condition is checked at the end of the loop instead of at the
start. This has the effect of running the loop at least once.

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto i = 0uLL;
    auto acc = 0uLL;

    do {
        acc += i;
        i += 1;
    } while (i < 1);

    std::cout << "Sum: " << acc << "\n";

$    return 0;
// --snip--
}
```

### for loop

`for` loops further abstract the concepts of loops by providing dedicated syntax for
initializing the loop counter and incrementing the loop unlike a `while` loop which only
only has syntax for checking the loop condition. We saw a `for` loop in our `constexpr`
example.

```cpp
$#include <iostream>
// --snip--

auto main() -> int {
    auto acc = 0uLL;

    for (auto i = 0; i < 10; i++) {
        acc += i;
    }

    std::cout << "Sum: " << acc << "\n";

$    return 0;
// --snip--
}
```

### range-for loop

In C++11, we got another `for` loop called a `range-for` loop. This loop is able to
automatically traverse C++ standard container types like `std::array`. This is beneficial
as it prevents us from incorrectly accessing/traversing the container ie. indexing out of
the array/containers bounds.

```cpp
$#include <iostream>
$#include <array>
// --snip--

auto main() -> int {
    auto const a = std::array {1, 2, 3, 4, 5};
    auto acc = 0uLL;

    for (auto const x : a) {
        acc += x;
    }

    std::cout << "Sum: " << acc << "\n";

$    return 0;
// --snip--
}
```

