#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "Contact: user@example.com";
    std::regex email_pattern(R"(\w+@\w+\.\w+)");
    std::smatch result;

    // Search
    if (std::regex_search(text, result, email_pattern)) {
        std::cout << "Found: " << result[0] << "\n";
    }

    // Replace
    std::string replaced = std::regex_replace(text, email_pattern, "[hidden]");
    std::cout << "After replacement: " << replaced << "\n";
}