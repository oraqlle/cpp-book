#include <compare>
#include <exception>
#include <iomanip>
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
    auto input = std::string {};
    auto guess = int {};

    while (true) {
        std::cout << "Please input your guess: ";
        std::getline(std::cin, input);

        try {
            guess = std::stoi(input);
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input " << std::quoted(input) << "!\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "Input " << std::quoted(input) << " is too large!" << '\n';
            continue;
        }

        if (const auto cmp = guess <=> secret_number; std::is_eq(cmp)) {
            std::cout << "You guessed correctly!\n";
            break;
        } else if (std::is_lt(cmp)) {
            std::cout << "Too small!\n";
        } else if (std::is_gt(cmp)) {
            std::cout << "Too big!\n";
        }
    }

    return 0;
}
