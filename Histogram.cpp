#ifndef HISTOGRAM_CPP
#define HISTOGRAM_CPP

#include "Histogram.h"

void Histogram::add(Hist::EInteger value)
{
    int count = m_dataSet[value] + 1;
    m_dataSet[value] = count;
}

Hist::EInteger Histogram::getMode() const
{
    Hist::EInteger nums[]{Hist::EInteger::Zero,
                          Hist::EInteger::One,
                          Hist::EInteger::Two,
                          Hist::EInteger::Three,
                          Hist::EInteger::Four};

    Hist::EInteger mode;
    int modeInt = 0;

    for (Hist::EInteger num : nums)
    {
        if (m_dataSet.count(num) > 0)
        {
            int count = m_dataSet[num];
            if (count > modeInt)
            {
                mode = num;
                modeInt = count;
            }
        }
    }

    return mode;
}

Hist::EInteger Histogram::getMinValue() const
{
    if (m_dataSet.empty())
    {
        throw std::out_of_range("Empty map");
    }
    return m_dataSet.begin()->first;
}

Hist::EInteger Histogram::getMaxValue() const
{
    if (m_dataSet.empty())
    {
        throw std::out_of_range("Empty map");
    }
    return m_dataSet.rbegin()->first;
}

#endif