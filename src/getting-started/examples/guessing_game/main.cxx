#include <iostream>
#include <string>

auto main() -> int
{
    std::cout << "Guessing Game!\n";
    std::cout << "Please input your guess: ";

    auto guess = std::string {};
    std::getline(std::cin, guess);
    std::cout << "You guessed: " << guess << std::endl;

    return 0;
}
