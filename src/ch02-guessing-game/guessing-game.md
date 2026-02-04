# Project: Guessing Game

Let us jump straight into C++ by developing a project together! This will help expose you
to some common concepts from C++ and how they are used in an actual program. You'll learn
how create variables, control the flow of your program, take in user input, create
functions and more! These concepts will be explored in more detail in future chapters
while this one will focus on the fundamentals.

We'll be implementing a simple number guessing game. The program will generate a random
integer between 1 and 100 (inclusive). It will then prompt the user to type in a guess.
After the guess is entered the program will indicate whether the guess was too high or to
low or a congratulatory message if the user got it right and exit the program.

## Setting Up a New Project

To begin, create a new directory in your `projects/` directory called `guessing_game` and
create your `main.cxx` and `CMakeLists.txt` files.

```sh,icon=%gnubash,fp=Shell
mkdir guessing_game
cd ~/projects/guessing_game
touch main.cxx
touch CMakeLists.txt
```

```haskell,icon=,fp=PowerShell
New-Item -Path projects -Name "guessing_game" -ItemType "Directory"
Set-Location projects/guessing_game
New-Item -Path . -Name "main.cxx" -ItemType "File"
New-Item -Path . -Name "CMakeLists.txt" -ItemType "File"
```

```haskell,icon=,fp=CommandPrompt
mkdir guessing_game
cd ~/projects/guessing_game
echo. > main.cxx
echo. > CMakeLists.txt
```

Our `main.cxx` file can just be an empty `main()` function for now and our
`CMakeLists.txt` is basically the same as in "Hello, World!" with only some input values
changed to reflect this mini-project.

```cpp,icon=%cplusplus,fp=main.cxx
auto main() -> int {
    return 0;
}
```

```haskell,icon=%cmake,fp=CMakeLists.txt
{{#include CMakeLists.txt}}
```

## Processing a Guess

First we will need to we need to ask the user for input, process that input and ensure it
is in a form we expected. To start we'll simply take in the users guess and return it to
them.

```cpp,icon=%cplusplus,fp=main.cxx
#include <iostream>
#include <string>

auto main() -> int {
    std::cout << "Guessing Game!\n";
    std::cout << "Please input your guess (1..100): ";

    auto guess = std::string{};
    std::getline(std::cin, guess);

    std::cout << "You guessed: " << guess << std::endl;

    return 0;
}
```

Let's briefly go over the new concepts introduced above. First we have included a new
header `<string>`[^1] which contains the definitions the type `std::string`[^2] and
supported functions.

```cpp,icon=%cplusplus,fp=main.cxx:2
#include <string>
```

We then prompt the user with the name of the game as well as request input from the user
using the output stream `std::cout`, which we covered in Chapter 1.

```cpp,icon=%cplusplus,fp=main.cxx:5:6
    std::cout << "Guessing Game!\n";
    std::cout << "Please input your guess (1..100): ";
```

### Storing Data with Variables

Next, we construct a new *variable* to store the users input in.

```cpp,icon=%cplusplus,fp=main.cxx:8
    auto guess = std::string{};
```

Now this is where things begin to get interesting. This line is an assignment expression
which is used to bind a value to a variable. Here is another!

```cpp,icon=%cplusplus
auto boxes = 7;
```

> [!IMPORTANT]
> Notice the lack of a type after the `=` like when we initialized a `std::string`. This
> is because we have initialize `boxes` with a `int` literal and thus the type is
> inferred. If you wanted to you could explicitly specify the type as such:
>
> ```cpp,icon=%cplusplus
> auto boxes = int{7};
> ```

In C++ variables are mutable by default which means we are allowed to change it's value.
This concept will be discussed more in
[Chapter 3 | Variables and Mutability](/ch03-common-concepts/vars-mut.md). To make a
variable constant ie. its value cannot change once it is set, we use the `const` keyword
after/before `auto` (I choose after).

```cpp,icon=%cplusplus
const auto boxes = 7;  // constant
auto crates = 4;  // mutable
```

> [!TIP]
> The `//` syntax indicates a comment that continues until the end of the line.
> Everything in a comment is ignored by C++. You will learn more about them in
> [Chapter 3 | Comments](/ch03-common-concepts/comments.md).

