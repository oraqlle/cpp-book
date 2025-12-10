# What is Ownership?

```admonish warning
🚧 Page Under Construction! 🏗️
```

*Ownership* is the notion that some data is managed or *owned* by a particular variable
and thus is responsible for ensuring that it's data lives long enough for all parts of
the program that *reference* the data can correctly access the data.

We first had a look at lifetimes in [Common Concepts - Variables and Mutability](/ch03-common-concepts/vars-mut.html#storage-duration)
when discussing *storage duration* of data but we are now going to discuss how this comes
into effect in our programs.

```admonish question title="The Stack and the Heap"
You'll hear a lot about the *stack* and the *heap* when discussing C++ but what are they?

These are two regions of memory that your program can access during its execution. The
*stack* is a fixed sized region that is utilised automatically by your program. When
variables are created, the data is pushed onto the top of the stack and the
*stack pointer* is incremented by the size in bytes of this newly pushed variable. When
that variable is no longer referenceable ie. it goes out of scope, the value is popped off
the stack thus deleted the data. Data with *automatic storage duration* live on the stack
and it is where all variables we have shown in the previous examples have been allocated
to.

Function calls also interact with the stack in an interesting way. When a function is
called the stack creates a new *stack frame* which encapsulates all the data created
during the function call, as well as information about parameters and how to get back to
the function's call site ie. parameter data and return address storage. This is done so
that when a function does return, the entire stack frame can be popped off, deallocating
all data created during the functions execution.

All in all, the stack is super fast and automatic allocates and deallocates memory for
us thus allowing the lifetime of variables to be computed by the compiler, not us! So why
don't we always use the stack? We can't because the stack is a fixed size and cannot grow
beyond its original capacity which usually isn't very large because our OS wants to allow
lots of programs to be able to run at once.

This is where the *heap* comes in. The heap is slow but dynamic memory that our program
requests at runtime. This allows us to create variable sized memory regions that we can
grow and shrink as need be however, this comes at the cost of having to manually return
this memory back to the OS otherwise it is **leaked**! This means we have to track the
lifetime of the data we create and ensure it is freed correctly. Data of this kind is
categories as having *dynamic storage duration*.
```

## Scope

Scopes define what set of symbols and objects are valid to reference in our program.
We've encounter quite a few different uses of scope in our travels this far. The obvious
one being functions. Functions create an entirely new scope that isn't just semantic
(ie. only enforced by the compiler for correctness sake) but have an effect on the
execution of a program. When a function is called it allocates a new stack frame meaning
the lifetime of all data creating in that function is bound to that function's lifetime.

We also can see scope with conditional statements like `for` and `range-for` loops as the
initializer and iterator for each statement type respectively is only bound to the scope
of the statement body. In fact, you can introduce an unnamed scope using a brace block.

```cpp
{
    auto const x = 5;

    // do stuck with x
}
// x out of scope
```

So how do we share data? In C++, variables have copy semantics and what this means is
that the data of an object is copied when we bind a new variable to an existing
variable. We can see this in the play below with `y` being assigned the value of `x` not
`x` itself and thus the address of each object is unique.

```cpp
$#include <iostream>
// --snip--

$auto main() -> {
    auto const x = 5;
    auto const y = x;

    std::cout << &x << "\n";
    std::cout << &y << "\n";
$    return 0;
$}
// --snip--
```

```admonish tip
Notice the addresses of `x` and `y` are only 4 bytes apart, this is because they are
right next to each other on the stack as we discussed above.
```

## The `std::string` Type

So what happens when data on the heap goes out of scope? To demonstrate what happens we
need to introduce the `std::string` type. `string` is more complex than the type
introduced in [Common Concepts - Data Types](/ch03-common-concepts/data-types.md)
as it allocates its data on the heap and can change its size during runtime, as opposed
to string literals which are encoded directly into the compiled binary. We even saw
`string` in our guessing game!

<!-- diagram of s pointing to data -->

<!-- `string` is structured according to the below image with the owning object storing the
pointer to the heap data as well as some meta-info like the size of the `string` and how
much memory has been allocated for the `string`. -->

```admonish note
String literials are declared using a pair of double quotes (`""`) to surround the text
and is of the type of a pointer to the first character (`const char*`).
```

So how can we ensure that the memory allocated on the heap is automatically freed when
the variable goes out of scope? Some languages use a *Garbage Collector* (GC) to clean up
memory that hasn't been used recently. In C++ we do not have a GC so it is our
responsiblility to identify when memory is no longer needed or is it? C++ uses a concept
known as *Resource Acquisition Is Initialization* or *RAII*. In essence it is the idiom
of binding the lifetime of a resource; like memory, to the variable or object that own
it and thus allowing for the resource to be freed when the owning variable goes out of
scope. This is how `string`; and any other standard library containers, works. 

```cpp
$#include <iostream>
$#include <string>
// --snip--

$auto main() -> {
    {
        auto const s = std::string {"hello"};

        // s is in scope
    }
    // s out of scope and data freed

$    return 0;
$}
// --snip--
```

