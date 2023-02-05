#include <iostream>
#include <memory>

#include "Histogram.h"
#include "Histogram.cpp"
#include "histogramBase.h"
#include "RandomEintegerGenerator.h"
#include "RandomEintegerGenerator.cpp"
#include "Log.h"

const int NUM_OF_SAMPLES = 5;

// For testing if the project works as it is supposed to
int main()
{
    // Create a logger object
    std::unique_ptr<Logger> log = std::make_unique<Logger>();

    // Create a histogram object
    Histogram hist(std::move(log));

    // Add random values to the histogram
    RandomEintegerGenerator giveRandomNumber;
    for (int i{}; i < NUM_OF_SAMPLES; ++i)
    {
        Hist::EInteger randomNum = giveRandomNumber();
        hist.add(randomNum);
    }

    // Print the mode, min and max
    std::cout << "The mode of the histogram is: " << hist.getMode() << std::endl;
    std::cout << "The min value of the histogram is: " << hist.getMinValue() << std::endl;
    std::cout << "The max value of the histogram is: " << hist.getMaxValue() << std::endl;

    return 0;
}