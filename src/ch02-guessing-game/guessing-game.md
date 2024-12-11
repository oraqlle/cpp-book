# Project: Guessing Game

```admonish warning
🚧 Page Under Construction! 🏗️
```

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
enter it.

```sh
$ mkdir guessing_game
$ cd guessing_game
```

As usual, we'll need to create the files `main.cxx`, `CMakeLists.txt` and
`CMakePresets.json`. Our `main.cxx` file can just be an empty `main()` function like
[Listing 2-1](#listing2-1) and for our `CMakeLists.txt` file we must specify a minimum
project configuration detailed in [Listing2-2](#listing2-2). As for our
`CMakePresets.json` file, we can use the either one from Chapter 1;
[Listing 1-3](hello-cmake.md#listing1-3) or [Listing 1-4](hello-cmake.md#listing1-4).

<span id="listing2-1" class="caption">Listing 2-1: Empty `main()` function in `main.cxx`.</span>

```cpp
auto main() -> int {
    return 0;
}
```

<span id="listing2-2" class="caption">Listing 2-2: Simple 'CMakeLists.txt' for guessing game executable.</span>

```haskell
{{#include CMakeLists.txt}}
```

## Processing a Guess

First we will need to we need to ask the user for input, process that input and ensure it
is in a form we expected. To start we'll simply take in the users guess and return it to
them. [Listing2-3](#listing2-3) shows the starting code.

<span id="listing2-3" class="caption">Listing 2-3: Code for obtaining an input from the user and printing it.</span>

```cpp
#include <iostream>
#include <string>

auto main() -> int
{
    std::cout << "Guessing Game!\n";

    std::cout << "Please input your guess (1..100): ";

    auto guess = std::string {};

    std::getline(std::cin, guess);

    std::cout << "You guessed: " << guess << std::endl;

    return 0;
}
```

Let's briefly go over the new concepts introduced in [Listing 2-3](#listing2-3). We have
included a new header [`<string>`](https://en.cppreference.com/w/cpp/header/string) which
contains the definitions the type [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string)
and supported functions.

```cpp
#include <string>
```

We then prompt the user with the name of the game as well as request input from the user
using the output stream `std::cout`, which we covered in Chapter 1.

```cpp
    std::cout << "Guessing Game!\n";

    std::cout << "Please input your guess (1..100): ";
```

### Storing Data with Variables

Next, we construct a new *variable* to store the users input in.

```cpp
    auto guess = std::string {};
```

Now this is where things begin to get interesting. This line is an assignment expression
which is used to bind a value to a variable. Here is another!

```cpp
auto boxes = 7;
```

```admonish note
Note the lack of a type after the `=`. This is because we can initialize `boxes` with a
integer literal and thus a type is not needed.
```

In C++ variables are mutable by default which means we are allowed to change it's value.
This concept will be discussed more in [Chapter 3 | Variables and Mutability](../common-concepts/vars-mut.md).
To make a variable constant ie. its value cannot change once it is set, we use the
`const` keyword after/before `auto` (I choose after).

```cpp
auto const boxes = 7;  // constant
auto crates = 4;  // mutable
```

```admonish tip
The `//` syntax indicates a comment that continues until the end of the line. Everything
in a comment is ignored by C++. You will learn more about them in
[Chapter 3 | Comments](../common-concepts/comments.md).
```

In this case of our variable `guess` in our guessing game program, we have (default)
constructed a temporary value with the type `std::string` which we then bind to the
variable named `guess` using the `=` operator. We have also used `auto` to allow the
compiler to deduce the type that the variable `guess` should have. We could have written
explicitly the type on the left-hand-side instead of `auto` like the example below but
this would be more verbose as we have to express the type twice. It also means that if
we change the type on the RHS we must also change it on the LHS but with `auto` the
compiler will do that for us!

```cpp
    std::string input = std::string {}; 
```

```admonish tip
When constructing our `std::string` we have used what is known as brace. This is a safer
variant of regular construction (which uses parenthesis `()`) as it prevents narrowing
which causes the bit representation of some types to be truncated. We also have default
constructed our `std::string` which in this case means the `std::string` is constructed
as an empty string not as an invalid object.
```

### Receiving User Input

There are a few different ways for handling user input from the terminal in C++. For this
program we have used the
[`std::getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline).

```cpp
    std::getline(std::cin, input);
```

This function extracts all characters from the first argument which is of type
[`std::basic_istream<>`](https://en.cppreference.com/w/cpp/io/basic_istream). In this
case, the input stream is [`std::cin`](https://en.cppreference.com/w/cpp/io/cin). Once no
characters remain in the stream or the designated deliminator is encountered; which
defaults to `'\n'` (third argument), the extracted characters are then written to the
second argument which is a *reference* to a string of the same underlying character type.
References allow functions to read and/or modify data passed to them and have the effects
reflected on the callers side. We'll cover references and ownership in C++ during
[Chapter 4](../ownership/ownership.md). In effect this function reads an entire line and
copies the characters into a string.

## Printing with Output Streams

As we first saw in ["Hello, world!"](hello-world.md) we can output text using
[`std::cout`](https://en.cppreference.com/w/cpp/io/couthttps://en.cppreference.com/w/cpp/io/cout)
global object using the operator [`<<`](https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt).
You may be wondering why the "unique" syntax for out has been chosen for printing? This
is because the [Input/Output](https://en.cppreference.com/w/cpp/io) library is more
generic than just a printing facility. As the name suggests it is a library for
manipulating and using Input/Output (IO) streams. Streams can be thought of as a pipeline
between two endpoints eg. a program and the terminal screen where data can be pushed from
one end (the program) and extracted at the other end (the terminal screen). The C++ IO
library uses streams to model how data is transferred between various endpoints like a
program, the terminal screen, files etc. with the `<<` and `>>` operators being used to
perform formatted IO ie. push formatted data to and/or extract formatted data from a
stream respectively. These facilities were then used to wrap low level IO handles such as
`stdin`, `stdout` and `stderr`; which are used to print and take user input, in global
stream objects eg. `std::cin`, `std::cout` and `std::cerr` which meant they could be
manipulated using the same API and functionality provided by the standard C++ IO library.

```admonish note
The C++23 Standard includes a new header [`<print>`](https://en.cppreference.com/w/cpp/header/print)
with functions like `std::println()` which use the C++20
[formatting library](https://en.cppreference.com/w/cpp/utility/format) which make
printing much more intuitive and faster. This library was directly inspired by the
`{fmt}` library.
```

If you are familiar with other languages you may be wondering why `<<` is used to push to
a streams as this operator is normally used for the
[left bit shifting](https://en.wikipedia.org/wiki/Bitwise_operation#Bit_shifts)
operations. We are able to use the `<<` operator because it has been overloaded.
Essentially this means the functionality of `<<` has been changed and customized for
particular types. Within the C++ standard library, `<<` has been overloaded to support
taking a reference to a [`std::basic_ostream<>`](https://en.cppreference.com/w/cpp/io/basic_ostream)
object as the left argument; ie. the type of `std::cout`, and various builtin C++ types
and library types from the standard library as the right argument eg. `int` and
`std::string`, which allows the `<<` syntax to be used with many different types already
in C++. Overloading will be covered in more detail in
[Chapter 3 | Functions](../common-concepts/functions.md).

In this program we have seen that we can chain the calls to `<<`.

```cpp
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
use a random number generator. The C++ standard library contains a header
[`<random>`](https://en.cppreference.com/w/cpp/numeric/random) which contains a bunch of
facilities for generating random numbers. Update your `main.cxx` file according to
[Listing 2-4](#listing2-4).

<span id="listing2-4" class="caption">Listing 2-4: Added code to generate a random number.</span>

```cpp
#include <iostream>
#include <random>
#include <string>

auto main() -> int
{
    std::cout << "Guessing Game!\n";

    auto rd = std::random_device {};
    auto gen = std::mt19937 { rd() };
    auto distrib = std::uniform_int_distribution<unsigned> { 1u, 100u };

    auto const secret_number = distrib(gen);

    std::cout << "The secret number is: " << secret_number << '\n';

    std::cout << "Please input your guess: ";

    auto input = std::string {};

    std::getline(std::cin, input);

    std::cout << "You guessed: " << input << std::endl;

    return 0;
}
```

First we include the new header `<random>` so we can access the (pseudo-) random number
generation types. Next we add the lines

```cpp
    auto rd = std::random_device {};
    auto gen = std::mt19937 { rd() };
    auto distrib = std::uniform_int_distribution { 1, 100 };
```

The first line (default) constructs a new
[`std::random_device`](https://en.cppreference.com/w/cpp/numeric/random/random_device).
This is a uniformly distributed, non-deterministic number generator. While we could
generate a random number from simply calling `rd`, this is considered bad practice as
`std::random_device` performance  degrades with use due to its entropy pool being used
up. For this reason we simply use it to seed a proper Pseudo-Random Number Generator
(PRNG) such as [`std::mt19937`](https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine)
which is what we do on the second line. Finally we construct a
[`std::uniform_int_distribution<>`](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
which is used to uniformly generate integers between the two provided bounds.

This sets up our random number generator. To obtain a random number we can call the
distribution object, passing in the generator and returning a new random value.

```cpp
    auto const secret_number = distrib(gen);
```

## Comparing the Guess to the Secret Number

Next we want to compare our players guess to the secret number. The updated code can be
seen in [Listing 2-5](#listing2-5).

<span id="listing2-5" class="caption">Listing 2-5: Added code to compare players input to the secret number.</span>

```cpp
#include <compare>
#include <iostream>
#include <random>
#include <string>

auto main() -> int
{
    std::cout << "Guessing Game!\n";

    auto rd = std::random_device {};
    auto gen = std::mt19937 { rd() };
    auto distrib = std::uniform_int_distribution { 1, 100 };

    auto const secret_number = distrib(gen);

    std::cout << "The secret number is: " << secret_number << '\n';

    std::cout << "Please input your guess: ";

    auto input = std::string {};

    std::getline(std::cin, input);

    auto guess = std::stoi(input);

    if (auto const cmp = guess <=> secret_number; std::is_eq(cmp)) {
        std::cout << "You guessed correctly!\n";
    } else if (std::is_lt(cmp)) {
        std::cout << "Too small!\n";
    } else if (std::is_gt(cmp)) {
        std::cout << "Too big!\n";
    }

    return 0;
}
```

Before we are able to compare the players input to our secret number we must first
convert the raw input into a number so they can be compared.

```cpp
    auto guess = std::stoi(input);
```

C++ offers a few functions for converting strings into numbers which all start with the
prefix [`std::sto*`](https://en.cppreference.com/w/cpp/string/basic_string/stol) meaning
'string-to' followed by a designator for the conversion type. Because we want to parse
our input as a plain `int` we can use `std::stoi()`.

Next we compare the `guess` to our `secret_number`. Here we can make use of the spaceship
operator (`<=>`) which allows us to perform a '3 way comparison' which we can then query
with the utility functions
[`std::is_eq`, `std::is_lt`, `std::is_gt` etc.](https://en.cppreference.com/w/cpp/utility/compare/named_comparison_functions).
In this case we create a new object `cmp` and then use these 'named comparison' functions
to check the result. We use
[`if` and `else if`](https://en.cppreference.com/w/cpp/language/if) branches to test the
comparisons result and run a separate piece of code if that branch succeeds.

```cpp
    if (auto const cmp = guess <=> secret_number; std::is_eq(cmp)) {
        std::cout << "You guessed correctly!\n";
    } else if (std::is_lt(cmp)) {
        std::cout << "Too small!\n";
    } else if (std::is_gt(cmp)) {
        std::cout << "Too big!\n";
    }
```

We have also used a initialiser statement in the first `if` branch. This allows us to run
an expression at the start of the `if` branches and store the result in a local variable
(in this case `cmp`) which can only be accessed within the `if` branches. This helps
ensure that `cmp` is not modified or accessed outside the `if` branches it belongs to.

## Handling Parsing Errors with Exceptions

Our game is coming along quite nicely but it has one fundamental flaw. What happens if we
give our game the input "abcd34" or "38574876546456476745"? We get the following two
errors and our game crashes!

```sh
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
instance of (either)
[`std::invalid_argument`](https://en.cppreference.com/w/cpp/error/invalid_argument) (or)
[`std::out_of_range`](https://en.cppreference.com/w/cpp/error/out_of_range) was thrown.
What are these objects? These are known as exceptions. They are a special object used to
indicate that an *exceptional event* has occurred. These are pathways in our program that
we do not expect to occur but might and exceptions allow us to recover the system without
fully crashing. This is a useful mechanism for allowing systems to remain online and
perform self recovery if an error does occur.

Before we look at how to handle thrown exceptions we'll first discuss what each of these
exceptions mean in the context of `std::stoi()`. `std::invalid_argument` is used to
indicate that a general parsing error has occurred due to a bad input ie. prefixing the
input with letters eg. "abcd34". The exception `std::out_of_range` is used to indicate
that the input value cannot fit into the conversion type. For example if
"38574876546456476745" is passed to `std::stoi()` we have this exception thrown because
the max value that can be fit inside an `int` is `2147483647` which is much smaller than
`38574876546456476745`.

```admonish tip
The `std::sto*` function family will 'successfully' parse inputs like "34abc" as they
extract the number from the front and will discard the rest.
```

### Catching Exceptions

So how do we handle an exception that has been thrown? We can use a `try-catch` block.
When there is a chance for something to fail we place the potentially failing code in a
`try` block. After a try block we put one or more `catch` blocks. These are used to
define the exception handling pathway for that particular exception. For our simple
program we can define a `try-catch` block like in [Listing 2-6](#listing2-6).

<span id="listing2-6" class="caption">Listing 2-6: Added exception error handling for `std::stoi` call.</span>

```cpp
$#include <compare>
// --snip--
#include <exception>
#include <iomanip>
$#include <iostream>
$#include <random>
$#include <string>
// --snip--

auto main() -> int
{
$    std::cout << "Guessing Game!\n";
$
$    auto rd = std::random_device {};
$    auto gen = std::mt19937 { rd() };
$    auto distrib = std::uniform_int_distribution { 1, 100 };
$
$    auto const secret_number = distrib(gen);
$
$    std::cout << "The secret number is: " << secret_number << '\n';
$
$    std::cout << "Please input your guess: ";
$
$    auto input = std::string {};
$
$    std::getline(std::cin, input);
$
    // --snip--

    auto guess = int {};

    try {
        guess = std::stoi(input);
    } catch (std::invalid_argument const&) {
        std::cout << "Invalid input " << std::quoted(input) << "!\n";
        std::exit(0);
    } catch (std::out_of_range const&) {
        std::cout << "Input " << std::quoted(input) << " is too large!" << '\n';
        std::exit(0);
    }
$
$    if (auto const cmp = guess <=> secret_number; std::is_eq(cmp)) {
$        std::cout << "You guessed correctly!\n";
$    } else if (std::is_lt(cmp)) {
$        std::cout << "Too small!\n";
$    } else if (std::is_gt(cmp)) {
$        std::cout << "Too big!\n";
$    }
$
$    return 0;

    // --snip--
}
```

```admonish warning
While `try-catch` block's do model a form of control flow they are very different to
regular control flow mechanisms like `if` statements. You should not be used `try-catch`
blocks to control the regular/expected execution pathway of a program as they are much
slower nor should you throw exceptions in order to jump out to a particular scope.
Exceptions should only be used to indicate that a recoverable error has occurred and
`try-catch` blocks being used to handle recovering from this event eg. giving any
allocated resources back to the OS, as such exceptions should be used only in
*exceptional* (pun most definitely intended) cases and when appropriate for your domain
(as they can be undesirable in many situations). The main purpose of showing exceptions
now is to demonstrate how to ***handle*** them not throw your own.
```

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

<span id="listing2-7" class="caption">Listing 2-7: Placed game in a infinite loop to allow player multiple guesses.</span>

```cpp
$#include <compare>
$#include <exception>
$#include <iomanip>
$#include <iostream>
$#include <random>
$#include <string>
$
// --snip--

auto main() -> int
{
$    std::cout << "Guessing Game!\n";
$
$    auto rd = std::random_device {};
$    auto gen = std::mt19937 { rd() };
$    auto distrib = std::uniform_int_distribution { 1, 100 };
$
$    auto const secret_number = distrib(gen);
$
$    std::cout << "The secret number is: " << secret_number << '\n';
$
$    auto input = std::string {};
$
$    auto guess = int {};
$
    // --snip--

    while (true) {
$        std::cout << "Please input your guess: ";
$        std::getline(std::cin, input);
$
        // --snip--

        try {
            guess = std::stoi(input);
        } catch (std::invalid_argument const&) {
            std::cout << "Invalid input " << std::quoted(input) << "!\n";
            continue;
        } catch (std::out_of_range const&) {
            std::cout << "Input " << std::quoted(input) << " is too large!" << '\n';
            continue;
        }

        if (auto const cmp = guess <=> secret_number; std::is_eq(cmp)) {
            std::cout << "You guessed correctly!\n";
            break;
        } else if (std::is_lt(cmp)) {
            std::cout << "Too small!\n";
        } else if (std::is_gt(cmp)) {
            std::cout << "Too big!\n";
        }
    }
$
$    return 0;
}
```

Fantastic! With a final tweak we have finished the guessing game. Our game is still
printing the secret number! We can fix this by deleting the line. The final code is
available in [Listing 2-8](#listing2-8).

<span id="listing2-8" class="caption">Listing 2-8: Final game.</span>

```cpp
{{#include main.cxx}}
```

## Summary

This project offered a hands on way to learn many of C++ features: `auto`, variables,
functions, `if` statements, exception handling and loops! In the upcoming chapters you 
will delve deeper into these concepts as well as explore many new ones. See you there!

<!-- ## Additional Challenge -->

<!-- Add `{fmt}` (or other) library using vcpkg. -->
