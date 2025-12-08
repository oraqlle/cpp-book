# Project: Guessing Game

```admonish warning
🚧 Page Under Construction! 🏗️
```

Let us jump straight into C++ by developing a project together! This will help expose you to some common concepts from C++ and how they are used in an actual program. You'll learn how create variables, control the flow of your program, take in user input, create functions and more! These concepts will be explored in more detail in future chapters while this one will focus on the fundamentals.

We'll be implementing a simple number guessing game. The program will generate a random integer between 1 and 100 (inclusive). It will then prompt the user to type in a guess. After the guess is entered the program will indicate whether the guess was too high or to low or a congratulatory message if the user got it right and exit the program.

## Setting Up a New Project

To begin, create a new directory in your `projects/` directory called `guessing_game` and enter it.

```sh
$ mkdir guessing_game
$ cd guessing_game
```

As usual, we'll need to create the files `main.cxx`, `CMakeLists.txt` and `CMakePresets.json`. Our `main.cxx` file can just be an empty `main()` function like [Listing 2-1](#listing2-1) and for our `CMakeLists.txt` file we must specify a minimum project configuration detailed in [Listing2-2](#listing2-2). As for our `CMakePresets.json` file, we can use the either one from Chapter 1; [Listing 1-3](hello-cmake.md#listing1-3) or [Listing 1-4](hello-cmake.md#listing1-4).

<span id="listing2-1" class="caption">Listing 2-1: Empty `main()` function in `main.cxx`.</span>

```cpp
auto main() -> int {
    return 0;
}
```

<span id="listing2-2" class="caption">Listing 2-2: Simple 'CMakeLists.txt' for guessing game executable.</span>

```cmake
{{#include examples/guessing_game/CMakeLists.txt}}
```

## Processing a Guess

First we will need to we need to ask the user for input, process that input and ensure it is in a form we expected. To start we'll simply take in the users guess and return it to them. [Listing2-3](#listing2-3) shows the starting code.

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

Let's briefly go over the new concepts introduced in [Listing 2-3](#listing2-3). We have included a new header `<string>` which contains the definitions the type `std::string` and supported functions.

```cpp
#include <string>
```

We then prompt the user with the name of the game as well as request input from the user using the output stream `std::cout`, which we covered in Chapter 1.

```cpp
    std::cout << "Guessing Game!\n";
    std::cout << "Please input your guess (1..100): ";
```

### Storing Data with Variables

Next, we construct a new *variable* to store the users input in.

```cpp
    auto guess = std::string {};
```

Now this is where things begin to get interesting. This line is an assignment expression which is used to bind a value to a variable. Here is another!

```cpp
auto boxes = int { 7 };
```

In C++ variables are mutable by default which means we are allowed to change it's value. THis concept will be discussed more in Chapter 3's [Variables and Mutability](../common-concepts/vars-mut.md). To make a variable constant ie. its value cannot change once it is set, we use the `const` keyword before `auto`.

```cpp
const auto boxes = int { 7 };  // constant
auto crates = int { 4 };  // mutable
```

```admonish tip
The `//` syntax indicates a comment that continues until the end of the line. Everything in a comment is ignored by C++.
```

In this case of our variable `guess` in our guessing game program, we have (default) constructed a temporary value with the type `std::string` which we then bind to the variable named `guess` using the `=` operator. We have also used `auto` to allow the compiler to deduce the type that the variable `guess` should have. We could have written explicitly the type on the left-hand-side instead of `auto` like the example below but this would be more verbose as we have to express the type twice. It also means that if we change the type on the RHS we must also change it on the LHS but with `auto` the compiler will do that for us!

```cpp
    std::string guess = std::string {}; 
```

```admonish tip
When constructing our `std::string` we have used what is known as brace. This is a safer variant of regular construction (which uses parenthesis `()`) as it prevents narrowing which causes the bit representation of some types to be truncated. We also have default constructed our `std::string` which in this case means the `std::string` is constructed as an empty string not as an invalid object.
```

### Receiving User Input

~

## Additional Challenge

<!-- Add `{fmt}` (or other) library using vcpkg. -->
