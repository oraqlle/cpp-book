# B - Operators

> [!WARNING]
> 🚧 Page Under Construction! 🏗️

This page is a high level overview of C++ operators and other symbols and what they do.

- ✅ - Fully overloadable
- ☑️  - Overloadable with constraints
- ⚠️  - Overloadable but not recommended
- ❌ - Not overloadable

## Basic Operators

|  Operator  |                    Example                    |                       Description                       | Overloadable  |
|:----------:|:---------------------------------------------:|:-------------------------------------------------------:|:-------------:|
|    `+`     |                    `+expr`                    |                  Arithmetic posigation                  |       ✅      |
|    `+`     |                 `expr + expr`                 |                   Arithmetic addition                   |       ✅      |
|    `++`    |                    `++expr`                   |                     Prefix increment                    |       ✅      |
|    `++`    |                    `expr++`                   |                    Postfix increment                    |       ✅      |
|    `+=`    |                 `var += expr`                 |            Arithmetic addition and assignment           |       ✅      |
|    `-`     |                    `-expr`                    |                   Arithmetic negation                   |       ✅      |
|    `-`     |                 `expr - expr`                 |                  Arithmetic subtraction                 |       ✅      |
|    `--`    |                    `--expr`                   |                     Prefix decrement                    |       ✅      |
|    `--`    |                    `expr--`                   |                    Postfix decrement                    |       ✅      |
|    `-=`    |                 `var -= expr`                 |          Arithmetic subtraction and assignment          |       ✅      |
|    `*`     |                    `*expr`                    |                   Pointer dereference                   |       ☑️       |
|    `*`     |                 `expr * expr`                 |                Arithmetic multiplication                |       ✅      |
|    `*=`    |                 `var *= expr`                 |         Arithmetic multiplication and assignment        |       ✅      |
|    `/`     |                 `expr / expr`                 |                   Arithmetic division                   |       ✅      |
|    `/=`    |                 `var /= expr`                 |            Arithmetic division and assignment           |       ✅      |
|    `%`     |                 `expr % expr`                 |                   Arithmetic remainder                  |       ✅      |
|    `%=`    |                 `var %= expr`                 |           Arithmetic remainder and assignment           |       ✅      |
|    `~`     |                    `~expr`                    |                    Bitwise Complement                   |       ✅      |
|    `&`     |                    `&expr`                    |                        Address of                       |       ✅      |
|    `&`     |      `type ident&`, `const type ident&`       |                      Reference type                     |       ❌      |
|    `&`     |                 `expr & expr`                 |                       Bitwise AND                       |       ✅      |
|    `&=`    |                 `var &= expr`                 |                Bitwise AND and assignment               |       ✅      |
|    `&&`    |                 `expr && expr`                |                       Logical AND                       |       ☑️       |
|    `\|`    |                 `expr \| expr`                |                        Bitwise OR                       |       ✅      |
|    `\|=`   |                 `var \|= expr`                |                Bitwise OR and assignment                |       ✅      |
|   `\|\|`   |                `expr \|\| expr`               |                        Logical OR                       |       ☑️       |
|    ` ^`    |                 `expr ^ expr`                 |                       Bitwise XOR                       |       ✅      |
|    `^=`    |                 `var ^= expr`                 |                Bitwise XOR and assignment               |       ✅      |
|    `<<`    |                 `expr << expr`                |                    Bitwise left shift                   |       ✅      |
|    `<<=`   |                 `var <<= expr`                |            Bitwise left shift and assignment            |       ✅      |
|    `>>`    |                 `expr >> expr`                |                   Bitwise right shift                   |       ✅      |
|    `>>=`   |                 `var >>= expr`                |            Bitwise right shift and assignment           |       ✅      |
|    `!`     |                    `!expr`                    |                       Logical NOT                       |       ✅      |
|    `==`    |                 `expr == expr`                |                   Equality comparison                   |       ✅      |
|    `!=`    |                 `expr != expr`                |                  Inequality comparison                  |       ✅      |
|    ` <`    |                 `expr < expr`                 |                        Less than                        |       ✅      |
|    `<=`    |                 `expr <= expr`                |                    Less than or equal                   |       ✅      |
|    ` >`    |                 `expr > expr`                 |                       Greater than                      |       ✅      |
|    `>=`    |                 `expr >= expr`                |                  Greater than or equal                  |       ✅      |
|    `<=>`   |                `expr <=> expr`                |                   Three way comparison                  |       ✅      |
|    `[]`    |             `expr[expr, expr, ..]`            | Subscript / array indexing (multi-argument since C++23) |       ✅      |
|    `()`    |             `expr(expr, expr, ..)`            |                Function object invocation               |       ✅      |
|    ` ,`    |                  `expr, expr`                 |                     Comma sequencing                    |       ⚠️       |
|    ` =`    |          `var = expr`, `ident = expr`         |                   Assignment / Binding                  |       ☑️       |
|    `?:`    |              `expr ? expr : expr`             |                    Ternary expression                   |       ❌      |
|    `::`    |           `ident::ident, ident::var`          |                     Namespace lookup                    |       ❌      |
|    `...`   | `typename types...`, `type T...`, `T... args` |              Parameter type and value packs             |       ❌      |
|    ` .`    |                  `expr.ident`                 |                      Member access                      |       ❌      |
|    `.*`    |                 `expr.*ident`                 |             Member access to pointer members            |       ❌      |
|    `->`    |                 `expr->ident`                 |             Member access through a pointer             |       ☑️       |
|    `->*`   |                 `expr->*ident`                |    Member access through a pointer to pointer members   |       ☑️       |
|    `""`    |             `literal_suffix-ident`            |                   User defined literal                  |       ☑️       |

