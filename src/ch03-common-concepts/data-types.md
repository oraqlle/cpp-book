# Data Types

The type of a value is important in C++ as it determines the permissible actions that
can be performed on the value as well as determine the size of the value in memory. C++
has a great many types but we'll begin by looking at some of the most simple, ones you
will find in every program your read or write.

## Scalar Types

Scalar integrals are types encoded as whole numbers. This not only includes integers
types but C++ character and Boolean types.

### Integer Types

An *integer* is a whole number. C++ has a few different integer types which have 
different bit widths. The default `int` is 32-bits wide on most platforms. By default
integer types are signed ie. they can represent both positive and negative numbers. If
you need unsigned numbers we can use the `unsigned` qualifier.

```cpp,icon=%cplusplus
const int x = -5;
const unsigned int y = 5;
```

If you need integers of a different sizes you can either use size qualifiers with the
`int` type to dictate the minimum size the integer can be. All of these can be used in
combination with the `unsigned` qualifier.

<table><thead>
  <tr>
    <th>Type</th>
    <th>Full Type</th>
    <th>Minimum Size</th>
    <th>Signed Value Range</th>
    <th>Unsigned Value Range</th>
  </tr></thead>
<tbody>
  <tr>
    <td nowrap><code>char</code></td>
    <td nowrap><code>char</code></td>
    <td nowrap>at least 8</td>
    <td nowrap>-128 to 127</td>
    <td nowrap>0 to 255</td>
  </tr>
  <tr>
    <td nowrap><code>short</code></td>
    <td nowrap><code>short int</code></td>
    <td nowrap>at least 16</td>
    <td nowrap>-32,768 to 32,767</td>
    <td nowrap>0 to 65,535</td>
  </tr>
  <tr>
    <td nowrap><code>int</code></td>
    <td nowrap><code>int</code></td>
    <td nowrap>at least 16</td>
    <td nowrap>-32,768 to 32,767</td>
    <td nowrap>0 to 65,535</td>
  </tr>
  <tr>
    <td nowrap><code>long</code></td>
    <td nowrap><code>long int</code></td>
    <td nowrap>at least 32</td>
    <td nowrap>-2,147,483,648<br>to<br>2,147, 483,647</td>
    <td nowrap>0 to<br>4,294, 967,296</td>
  </tr>
  <tr>
    <td nowrap><code>long long</code></td>
    <td nowrap><code>long long int</code></td>
    <td nowrap>at least 64</td>
    <td nowrap>-9,223,372,036,854,775,808<br>to<br>9,223,372,036,854,775,807</td>
    <td nowrap>0 to<br>18,446,744,073,709,551,615</td>
  </tr>
</tbody>
</table>

