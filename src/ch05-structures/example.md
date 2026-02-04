# Using Structures

Let us explore how structs can be used in everyday programs. We are going to create a
simple program to calculate operations on a 3D vector type.

```cpp
$#include <cmath>
$#include <iostream>
$
auto magnitude(const double x, const double y, const double z) -> double {
    return std::sqrt(x * x + y * y + z * z);
}

auto main() -> int {
    const auto x = 2.;
    const auto y = 3.;
    const auto z = 5.;

    std::cout << "The magnitude of the vector is "
              << magnitude(x, y, z)
              << "units.\n";
$
$    return 0;
}
```

## Refactoring with Tuples

We can make this code more concise by packing the data into a tuple. This allows the
type signature of `magnitude()` to be much simpler; taking a single parameter, and
ensures all our data is collected together. However, using a tuple leaves room for
ambiguity in which piece of data has which meaning as none of the elements have names.

```cpp
$#include <cmath>
$#include <iostream>
$#include <tuple>
$
using vec3 = std::tuple<double, double, double>;

auto magnitude(const vec3 vec) -> double {
    const auto& [x, y, z] = v;
    return std::sqrt(x * x + y * y + z * z);
}

auto main() -> int {
    const auto v = vec3{2., 3., 5.};

    std::cout << "The magnitude of the vector is "
              << magnitude(v)
              << "units.\n";
$
$    return 0;
}
```

> [!tip]
- The line starting with the `using` keyword is used introduce a *type alias*. This allows
us to define a shorter name for a type we are using frequently. This is particularly
useful for tuples such that we can distinguish two tuples of the same underlying types
but with different purposes.
- We could also have used `std::make_tuple()` to create our tuple object in `main()`
however, I used the brace-initialized from with the type alias to make it clearer what
type `v` is supposed to be.

## Refactoring with structs

We can add more meaning by create a `vec3` struct with named *x, y and z* data members.
Now our `magnitude()` function is able to access the member variables by name.

```cpp
$#include <cmath>
$#include <iostream>
$
struct vec3 {
    double x;
    double y;
    double z;
};

auto magnitude(const vec3 vec) -> double {
    return std::sqrt(vec.x * vec.x
                   + vec.y * vec.y
                   + vec.z * vec.z);
}

auto main() -> int {
    const auto v = vec3{2., 3., 5.};

    std::cout << "The magnitude of the vector is "
              << magnitude(v)
              << "units.\n";
$
$    return 0;
}
```

