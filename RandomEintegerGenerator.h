#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "histogramBase.h"

class RandomEintegerGenerator : public Hist::RandomEintegerGeneratorBase
{
public:
    RandomEintegerGenerator() = default;
    ~RandomEintegerGenerator() = default;
    /// @brief Generates random EIntegers
    /// @return Hist::EInteger
    virtual Hist::EInteger operator()() override;
};

#endif