In this case of our variable `guess` in our guessing game program, we have (default)
constructed a temporary value with the type `std::string` which we then bind to the
variable named `guess` using the `=` operator. We have also used `auto` to allow the
compiler to deduce the type that the variable `guess` should have. We could have written
explicitly the type on the left-hand-side instead of `auto` like the example below but
this would be more verbose as we have to express the type twice. It also means that if
we change the type on the RHS we must also change it on the LHS but with `auto` the
compiler will do that for us!

```cpp,icon=%cplusplus,fp=main.cxx:8
    std::string input = std::string{}; 
```

> [!TIP]
> When constructing our `std::string` we have used what is known as brace initialization.
> This is a modern (C++11) method for initializing objects and is used to avoid the
> narrowing of types. The empty `{}` indicates we a constructing the object in its
> default state, which for `std::string` is an empty string.

### Receiving User Input

There are a few different ways for handling user input from the terminal in C++. For this
program we have used the `std::getline()`[^3].

```cpp,icon=%cplusplus,fp=main.cxx:9
    std::getline(std::cin, input);
```

This function extracts all characters from the first argument which is of type
`std::basic_istream<>`[^4]. In this case, the input stream is `std::cin`[^5]. Once no
characters remain in the stream or the designated deliminator is encountered; which
defaults to `'\n'` (third argument), the extracted characters are then written to the
second argument which is a *reference* to a string of the same underlying character type.
References allow functions to read and/or modify data passed to them and have the effects
reflected on the callers side. We'll cover references and ownership in C++ during
[Chapter 4](/ch04-ownership/ownership.md). In effect this function reads an entire line
and copies the characters into a string.

## Printing with Output Streams

As we first saw in ["Hello, world!"](hello-world.md) we can output text using
`std::cout`[^6] global object using the operator `<<`[^7]. You may be wondering why the
"unique" syntax for out has been chosen for printing? This is because the
Input/Output[^8] library is more generic than just a printing facility. As the name
suggests it is a library for manipulating and using Input/Output (IO) streams. Streams
can be thought of as a pipeline between two endpoints eg. a program and the terminal
screen where data can be pushed from one end (the program) and extracted at the other end
(the terminal screen). The C++ IO library uses streams to model how data is transferred
between various endpoints like a program, the terminal screen, files etc. with the `<<`
and `>>` operators being used to perform formatted IO ie. push formatted data to and/or
extract formatted data from a stream respectively. These facilities were then used to
wrap low level IO handles such as `stdin`, `stdout` and `stderr`; which are used to print
and take user input, in global stream objects eg. `std::cin`, `std::cout` and `std::cerr`
which meant they could be manipulated using the same API and functionality provided by
the standard C++ IO library.

> [!NOTE]
> The C++23 Standard includes a new header `<print>`[^9] with functions like
> `std::println()` which use the C++20 formatting library[^10] which make printing much
> more intuitive and faster. This library was directly inspired by the `{fmt}` library.

If you are familiar with other languages you may be wondering why `<<` is used to push to
a streams as this operator is normally used for the left bit shifting[^11] operations.
We are able to use the `<<` operator because it has been overloaded. Essentially this
means the functionality of `<<` has been changed and customized for particular types.
Within the C++ standard library, `<<` has been overloaded to support taking a reference
to a `std::basic_ostream<>`[^12] object as the left argument; ie. the type of
`std::cout`, and various builtin C++ types and library types from the standard library as
the right argument eg. `int` and `std::string`, which allows the `<<` syntax to be used
with many different types already in C++. Overloading will be covered in more detail in
[Chapter 3 | Functions](/ch03-common-concepts/functions.md).

In this program we have seen that we can chain the calls to `<<`.

```cpp,icon=%cplusplus,fp=main.cxx:11
    std::cout << "You guessed: " << input << std::endl;
```

This is because each call to `<<` returns a reference to the same stream passed as the
left argument, allowing you to make subsequent calls to `<<` one after another. This can
make it easier to build up pipelines to and from streams as we can create arbitrarily
long chains.

