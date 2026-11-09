# Constructors & Destructors

So far we have only constructed objects of our types using aggregate initialisation
and while this is useful for simple data bundles, this form lacks the nuance required for
constructing more complicated types.

For the following examples we are going to continue building up our `vec3` type. At this
pint I should clarify what the purpose of the `vec3` type is so we know what we are
working towards.

> [!IMPORTANT]
> `vec3` represents a mathematical vector with three components `x`, `y` and `z`. We
> expect to use it to represent, points, velocities in 3D space, It could even represent
> an RGB colour if needed. Given these expected use cases, we expect it to possess
> methods the implement the mathematical operations expected from a 3-component vector.

With the definition out of the way, lets explore the ways we can construct a `vec3`.

## Constructors

Constructors are special methods whose name is the same as its type. The constructors
signature does not indicate any return value as nothing can be returned from a
constructor. Different constructors are designated by the parameters they take, with the
compiler resolving which constructor to execute based on the arguments passed to a given
constructor call. The `this` implicit variable pointer is available within a constructor
to allow explicit access to the members of the "in-construction" object.

### Default Constructor

Default Constructor's are used to initialise a type into its *default* state. For our
`vec3` type, this would be a zero-ed vector ie. all components are set to zero.

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
    vec3() noexcept {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    auto v = vec3(); // selects default constructor;
    auto u = vec3();

    v.x = 2.0;
    v.y = 3.0;
    v.z = 5.0;

    u.x = 2.0;
    u.y = -3.0;
    u.z = 5.0;

    std::cout << "v * u = " << v * u << " units \n";
$
$    return 0;
}
```

That's it! We can now guarantee that a default `vec3` is constructed the same way every
time.

> [!TIP]
> The odd keyword `noexcept` is placed at the end of the constructor's signature to
> indicate this constructor does not throw an exception and thus; by extension, cannot
> fail. This allows the compiler to not have to generate a recovery path for handling
> exceptions in relation to this constructor which can save binary space and execution
> time but, if an exception did bubble out of this constructor, the program would
> encounter a hard error and `std::terminate()` will be called, killing the program.
> Thankfully, for our very simple example with no resource management and simple member
> initialisation it is impossible for an exception to occur. It is general practice to
> place the `noexcept` keyword after a constructor by default unless you expect it to 
> throw or bubble-up an exception.

### Explicit Constructors

Explicit Constructors allow you to define a arbitrary parameters that are used to
initialise an object of the given type. You can define multiple of these constructors
(provided the parameter list is different) and they can be used to directly pass values
down to member variables or have specific meaning to the type it belongs to.

> [!TIP]
> When we construct an object an explicit constructor, the object is said to have had
> undergone [direct initialisation].

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
$    vec3() noexcept {
$        this->x = 0.0;
$        this->y = 0.0;
$        this->z = 0.0;
$    }

    explicit vec3(double x, double y, double z) noexcept {
        this->x = x;
        this->y = y;
        this->z = z;
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const auto u = vec3(2.0, -3.0, 5.0);  // explicitly passing three doubles resolves to
                                          // the constructor we just wrote.

    std::cout << "v * u = " << v * u << " units \n";
$
$    return 0;
}
```

> [!NOTE]
> The `explicit` keyword is required to mark a constructor as *explicit*. Constructors
> with the same kind of signature but without `explicit` is called a
> [converting constructor].

#### Member Initialiser List

There is another form that can be used to initialise members in a constructor called
'Member Initialiser List'. Each member variable is initialised using the syntax
`member(parameter)`, in effect all the constructor of that member.

```cpp
$#include <cmath>
$#include <iostream>
$#include <ostream>
$
struct vec3 {
$    double x;
$    double y;
$    double z;

    vec3() noexcept
    : x(0.0), y(0.0), z(0.0) {}

    explicit vec3(double x, double y, double z) noexcept
    : x(x), y(y), z(z) {}
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const auto u = vec3(2.0, -3.0, 5.0);

    std::cout << "v * u = " << v * u << " units \n";
$
$    return 0;
}
```

