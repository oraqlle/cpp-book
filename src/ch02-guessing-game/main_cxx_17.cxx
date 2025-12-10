#include <exception>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

auto main() -> int {
    std::cout << "Guessing Game!\n";

    auto rd = std::random_device{};
    auto gen = std::mt19937{ rd() };
    auto distrib = std::uniform_int_distribution{ 1, 100 };

    const auto secret_number = distrib(gen);
    auto input = std::string{};
    auto guess = int{0};

    while (true) {
        std::cout << "Please input your guess: ";
        std::getline(std::cin, input);

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

    return 0;
}