Finally, you may notice the `std::endl` at the end of the chain. This is a
*stream manipulator*. Stream manipulators are used to modify the stream to support
different kinds of formatting. In this case, `std::endl` simply appends a `'\n'` to the
stream and flushes the underlying buffer. So why not just use `'\n'`? Well, you should.
Using `std::endl` repeatedly just to add newlines will dramatically degrade performance
because repeatedly flushing the internal buffer forces the OS the immediately display the
characters instead of allowing for the output to buffer ie. reach a large enough size to
warrant making a system call. `std::endl` should only be used when you want to flush the
streams buffer and place a newline eg. at the end of a program, otherwise use an explicit
`'\n'`.

## Generating a Secret Number

Now we want some way to generate a secret number that the player will try to guess. We
also want the number to be different each time so the game is more fun but we'll keep it
between 1 and 100 to ensure it is not too difficult. To generate our secret number we'll
use a random number generator. The C++ standard library contains a header `<random>`[^13]
which contains a bunch of facilities for generating random numbers. Update your
`main.cxx` file according to the snippet below.

```cpp,icon=%cplusplus,fp=main.cxx
#include <iostream>
#include <random>
#include <string>

auto main() -> int {
    std::cout << "Guessing Game!\n";

    auto rd = std::random_device{};
    auto gen = std::mt19937{rd()};
    auto distrib = std::uniform_int_distribution<unsigned>{1u, 100u};
    const auto secret_number = distrib(gen);

    std::cout << "The secret number is: " << secret_number << '\n';
    std::cout << "Please input your guess: ";

    auto input = std::string {};
    std::getline(std::cin, input);

    std::cout << "You guessed: " << input << std::endl;

    return 0;
}
```

First we include the new header `<random>`[^13] so we can access the (pseudo-) random
number generation types. Next we add the lines

```cpp,icon=%cplusplus,fp=main.cxx:8:10
    auto rd = std::random_device{};
    auto gen = std::mt19937{rd()};
    auto distrib = std::uniform_int_distribution<unsigned>{1u, 100u};
```

The first line (default) constructs a new `std::random_device`[^14]. This is a uniformly
distributed, non-deterministic number generator. While we could generate a random number
from simply calling `rd`, this is considered bad practice as `std::random_device`[^14]
performance degrades with use due to its entropy pool being used up. For this reason we
simply use it to seed a proper Pseudo-Random Number Generator (PRNG) such as
`std::mt19937`[^15] which is what we do on the second line. Finally we construct a
`std::uniform_int_distribution<>`[^16] which is used to uniformly generate integers
between the two provided bounds.

This sets up our random number generator. To obtain a random number we can call the
distribution object, passing in the generator and returning a new random value.

```cpp,icon=%cplusplus,fp=main.cxx:11
    const auto secret_number = distrib(gen);
```

## Comparing the Guess to the Secret Number

Next we want to compare our players guess to the secret number.

```cpp,icon=%cplusplus,fp=main.cxx
#include <compare>
#include <iostream>
#include <random>
#include <string>

auto main() -> int {
    std::cout << "Guessing Game!\n";

    auto rd = std::random_device{};
    auto gen = std::mt19937{rd()};
    auto distrib = std::uniform_int_distribution<unsigned>{1u, 100u};
    const auto secret_number = distrib(gen);

    std::cout << "The secret number is: " << secret_number << '\n';
    std::cout << "Please input your guess: ";
    auto input = std::string{};
    std::getline(std::cin, input);
    auto guess = std::stoi(input);

    if (guess == secret_number) {
        std::cout << "You guessed correctly!\n";
        break;
    } else if (guess < secret_number) {
        std::cout << "Too small!\n";
    } else if (guess > secret_number) {
        std::cout << "Too big!\n";
    }

    return 0;
}
```

Before we are able to compare the players input to our secret number we must first
convert the raw input into a number so they can be compared.

```cpp,icon=%cplusplus,fp=main.cxx:17
    auto guess = std::stoi(input);
```

C++ offers a few functions for converting strings into numbers which all start with the
prefix `std::sto*`[^17] meaning 'string-to' followed by a designator for the conversion
type. Because we want to parse our input as a plain `int` we can use `std::stoi()`.


Next we compare the `guess` to our `secret_number`. We use `if` and `else if`[^18]
branches to test the ordering of the two numbers and run a separate piece of code
depending on which condition is true.

