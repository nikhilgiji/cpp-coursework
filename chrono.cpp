#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 3, 7, 4, 6, 8, 0};

    // Start timing
    auto start = std::chrono::steady_clock::now();

    // Perform sort
    std::sort(numbers.begin(), numbers.end());

    // End timing
    auto end = std::chrono::steady_clock::now();

    // Calculate duration
    std::chrono::duration<double, std::micro> duration = end - start;

    // Output sorted result
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nTime taken to sort: " << duration.count() << " microseconds\n";

    return 0;
}