# A - Keywords

```admonish warning
🚧 Page Under Construction! 🏗️
```

This is the list of keywords reserved by C++. This means these words cannot be used as an
identifier for variables, functions, class/struct member names etc.. Some are reserved
with no current or deprecated usecase.

## Currently in Use

| Keyword                 | Description |
|-------------------------|:-----------:|
| `alignas` (C++11)       |             |
| `alignof` (C++11)       |             |
| `and`                   |             |
| `and_eq`                |             |
| `asm`                   |             |
| `auto`                  |             |
| `bitand`                |             |
| `bitor`                 |             |
| `break`                 |             |
| `case`                  |             |
| `catch`                 |             |
| `class`                 |             |
| `compl`                 |             |
| `concept` (C++20)       |             |
| `const`                 |             |
| `consteval` (C++20)     |             |
| `constexpr` (C++11)     |             |
| `constinit` (C++20)     |             |
| `const_cast`            |             |
| `continue`              |             |
| `co_await` (C++20)      |             |
| `co_return` (C++20)     |             |
| `co_yield` (C++20)      |             |
| `decltype` (C++11)      |             |
| `default`               |             |
| `delete`                |             |
| `do`                    |             |
| `double`                |             |
| `dynamic_cast`          |             |
| `else`                  |             |
| `enum`                  |             |
| `explicit`              |             |
| `export`                |             |
| `extern`                |             |
| `false`                 |             |
| `float`                 |             |
| `for`                   |             |
| `friend`                |             |
| `goto`                  |             |
| `if`                    |             |
| `inline`                |             |
| `mutable`               |             |
| `namespace`             |             |
| `new`                   |             |
| `noexcept` (C++11)      |             |
| `not`                   |             |
| `not_eq`                |             |
| `nullptr` (C++11)       |             |
| `operator`              |             |
| `or`                    |             |
| `or_eq`                 |             |
| `private`               |             |
| `protected`             |             |
| `public`                |             |
| `register`              |             |
| `reinterpret_cast`      |             |
| `requires` (C++20)      |             |
| `return`                |             |
| `signed`                |             |
| `sizeof`                |             |
| `static`                |             |
| `static_assert` (C++11) |             |
| `static_cast`           |             |
| `struct`                |             |
| `switch`                |             |
| `template`              |             |
| `this`                  |             |
| `thread_local` (C++11)  |             |
| `throw`                 |             |
| `true`                  |             |
| `try`                   |             |
| `typedef`               |             |
| `typeid`                |             |
| `typename`              |             |
| `union`                 |             |
| `unsigned`              |             |
| `using`                 |             |
| `virtual`               |             |
| `void`                  |             |
| `volatile`              |             |
| `while`                 |             |
| `xor`                   |             |
| `xor_eq`                |             |

## Reserved In Specific Contexts

These keywords are reserved in specific circumstances like in a class declaration etc..

| Keyword            | Description                                                               |
|--------------------|---------------------------------------------------------------------------|
| `final` (C++11)    | Specifies virtual member function cannot be overridden in child class.    |
| `override` (C++11) | Specifies virtual member function definition overrides parent definition. |
| `import` (C++20)   | Module import declaration.                                                |
| `module` (C++20)   | Module and module fragment declaration.                                   |

## Reserved for Future Use

These keywords are reserved for experimental features being tested in a
[Technical Specification](https://en.cppreference.com/w/cpp/experimental).

| Keyword                    | Technical Specification      | Description                                                                                                                                          |
|----------------------------|------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------|
| `atomic_cancel`            | Transactional Memory (TM) TS | Starts atomic block that will restore data modified during atomic block for some exception types, otherwise it will call `std::abort`.               |
| `atomic_commit`            | Transactional Memory (TM) TS | Starts atomic block that commits data changes regardless of exceptions being thrown.                                                                 |
| `atomic_noexcept`          | Transactional Memory (TM) TS | Starts atomic block that will call `std::abort` if exception is thrown within the block.                                                             |
| `reflexpr`                 | Reflection TS                | Provides meta info about an object by returning a _meta-object_.                                                                                     |
| `synchronized`             | Transactional Memory (TM) TS | Starts a [synchronized block](https://en.cppreference.com/w/cpp/language/transactional_memory#Synchronized_blocks)                                   |
| `transaction_safe`         | Transactional Memory (TM) TS | Indicates that a function is [transaction-safe](https://en.cppreference.com/w/cpp/language/transactional_memory#Transaction-safe_functions).         |
| `transaction_safe_dynamic` | Transactional Memory (TM) TS | Indicates that a virtual function is [transaction-safe](https://en.cppreference.com/w/cpp/language/transactional_memory#Transaction-safe_functions). |

