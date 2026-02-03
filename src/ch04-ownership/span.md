# The `span` and `string_view` types

> [!WARNING]
> 🚧 Page Under Construction! 🏗️

## `string_view`

Often we want to reference only part of a `string`, in the past we would use
`string::substr()` however this would return a newly allocated `string` so in C++17 we
got `std::string_view` which is a reference to a series of characters however, it does
not *own* the characters. `string_view` has almost all the same operations as `string`
which makes it super versatile as a `string` substitute when needing to reference part of
a `string`.

```cpp
$#include <iostream>
$#include <string>
$#include <string_view>
// --snip--

auto main() -> int {
    auto s = std::string { "hello" };
    auto sv = std::string_view { s.data() + 1, 3 };

    std::cout << s << "\n";
    std::cout << sv << "\n";
    
$    return 0;
// --snip--
}
```

> [!NOTE]
> The `string::data()` method is used to get the address of the first element in a
> `string` thus we can use it to get the starting address of our substring by offsetting
> it by the correct number of characters as seen above.

We can also use `string_view` to handle *string literals*, these are the strings we create
using double quotes (`""`). This makes string literals; which previously was just an
address to the character data, much easier to use and much closer to `strings`, with the
the constraint that you cannot modify this text.

```cpp
$#include <iostream>
$#include <string>
$#include <string_view>

using namespace std::literals;

auto main() -> int {
    auto sv1 = std::string_view { "hello" };
    auto sv2 = "bye"sv;

    std::cout << sv1 << "\n";
    std::cout << sv2 << "\n";
    
$    return 0;
// --snip--
}
```

> [!TIP]
> We can create `strings` and `string_views` from *string literals* using
> *literal operators*. Literal operators are suffixes you attach to a literals; like the
> `u` suffix to make an integer literal `unsigned`, that can be used to construct a
> custom type from the literals. In this case, we can make a `string` or `string_view`
> using the `s` or `sv` literal operators respectively. These are found in the namespace
> `std::literals` which we expose globally in the line above `main()`.

## Spans

We can general this ntion of a view using the `std::span` type. Because `spans` are more
general than a `string_view` there are far fewer methods available however, they still
cover all you need when working with a generalised view (or *span*) of a contiguous
data structure.

`spans` are used for similar reasons to `string_view`, to easily accesses subslices of a
contiguous data structure (ie. a subarray) or to adapt C-arrays into a safer type.

```cpp
$#include <iostream>
$#include <array>
$#include <span>
$
$auto main() -> int {
    // --snip--

    auto a1 = std::array { 1, 2, 3, 4, 5 };
    auto s1 = std::span { a1.data() + 1, 3 };

    int a2[] = { 1, 2, 3, 4, 5 }; // C-array
    auto s2 = std::span { a2 };
    
$    return 0;
$}
    // --snip--
```

> [!CAUTION]
> You don't need to worry about why C-arrays are unsafe for the purposes of this book. In
> a nutshell C-arrays (and string literals for that matter) are very primitive structures
> that do not provide any guards from misuse.
>
> This has the benefit of allowing clever uses of the structures for the sake of
> performance and optimization which can be a good thing for system languages especially
> for the time period C came onto the scene however, when learning a system language
> guards help ensure correct practices are followed and engrained early in your journey
> so they do not become *footguns* in the future. This is why this book does not cover
> content from C as C++ has given many safer alternatives for decades.