```cpp,icon=%cplusplus,fp=main.cxx:19:26
    if (guess == secret_number) {
        std::cout << "You guessed correctly!\n";
        break;
    } else if (guess < secret_number) {
        std::cout << "Too small!\n";
    } else if (guess > secret_number) {
        std::cout << "Too big!\n";
    }
```

## Handling Parsing Errors with Exceptions

Our game is coming along quite nicely but it has one fundamental flaw. What happens if we
give our game the input "abcd34" or "38574876546456476745"? We get the following two
errors and our game crashes!

```sh,icon=%gnubash,fp=Shell
# input: "abcd34"
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
[1]    27989 IOT instruction  ./build/.../guessing_game

# input: "38574876546456476745"
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi
[1]    1513 IOT instruction  ./build/.../guessing_game
```

This is not ideal as it gives no way for the system to recover from the error and let the
user try again. How do we fix this? Well notice in the error message it states that an
instance of (either) `std::invalid_argument`[^19] (or) `std::out_of_range`[^20] was
thrown. What are these objects? These are known as exceptions. They are a special object
used to indicate that an *exceptional event* has occurred. These are pathways in our
program that we do not expect to occur but might and exceptions allow us to recover the
system without fully crashing. This is a useful mechanism for allowing systems to remain
online and perform self recovery if an error does occur.

Before we look at how to handle thrown exceptions we'll first discuss what each of these
exceptions mean in the context of `std::stoi()`[^17]. `std::invalid_argument`[^19] is
used to indicate that a general parsing error has occurred due to a bad input ie.
prefixing the input with letters eg. "abcd34". The exception `std::out_of_range`[^20] is
used to indicate that the input value cannot fit into the conversion type. For example if
"38574876546456476745" is passed to `std::stoi()`[^17] we have this exception thrown
because the max value that can be fit inside an `int` is `2147483647` which is much
smaller than `38574876546456476745`.

> [!TIP]
> The `std::sto*` function family will 'successfully' parse inputs like "34abc" as they
> extract the number from the front and will discard the rest.

### Catching Exceptions

So how do we handle an exception that has been thrown? We can use a `try-catch` block.
When there is a chance for something to fail we place the potentially failing code
in a `try` block[^21]. After a try block we put one or more `catch` blocks[^22]. These
are used to define the exception handling pathway for that particular exception.

```cpp,icon=%cplusplus,fp=main.cxx
// --snip--
#include <exception>
#include <iomanip>
$#include <iostream>
$#include <random>
$#include <string>

auto main() -> int {
    // --snip--
$    std::cout << "Guessing Game!\n";
$
$    auto rd = std::random_device{};
$    auto gen = std::mt19937{rd()};
$    auto distrib = std::uniform_int_distribution{1, 100};
$    const auto secret_number = distrib(gen);
$
$    std::cout << "The secret number is: " << secret_number << '\n';
$    std::cout << "Please input your guess: ";
$    auto input = std::string{};
$    std::getline(std::cin, input);
$
    auto guess = int{0};

    try {
        guess = std::stoi(input);
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid input " << std::quoted(input) << "!\n";
        std::exit(0);
    } catch (const std::out_of_range&) {
        std::cerr << "Input " << std::quoted(input) << " is too large!" << '\n';
        std::exit(0);
    }

    // --snip--
$
$    if (guess == secret_number) {
$        std::cout << "You guessed correctly!\n";
$        break;
$    } else if (guess < secret_number) {
$        std::cout << "Too small!\n";
$    } else if (guess > secret_number) {
$        std::cout << "Too big!\n";
$    }
$
$    return 0;
}
```

> [!WARNING]
> While `try-catch` block's do model a form of control flow they are very different to
> regular control flow mechanisms like `if` statements. You should not be used
> `try-catch` blocks to control the regular/expected execution pathway of a program as
> they are much slower nor should you throw exceptions in order to jump out to a
> particular scope. Exceptions should only be used to indicate that a recoverable error
> has occurred and `try-catch` blocks being used to handle recovering from this event eg.
> giving any allocated resources back to the OS, as such exceptions should be used only
> in *exceptional* (pun most definitely intended) cases and when appropriate for your
> domain (as they can be undesirable in many situations). The main purpose of showing
> exceptions now is to demonstrate how to ***handle*** them not throw your own.