### Copy Constructors and Copy Assignments

Now what if you wanted to copy the values of a type from one instance to another? C++ has
a constructor form to achieve that which is cleverly known as a Copy Constructor.
Moreover, if you want to be able to use the assignment operator (`=`) to copy values, you
can overload it to have a similar form.

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
$    vec3() noexcept
$    : x(0.0), y(0.0), z(0.0) {}
$
$    explicit vec3(double x, double y, double z) noexcept
$    : x(x), y(y), z(z) {}

    vec3(const vec3& other) noexcept
    : x(other.x), y(other.y), z(other.z) {}

    auto operator=(const vec3& other) noexcept -> vec3& {
        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const vec3 u(v);  // copy ctor
    const auto w = v; // copy assignment

    std::cout << "v = " << v << "\n"
              << "u = " << u << "\n"
              << "w = " << w << "\n";
$
$    return 0;
}
```

> [!NOTE]
>
> A copy constructor and copy assignment both take a parameter in the same form. For our
> given struct type `T`, a copy constructor/assignment will take a parameter of
> `const T&`.

### Move Constructors and Move Assignments

Earlier we introduced the concept of *move semantics* where ownership of data is
transferred from one instance to another. While `vec3` does not own any resources that
warrant a move constructor, how to define one will still be demonstrated.

```cpp
$#include <cmath>
$#include <iostream>
$#include <ostream>
#include <utility>

struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    vec3() noexcept
$    : x(0.0), y(0.0), z(0.0) {}
$
$    explicit vec3(double x, double y, double z) noexcept
$    : x(x), y(y), z(z) {}
$
$    vec3(const vec3& other) noexcept
$    : x(other.x), y(other.y), z(other.z) {}
$
$    auto operator=(const vec3& other) noexcept -> vec3& {
$        x = other.x;
$        y = other.y;
$        z = other.z;
$
$        return *this;
$    }

    vec3(vec3&& other) noexcept
    : x(std::exchange(other.x, 0.0))
    , y(std::exchange(other.y, 0.0))
    , z(std::exchange(other.z, 0.0))
    {}

    auto operator=(vec3&& other) noexcept -> vec3& {
        x = std::exchange(other.x, 0.0);
        y = std::exchange(other.y, 0.0);
        z = std::exchange(other.z, 0.0);

        // If vec3 owned a resource eg. a std::string,
        // std::move() would be called on it so its
        // move ctor can be used:
        // str = std::move(other.str);

        return *this;
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const vec3 u(std::move(v));  // move ctor
    const auto w = std::move(v); // move assignment

    std::cout << "v = " << v << "\n"
              << "u = " << u << "\n"
              << "w = " << w << "\n";
$
$    return 0;
}
```

> [!TIP]
>
> `std::exchange()` is a utility function that replaces the left parameter value with the
> right parameter and returns the left's old value.

> [!NOTE]
>
> Like copy constructors, move constructors/assignment both take a parameter in the same
> form. That is for our given struct type `T`, a move constructor/assignment will take a
> parameter of `T&&`. Notice that this parameter is not `const` as we want to be able to
> be able to modify the moved from object.

## Destructors

What if we want to control how data is freed? This is where a destructor is defined.
There is only one destructor for a given type and it is defined using the types name,
like other constructors, with a tilde (`~`) in front of it. The `vec3` we have defined
thus far does not have any resources to free but again, we'll define one for arguments
sake.

```cpp
$#include <cmath>
$#include <iostream>
$#include <ostream>
$#include <utility>
$
struct vec3 {
$    double x;
$    double y;
$    double z;
$
$    vec3() noexcept
$    : x(0.0), y(0.0), z(0.0) {}
$
$    explicit vec3(double x, double y, double z) noexcept
$    : x(x), y(y), z(z) {}
$
$    vec3(const vec3& other) noexcept
$    : x(other.x), y(other.y), z(other.z) {}
$
$    auto operator=(const vec3& other) noexcept -> vec3& {
$        x = other.x;
$        y = other.y;
$        z = other.z;
$
$        return *this;
$    }
$
$    vec3(vec3&& other) noexcept
$    : x(std::exchange(other.x, 0.0))
$    , y(std::exchange(other.y, 0.0))
$    , z(std::exchange(other.z, 0.0))
$    {}
$
$    auto operator=(vec3&& other) noexcept -> vec3& {
$        x = std::exchange(other.x, 0.0);
$        y = std::exchange(other.y, 0.0);
$        z = std::exchange(other.z, 0.0);
$
$        return *this;
$    }

