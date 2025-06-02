#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <chrono>

int main() {
    // Start timing with chrono
    auto start = std::chrono::steady_clock::now();

    // --- RANDOM: Generate a random email-like string ---
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> char_dist(0, 25); // a-z
    std::uniform_int_distribution<> length_dist(5, 10);

    auto random_string = [&](int len) {
        std::string s;
        for (int i = 0; i < len; ++i)
            s += static_cast<char>('a' + char_dist(gen));
        return s;
    };

    std::string email = random_string(length_dist(gen)) + "@" +
                        random_string(length_dist(gen)) + ".com";

    std::cout << "Generated email: " << email << "\n";

    // --- REGEX: Validate the generated email ---
    std::regex email_pattern(R"(\w+@\w+\.\w+)");
    if (std::regex_match(email, email_pattern)) {
        std::cout << "Valid email format ✅\n";
    } else {
        std::cout << "Invalid email format ❌\n";
    }

    // End timing
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;

    std::cout << "Execution time: " << elapsed.count() << " µs\n";

    return 0;
}