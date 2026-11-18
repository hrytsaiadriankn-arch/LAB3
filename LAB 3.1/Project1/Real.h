
#pragma once
#include "Number.h"

class Real : public Number
{
public:
    Real();
    Real(double value);
    Real(const Real& other);
    ~Real();

    double Root(int degree) const;
    double PowerOfPi(double exponent) const;

    void DisplayReal() const;
};