    ~vec3() noexcept {
        // free resources
        std::cout << "Dtor called\n";
    }
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const auto u = vec3(2.0, -3.0, 5.0);

    std::cout << "v * u = " << v * u << "\n";

    return 0;
    // destructors called here
}
```

## Let the Compiler Define Them

As stated throughout this page, our `vec3` type is not very complex with the default,
copy and move constructors we have defined thus far are pretty trivial. Even out
destructor doesn't do anything. In these cases, we can let the compiler define these
constructors for use using the `= default` keyword.

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
    vec3() noexcept = default;
$
$    explicit vec3(double x, double y, double z) noexcept
$    : x(x), y(y), z(z) {}

    vec3(const vec3& other) noexcept = default;
    vec3(vec3&& other) noexcept = default;

    auto operator=(const vec3& other) noexcept -> vec3& = default;
    auto operator=(vec3&& other) noexcept -> vec3& = default;

    ~vec3() noexcept = default;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const auto u = vec3(2.0, -3.0, 5.0);

    std::cout << "v * u = " << v * u << "\n";
$
$    return 0;
}
```

> [!NOTE]
>
> Explicit constructor or converting constructors cannot be *defaulted* as these
> constructors are more specialised.

## Disabling Behaviour

In a similar vein, we disable a constructor using the `= delete` keyword. This is useful
if a type cannot have the semantics associated with the constructor eg. a handle to a
file should not be copied as that could introduce multiple owners but should be allowed
to change owners via moves.

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
    vec3() noexcept = delete;
$
$    explicit vec3(double x, double y, double z) noexcept
$    : x(x), y(y), z(z) {}
$
$    vec3(const vec3& other) noexcept = default;
$    vec3(vec3&& other) noexcept = default;
$
$    auto operator=(const vec3& other) noexcept -> vec3& = default;
$    auto operator=(vec3&& other) noexcept -> vec3& = default;
$
$    ~vec3() noexcept = default;
$
$    auto magnitude() const -> double {
$        return std::sqrt(x * x + y * y + z * z);
$    }
$
$    auto normalized() const -> vec3 {
$        const auto sz = this->magnitude();
$        return vec3{x / sz, y / sz, z / sz};
$    }
$
$    auto dot(const vec3& u) const -> double {
$        return x * u.x + y * u.y + z * u.z;
$    }
$
$    auto operator*(const vec3& u) const -> double {
$        return this->dot(u);
$    }
$
$    friend auto operator<<(std::ostream& os, const vec3& v) -> std::ostream& {
$        os << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
$        return os;
$    }
};

auto main() -> int {
    const auto v = vec3(2.0, 3.0, 5.0);
    const auto u = vec3(2.0, -3.0, 5.0);
    const auto w = vec3(); // deleted ctor, fails to compile

    std::cout << "v * u = " << v * u << "\n";
$
$    return 0;
}
```

## Other Constructors...?

There are quite few ways to construct a type in C++ which gives you an enourmous amount
of control over your programs behaviour but can be a lot for a beginner to learn so we
are going to leave it here. If you want to learn more, check out the
[page on cppreference.com](https://en.cppreference.com/cpp/language/constructor).

## Summary

Constructors and Destructors is one of the most involved topics in the C++ language, with
many variations, rules and conventions but that is because controlling how data is
created and lives throughout the lifetime of your programs is a fundamental part of C++,
giving you complete control over the objects you create. Fantastic work for persevering
through this page and I recommend bookmarking it as you might need to refer back to it
throughout your early C++ journey.

