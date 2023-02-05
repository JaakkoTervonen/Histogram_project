#include <random>

#include "RandomEintegerGenerator.h"

Hist::EInteger RandomEintegerGenerator::operator()()
{
    Hist::EInteger value;
    // Seed the random number generator
    std::mt19937 rng(std::random_device{}());

    // Create a uniform integer distribution [0, 4]
    std::uniform_int_distribution<int> dist(0, 4);

    // Generate random integer from above distribution
    int num = dist(rng);

    // Find EInteger corresponding to random integer
    switch (num)
    {
    case 0:
        value = Hist::EInteger::Zero;
        break;
    case 1:
        value = Hist::EInteger::One;
        break;
    case 2:
        value = Hist::EInteger::Two;
        break;
    case 3:
        value = Hist::EInteger::Three;
        break;
    case 4:
        value = Hist::EInteger::Four;
        break;
    }

    return value;
}
