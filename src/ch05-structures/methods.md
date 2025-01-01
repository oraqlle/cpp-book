# Methods

As discussed before, *methods* are functions that are called on instances of a struct.
This allows the method to access the member variables of the struct and just like regular
functions we can pass parameters and return values from methods.

## Defining Methods

Let's change our example program from before to use methods instead of a free function.
We define methods within the structs curly braces just like regular functions and call
the function using the dot syntax on an instance of the struct.

```cpp
$#include <cmath>
$#include <iostream>
$
struct vec3 {
    double x;
    double y;
    double z;

    auto magnitude() const -> double {
        return std::sqrt(x * x + y * y + z * z);
    }
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };

    std::cout << "The magnitude of the vector is "
              << v.magnitude()
              << "\n";
$
$    return 0;
}
```

```admonish note
The `const` after the parameter declaration and before the trailing return arrow does not
mean the return type is constant, but rather indicates that this method does not modify
the member variables of this `vec3` instance and thus can be used on on `const`
instances.
```

## `this` keyword

Implicitly, all methods are passed an argument called `this` which is a pointer to the
instance of the struct the method was called on. `this` can be omitted in most cases
with variables automatically being looked up in the struct instance however, if the name
lookup is ambiguous ie. there is a parameter of the same name, then you will need to
access the member variable through `this`. Because `this` is a pointer you cannot use the
dot operator but must use the `->` operator to deference the pointer.

```cpp
$#include <cmath>
$#include <iostream>
$#include <string>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
    auto normalized() const -> vec3 {
        auto const sz = this->magnitude();
        return vec3 { x / sz, y / sz, z / sz };
    }
$
$    // Helper method for stringifying vec3
$    auto to_string() const -> std::string {
$        auto ss = std::stringstream {};
$        ss << "{ "
$           << x
$           << ", "
$           << y
$           << ", "
$           << z
$           << " }";
$
$        return ss.str();
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };
$
$    std::cout << "The magnitude of the vector is "
$              << v.magnitude()
$              << "\n";
$
    auto const n = v.normalized();

    std::cout << "Vector v: "
              << v.to_string()
              << " is: "
              << n.to_string()
              << "\n";
$
$    return 0;
}
```

```admonish warning
We will discuss pointers properly and in detail in *Chapter 13 - Memory* but for now,
think of pointers as like references but closer to a hardware concept.
```

## Taking Parameters

As stated before, we can declare parameters for methods such that they can take
arguments with parameters a declared the same as with free functions.

```cpp
$#include <cmath>
$#include <iostream>
$#include <sstream>
$#include <string>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        auto const sz = this->magnitude();
$        return vec3 { x / sz, y / sz, z / sz };
$    }
$
    auto dot(vec3 const& u) const -> double {
        return x * u.x + y * u.y + z * u.z;
    }
$
$    // Helper method for stringifying vec3
$    auto to_string() const -> std::string {
$        auto ss = std::stringstream {};
$        ss << "{ "
$           << x
$           << ", "
$           << y
$           << ", "
$           << z
$           << " }";
$
$        return ss.str();
$    }
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };
$
$    std::cout << "The magnitude of the vector is "
$              << v.magnitude()
$              << "\n";
$
$    auto const n = v.normalized();
$
$    std::cout << "Vector v: "
$              << v.to_string()
$              << " is: "
$              << n.to_string()
$              << "\n";
$
    auto const u = vec3 { 2., -3., 5. };

    std::cout << "Dot product of v: "
              << v.to_string()
              << " and u: "
              << u.to_string()
              << " is: "
              << v.dot(u)
              << " units \n";
$
$    return 0;
}
```

## Operator Overloading

Just like we can define overloaded operators as free functions we can define overloaded
operators within a struct however, the left hand argument is always the the struct
instance the operator is defined on.

