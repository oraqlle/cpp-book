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

    const auto secret_number = distrib(gen);

    std::cout << "The secret number is: " << secret_number << '\n';

    std::cout << "Please input your guess: ";

    auto input = std::string {};

    std::getline(std::cin, input);

    auto guess = std::stoi(input);

    if (const auto cmp = guess <=> secret_number; std::is_eq(cmp)) {
        std::cout << "You guessed correctly!\n";
    } else if (std::is_lt(cmp)) {
        std::cout << "Too small!\n";
    } else if (std::is_gt(cmp)) {
        std::cout << "Too big!\n";
    }

    return 0;
}