You can also use [fixed width integer types (FWIT)](https://en.cppreference.com/w/cpp/types/integer).
FWIT have the form std::int*N*\_t or std::uint*N*\_t where *N* is the exact number of
bits wide. The standard library define FWIT (signed and unsigned) for 8, 16, 32, 64 bits
widths.

The bit width of an integer dictates how many values the integer can represent. As of
C++20, all integers must be represented by 2s-complement which means that for signed
numbers the range of values is \\(-2^{N-1}\\) to \\(+2^{N-1}-1\\) eg. -128 to 127
for an 8-bit number and for an unsigned number the range is \\(2^N-1\\) eg. values
0 to 255 for an 8-bit number.

In addition to these integer types there are `std::size_t` and `std::ptrdiff_t` which
are the unsigned and signed types respectively that have the max bit width available on a
given architecture, eg. 64 bits on 64-bit architecture. `std::size_t` is the type used
when indexing arrays or getting the size of objects.

#### Literals

Literals are the symbols that represent an actual value in C++ source code. They are
mostly used to initialize a variable. For example, `1` is an integer literal of type
`int` while `"Hello"` is a string literal of type `const char*` (ignore the meaning of
this type for now).

Literals can have a suffix operator applied to specify the literal has a specific type
or bit width. Some can be used in combination with others such as the `u` literal suffix
on integer literals.

| Keyword      | Description |
|--------------|:-----------:|
| `u` or `U`   |  `unsigned` |
| `l` or `L`   |    `long`   |
| `ll` or `LL` | `long long` |

Additionally you can write integer literals in a different base form by changing the
prefix of the literal.

```cpp,icon=%cplusplus
const auto decimal = 42;
const auto octal = 052;
const auto hex = 0x2a;
const auto Hex = 0X2A; // capital hex digits
const auto binary 0b101010;
```

Integers can also be separated using a `'` to make large numbers easier to read.

```cpp,icon=%cplusplus
const auto x = 1'234'567'890;
```

### Character Types

You'll notice that we have included the `char` type in the integer list above. This is
because character types in C++ are represented using numbers, specifically `char`
represents ASCII code points. Character literals are specified with single quotes like
the example below. 

```cpp,icon=%cplusplus
const char x = 'a';
const auto y = 'b';
```

### Boolean Type

C++'s Boolean type is called `bool` and can either hold the value `true` or `false`.
Booleans are mostly used in conditional and loop statements eg. `if` and `while`.

```cpp,icon=%cplusplus
bool x = false;
auto y = true;
```

```admonish tip
The C language; C++'s mother language, originally did not have a native Boolean type with
Boolean expressions return 1 for `true` and 0 for `false`. Later in the 1999 standard of
C (C99), the `_Bool` type was introduced to support Booleans.
```

## Floating Point Types

C++ has three floating point types, all of which are based on the IEEE-754 standard.
Floating point numbers are used to represent decimal numbers ie. numbers that can store
fractional components. These types are the `float`, `double` and `long double`; with
`float` represent single precision (32-bit) numbers, `double` being double precision
(64-bit) numbers and `long double` being an extended or quadruple precision (128-bit)
floating point number.

All floating point literals have the type of `double` with the `f` and `l` literal suffix
operators specifying a type of `float` and `long double` respectively.

```cpp,icon=%cplusplus
const auto f = -0.06f;
const auto d = 47.5768;
const auto l = -655456.457567l;
```

We can also initialize floating points using exponential form:

```cpp,icon=%cplusplus
const auto f = -6e-2f;
const auto d = 475768e4;
const auto l = -655456457567le7l;
```

#### Arithmetic Operations

Integral and floating point types are categorized as *arithmetic* types which mean they
support the common arithmetic operations like addition, subtraction etc.

```cpp,icon=%cplusplus,fp=main.cxx
$#include <iostream>
$
auto main() -> int {
    // addition
    const auto sum = 4 + 6;

    // subtraction
    const auto sub = 10 - 5.5;

    // multiplication
    const auto mul = 5 * 3.2;

    // division
    const auto idiv = 10 / 3;
    const auto fdif = 13.5 / 2.4;

    // remainder
    const auto rem = 23 % 4;

    // --snip--
$
$    std::cout << "sum: " << sum << "\n";
$    std::cout << "sub: " << sub << "\n";
$    std::cout << "mul: " << mul << "\n";
$    std::cout << "idiv: " << idiv << "\n";
$    std::cout << "fdiv: " << fdiv << "\n";
$    std::cout << "rem: " << rem << "\n";
$
$    return 0;
}
```

```admonish tip
- Division between two integrals performs *integer division* and truncates towards 0 while
if one argument is a floating point then floating point division is performed.
- Remainder is only valid between integral types.

```

## Compound Data Types

Compound data types store multiple pieces of data or are data that can take multiple
values.

### Enumerations

Enumerations or *enums* are a construct that allows you to define a type whose value is
restricted to a set of named variants or *enumerators*. These named constants have an
underlying integral type. Specifying the underlying type is optional ie. omit the
`: type` in the enum declaration.

```cpp,icon=%cplusplus
$#include <iostream>
$
enum class colour : char {
    red,
    green,
    blue
};

auto main() -> int {
    const auto col = colour::red;

    // --snip--
$
$    std::cout << "colour internal value is: " << col << "\n";
$
$    return 0;
}
```


### Tuple

*Tuples* allow you to pack multiple pieces of data of different types into a single
structure. Tuples have a fixed size/number of elements that cannot grow or shrink once
declared. Tuples in C++ are not language types but are provided by the standard library
in the `<tuple>` header and is called `std::tuple`. We create a tuple using brace
initialization (top) or using the helper function `std::make_tuple()`.

```cpp,icon=%cplusplus
$#include <iostream>
$#include <tuple>
$
auto main() -> int {
    const auto t = std::tuple{ 5u, 5.34f, -345, "abc", false };
    const auto u = std::make_tuple(5u, 5.f, -345, "abc", false);
$
$    return 0;
}
```

Tuples can be accessed using `std::get<I>(t)` with `I` being the index of the value we
want to access and `t` is the tuple object.

```cpp,icon=%cplusplus
$#include <iostream>
$#include <tuple>
$
auto main() -> int {
    const auto t = std::tuple{ 5u, 5.34f, -345, "abc", false };
    const auto u = std::make_tuple(5u, 5.f, -345, "abc", false);
    
    const auto e = std::get<2>(t);  // e := -345

    // --snip--
$
$    std::cout << "2nd tuple element is: " << e << "\n";
$
$    return 0;
}
```

You can also destructure tuples into its constituent values like so.

```cpp,icon=%cplusplus
$#include <iostream>
$#include <tuple>
$
auto main() -> int {
    const auto t = std::tuple{ 5u, 5.34f, -345, "abc", false };
    const auto u = std::make_tuple(5u, 5.f, -345, "abc", false);
    
    const auto [v, w, x, y, z] = t;

    // --snip--
$
$    std::cout << "v: " << v << "\n";
$    std::cout << "w: " << w << "\n";
$    std::cout << "x: " << x << "\n";
$    std::cout << "y: " << y << "\n";
$    std::cout << "z: " << z << "\n";
$
$    return 0;
}
```

There is a specialization of *tuples* called `std::pair` found in the `<utility>` header
which holds just two values. The values of a pair can be extracted using the same methods
as tuples but they also have public members `std::pair::first` and `std::pair::second`
which allows you to access the data.

```cpp,icon=%cplusplus
$#include <iostream>
$#include <utility>
$
auto main() -> int {
    const auto p = std::pair{5, 'a'};
    const auto [x, y] = p;
    
    // --snip--
$
$    std::cout << "first: " << p.first << "\n";
$    std::cout << "second: " << p.second << "\n";
$    std::cout << "x: " << x << "\n";
$    std::cout << "y: " << y << "\n";
$
$    return 0;
}
```

<!--
## Special Types

C++ has a handful of special types that you won't use as directly as types but are
fundamental to the language.

The first is the `void` type is an incomplete type that is used to indicate that a
function does not return a value.

```cpp,icon=%cplusplus
auto foo(const int i) -> void {
   i + 5; 
}
```

The other type is `std::nullptr_t` which is the type of `nullptr` the value of a pointer
pointing to nothing.
-->

## Array Types

C++'s array type is a fixed sized container where every elements is of of the same type
and located contiguously next to each other in memory. Much like other types it is found
in the `std` namespace and is called; as you might of guess `std::array`, which You can
import from the `<array>` header. An element in an array can be accessed using the
subscript operator `[]` or the `array::at()` method with indices starting at 0. The
subscript operator access does not perform bounds checking while `array::at()` does,
meaning the latter will throw and exception if an out of bounds index is used while the
former will results in 'Undefined Behaviour' which may or may not crash the program.

```cpp,icon=%cplusplus
$#include <array>
$#include <iostream>
$
auto main() -> int {
    const auto a = std::array{ 1, 2, 3, 4, 5 };
    const auto e1 = a[0]; // valid
    const auto e2 = a.at(5); // exception std::out_of_range
    
    // --snip--
$
$    return 0;
}
```