```cpp
$#include <cmath>
$#include <iostream>
$#include <sstream>
$#include <string>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        auto const sz = this->magnitude();
$        return vec3 { x / sz, y / sz, z / sz };
$    }
$
$    auto dot(vec3 const& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
    auto operator*(vec3 const& u) const -> double {
        return this->dot(u);
    }
$
$    // Helper method for stringifying vec3
$    auto to_string() const -> std::string {
$        auto ss = std::stringstream {};
$        ss << "{ "
$           << x
$           << ", "
$           << y
$           << ", "
$           << z
$           << " }";
$
$        return ss.str();
$    }
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };
$
$    std::cout << "The magnitude of the vector is "
$              << v.magnitude()
$              << "\n";
$
$    auto const n = v.normalized();
$
$    std::cout << "Vector v: "
$              << v.to_string()
$              << " is: "
$              << n.to_string()
$              << "\n";
$
    auto const u = vec3 { 2., -3., 5. };

    std::cout << "Dot product of v: "
              << v.to_string()
              << " and u: "
              << u.to_string()
              << " is: "
              << v * u
              << " units \n";
$
$    return 0;
}
```

If we want to reorder the parameters of an operator on our struct but keep the definition
all together we can use the `friend` keyword to create a free function in a structs
definition. This also allows the friend function to access the members of the struct
instance. The `friend` keyword becomes more relevant when discussing
*Access Modifiers* in Chapter 8.

```cpp
$#include <cmath>
$#include <iostream>
$#include <ostream>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        auto const sz = this->magnitude();
$        return vec3 { x / sz, y / sz, z / sz };
$    }
$
$    auto dot(vec3 const& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(vec3 const& u) const -> double {
$        return this->dot(u);
$    }
$
    friend auto operator<<(std::ostream& os, vec3 const& v) -> std::ostream& {
        os << "{ "
           << x
           << ", "
           << y
           << ", "
           << z
           << " }";

        return os;
    }
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };
$
$    std::cout << "The magnitude of the vector is "
$              << v.magnitude()
$              << "\n";
$
$    auto const n = v.normalized();
$
$    std::cout << "Vector v: "
$              << v
$              << " is: "
$              << n
$              << "\n";
$
    auto const u = vec3::unit_x();

    std::cout << "Dot product of v: "
              << v
              << " and u: "
              << u
              << " is: "
              << v * u
              << " units \n";
$
$    return 0;
}
```

## Static Functions

We can also declare `static` methods on a struct which do not operate on an instance but
are simply bound to the struct itself. We declare static methods with the `static`
keyword

```cpp
$#include <cmath>
$#include <iostream>
$#include <ostream>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
    static auto unit_x() -> vec3 {
        return vec3 { 1., 0., 0. };
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        auto const sz = this->magnitude();
$        return vec3 { x / sz, y / sz, z / sz };
$    }
$
$    auto dot(vec3 const& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(vec3 const& u) const -> double {
$        return this->dot(u);
$    }
$
$    // Helper method for stringifying vec3
$    friend auto operator<<(std::ostream& os, vec3 const& v) -> std::ostream& {
$        os << "{ "
$           << x
$           << ", "
$           << y
$           << ", "
$           << z
$           << " }";
$
$        return os;
$    }
};

auto main() -> int {
    auto const v = vec3 { 2., 3., 5. };
$
$    std::cout << "The magnitude of the vector is "
$              << v.magnitude()
$              << "\n";
$
$    auto const n = v.normalized();
$
$    std::cout << "Vector v: "
$              << v
$              << " is: "
$              << n
$              << "\n";
$
    auto const u = vec3 { 2., -3., 5. };

    std::cout << "Dot product of v: "
              << v
              << " and u: "
              << u
              << " is: "
              << v * u
              << " units \n";
$
$    return 0;
}
```

## Summary

While this chapter has only a handful of pages we covered a lot of new features and
syntax. From defining and creating structs, attaching methods to structures and even
static methods!

