# Data Types

```admonish warning
🚧 Page Under Construction! 🏗️
```

As we mentioned on the last page, C++ is a *statically typed* language which means the
type of data must be known (or deducable) to the compiler. C++ has a large selection of
types available to use, some are language primitives and others are defined in the
standard library. In this page we will look at four categories of types,
*scalar integrals*, *floating point*, *compound* and special types.

## Scalar Types

Scalar integrals are types encoded as whole numbers. This not only includes integers
types but C++ character and Boolean types.

### Integer Types

An *integer* is a whole number. C++ has a few different integer types which have 
diffenent bit widths. The default `int` is 32-bits wide on most platforms. By default
integer types are signed ie. they can represent both positive and negative numbers. If
you need unsigned numbers we can use the `unsigned` qualifier.

```cpp
int const x = -5;
unsigned int const y = 5;
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
when index arrays or getting the size of objects. The odd name for `std::ptrdiff_t` is
because this is the type returned after pointer arithmetics however, it is really the
largest signed integer type.

#### Arithmetics

```admonish warning
🚧 Section Under Construction! 🏗️
```

#### Literals

```admonish warning
🚧 Section Under Construction! 🏗️
```

### Character Types

You'll notice that we have included the `char` type in the integer list above. This is
because character types in C++ are represented using numbers, specifically `char`
represents ASCII code points. Character literals are specified with single quotes like
the example below. 

```cpp
char const x = 'a';
auto const y = 'b';
```

### Boolean Type

C++'s Boolean type is called `bool` and can either hold the value `true` or `false`.
Booleans are used mostly in conditional and loop statements eg. `if` and `while`.

```cpp
bool x = false;
auto y = true;
```

```admonish tip
The C language; C++'s mother language, orginally did not have a native Boolean type with
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

With `auto`, floating point values being initialized as a `double` by default and `float`
and `long double` literals being specified by `f` and `l` literal suffixes.

```cpp
auto const f = -0.06f;
auto const d = 47.5768;
auto const l = -655456.457567l;
```

We can also initialize floating points using exponential form:

```cpp
auto const f = -6e-2f;
auto const d = 475768e4;
auto const l = -655456457567le7l;
```

## Compound Data Types

Compound data types store multiple pieces of data or are data that can take multiple
values.

### Enumerations

Enumerations or *enums* are a construct that allows you to define a type whose value is
restricted to a set of named variants or *enumerators*. These named constants have an
underlying integral type. Specifying the underlying type is optional ie. omit the
`: type` in the enum declaration.

```cpp
enum class colour : char {
    red,
    green,
    blue
};

auto const c = colour::red;
```


### Tuple

*Tuples* allow you to pack multiple pieces of data of different types into a single
structure. Tuples have a fixed size/number of elements that cannot grow or shrink once
declared. Tuples in C++ are not language types but are provided by the standard library
in the `<tuple>` header and is called `std::tuple`. We create a tuple using brace
initialization (top) or using the helper function `std::make_tuple()`.

```cpp
auto const t = std::tuple { 5u, 5.34f, -345, "abc", false };
auto const u = std::make_tuple(5u, 5.f, -345, "abc", false);
```

Tuples can be accessed using `std::get<I>(t)` with `I` being the index of the value we
want to access and `t` is the tuple object.

```cpp
auto const e = std::get<2>(t);  // e := -345
```

You can also destructure tuples into its constituent values like so.

```cpp
auto const [v, w, x, y, z] = t;
```

## Special Types

C++ has a handful of special types that you wont use as directly as types but are
fundamental to the language.

The first is the `void` type is an incomplete type that is used to indicate that a
function does not return a value.

```cpp
auto foo(auto const i) -> void {
   i + 5; 
}
```

The other type is `std::nullptr_t` which is the type of `nullptr` the value of a pointer
pointing to nothing.

## Array Types

C++ array type is a fixed sized container where elements are all of the same type.
The array type is called `std::array` and is found in the `<array>` header. Array
elements can be accessed using the subscript operator `[]` or the `array::at()` method
with indices starting at 0. The subscript element access does not perform bounds checking
while `array::at()` does, meaning the later will throw and exception if an out of bounds
index is used while the former will crash the program... sometimes.

```cpp
auto const a = std::array { 1, 2, 3, 4, 5 };
auto const e1 = a[0]; // valid
auto const e2 = a.at(5); // exception std::out_of_range
```

