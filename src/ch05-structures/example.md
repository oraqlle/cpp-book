# Using Structures

Let us explore how structs can be used in everyday programs. We are going to create a
simple program to calculate operations on a 3D vector type.

```cpp
$#include <cmath>
$#include <iostream>
$
auto magnitude(auto const x, auto const y, auto const z) -> double {
    return std::sqrt(x * x + y * y + z * z);
}

auto main() -> int {
    auto const x = 2.;
    auto const y = 3.;
    auto const z = 5.;

    std::cout << "The magnitude of the vector is "
              << magnitude(x, y, z)
              << "units.\n";
$
$    return 0;
}
```

## Refactoring with Tuples

We can make this code more concise by packing the data into a tuple.