## Allowing Multiple Guesses with a Loop

Now that we correctly handle the exceptional cases of parsing our player's input we can
look at making the game more interactive. Only having one guess doesn't make our game
very fun. Lets allow the player to make multiple guesses by introducing a loop! We will
want this loop to run forever with explicit mechanisms for exiting the loop. We can use
a `while` loop with its condition simply being `true`. This will create our infinite
loop. But how and when do we exit the loop? We want the loop to be broken when the player
guesses the correct number. We can do this by introducing a `break` statement in the
first `if` branch when comparing the player's input to the secret number. `break` is used
to break out of the enclosing loop block. We also need the program to run the next loop
iteration if an exception occurs, skipping the comparisons. We can do this with a
`continue` statement within each of the `catch` blocks to skip to the next iteration.
Finally, be sure to move the prompt output and player input logic into the loop so they
are called each iteration.

```cpp,icon=%cplusplus
// --snip--
$#include <exception>
$#include <iomanip>
$#include <iostream>
$#include <random>
$#include <string>

auto main() -> int {
    // --snip--
$    std::cout << "Guessing Game!\n";
$
$    auto rd = std::random_device{};
$    auto gen = std::mt19937{rd()};
$    auto distrib = std::uniform_int_distribution{1, 100};
$    const auto secret_number = distrib(gen);
$
$    std::cout << "The secret number is: " << secret_number << '\n';
$    auto input = std::string{};
$    auto guess = int{0};
$

    while (true) {

        // --snip--
$        std::cout << "Please input your guess: ";
$        std::getline(std::cin, input);
$
        try {
            guess = std::stoi(input);
        } catch (const std::invalid_argument&) {
            std::cerr << "Invalid input " << std::quoted(input) << "!\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cerr << "Input " << std::quoted(input) << " is too large!" << '\n';
            continue;
        }

        if (guess == secret_number) {
            std::cout << "You guessed correctly!\n";
            break;
        } else if (guess < secret_number) {
            std::cout << "Too small!\n";
        } else if (guess > secret_number) {
            std::cout << "Too big!\n";
        }
    }
$
$    return 0;
}
```

Fantastic! With a final tweak we have finished the guessing game. Our game is still
printing the secret number! We can fix this by deleting the line. The final code is
available below.

```cpp,icon=%cplusplus
{{#include main_cxx_17.cxx}}
```

## Summary

This project offered a hands on way to learn many of C++ features: `auto`, variables,
functions, `if` statements, exception handling and loops! In the upcoming chapters you 
will delve deeper into these concepts as well as explore many new ones. See you there!

[^1]: <https://en.cppreference.com/w/cpp/header/string>
[^2]: <https://en.cppreference.com/w/cpp/string/basic_string>
[^3]: <https://en.cppreference.com/w/cpp/string/basic_string/getline>
[^4]: <https://en.cppreference.com/w/cpp/io/basic_istream>
[^5]: <https://en.cppreference.com/w/cpp/io/cin>
[^6]: <https://en.cppreference.com/w/cpp/io/cout>
[^7]: <https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt>
[^8]: <https://en.cppreference.com/w/cpp/io>
[^9]: <https://en.cppreference.com/w/cpp/header/print>
[^10]: <https://en.cppreference.com/w/cpp/utility/format>
[^11]: <https://en.wikipedia.org/wiki/Bitwise_operation#Bit_shifts>
[^12]: <https://en.cppreference.com/w/cpp/io/basic_ostream>
[^13]: <https://en.cppreference.com/w/cpp/numeric/random>
[^14]: <https://en.cppreference.com/w/cpp/numeric/random/random_device>
[^15]: <https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine>
[^16]: <https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution>
[^17]: <https://en.cppreference.com/w/cpp/string/basic_string/stol>
[^18]: <https://en.cppreference.com/w/cpp/language/if>
[^19]: <https://en.cppreference.com/w/cpp/error/invalid_argument>
[^20]: <https://en.cppreference.com/w/cpp/error/out_of_range>
[^21]: <https://en.cppreference.com/w/cpp/language/try.html>
[^22]: <https://en.cppreference.com/w/cpp/language/catch.html>
