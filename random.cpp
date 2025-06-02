#include <iostream>
#include <random>
#include <iomanip>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());  // Common random engine

    // 1. Uniform Int Distribution: values from 1 to 10
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::cout << "Uniform Distribution (1–10): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << uniform_dist(gen) << " ";
    }
    std::cout << "\n";

    // 2. Normal Distribution: mean = 0.0, stddev = 1.0
    std::normal_distribution<double> normal_dist(0.0, 1.0);
    std::cout << "Normal Distribution (mean=0, stddev=1): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << std::fixed << std::setprecision(2) << normal_dist(gen) << " ";
    }
    std::cout << "\n";

    // 3. Poisson Distribution: mean = 4.0
    std::poisson_distribution<int> poisson_dist(4.0);
    std::cout << "Poisson Distribution (mean=4): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << poisson_dist(gen) << " ";
    }
    std::cout << "\n";

    return 0;
}