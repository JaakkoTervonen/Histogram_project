#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "histogramBase.h"
#include "Log.h"

#include <map>
#include <memory>

class Histogram : public Hist::HistogramBase
{
public:
    /**
     * @brief Construct a new Histogram object, initializes the base class and
     * moves the ownership of the param log to the constructor of Histogram.
     *
     * @param log
     */
    Histogram(std::unique_ptr<Logger> log) : Hist::HistogramBase(std::move(log)){};

    /**
     * @brief Adds EInterger to m_dataSet.
     *
     * @param value
     */
    virtual void add(Hist::EInteger value) override;

    /**
     * @brief Get the mode of the m_dataSet. If map is empty returns default
     * value Hist::EInterger::Zero.
     *
     * @return Hist::EInteger
     */
    virtual Hist::EInteger getMode() const override;

    /**
     * @brief Get the minimum value of m_dataSet. Can throw std::out_of_range
     * exception if the map is empty when calling
     *
     * @return Hist::EInteger
     */
    virtual Hist::EInteger getMinValue() const override;

    /**
     * @brief Get the maximum value of m_dataSet. Can throw std::out_of_range
     * exception if the map is empty when calling.
     *
     * @return Hist::EInteger
     */
    virtual Hist::EInteger getMaxValue() const override;

private:
    /**
     * @brief Data container for EIntegers is map, for easy min, max and mode.
     *
     */
    mutable std::map<Hist::EInteger, int> m_dataSet{};
};

#endif