## Memory Operators

|   Operator  |            Example           |                                Description                               |
|:-----------:|:----------------------------:|:------------------------------------------------------------------------:|
|    `new`    |    `new type (init-list)`    | Allocate a heap memory object constructed with parameters in *init-list* |
|   `new []`  | `new type[size]{init-list}`  |   Allocate a heap memory block initialized with elements in *init-list*  |
|   `delete`  |         `delete expr`        |                         Delete heap memory object                        |
| `delete []` |       `delete [] expr`       |                         Deletes heap memory block                        |

## Type Casting Operators

|      Operator      |           Example           |                                          Description                                         |
|:------------------:|:---------------------------:|:--------------------------------------------------------------------------------------------:|
|    `static_cast`   |    `static_cast<T>(expr)`   |                                   Casts `expr` to type `T`                                   |
|   `dynamic_cast`   |   `dynamic_cast<T>(expr)`   | Casts pointers and references to classes up, down and sideways through inheritance hierarchy |
| `reinterpret_cast` | `reinterpret_cast<T>(expr)` |            Casts `expr` to type `T` by *reinterpreting* underlying bits of `expr`            |
|    `const_cast`    |    `const_cast<T>(expr)`    |           Can cast to or away `const` when type of `expr` and `T` are similar types          |
|       C-cast       |         `(type)expr`        |                  Legacy type cast from C, uses a combination of above casts                  |

## Other Operators

|   Operator  |                   Example                   |                     Description                    |
|:-----------:|:-------------------------------------------:|:--------------------------------------------------:|
|   `sizeof`  |        `sizeof(expr)`, `sizeof(type)`       |  Obtains the size in bytes of a type or expression |
| `sizeof...` | `sizeof...(pack-expr)`, `sizeof(pack-type)` | Obtains the number of elements of a parameter pack |
|   `typeid`  |        `typeid(expr)`, `typeid(type)`       |      Obtains compiler representation of a type     |
|  `noexcept` |               `noexcept(expr)`              |   Checks if an expression will throw an exception  |
|  `alignof`  |              `alignof(typeid)`              |      Obtains the alignment required by a type      |

