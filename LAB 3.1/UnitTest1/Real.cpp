#include "pch.h"
#include "Real.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

Real::Real() : Number()
{
}

Real::Real(double value) : Number(value)
{
}

Real::Real(const Real& other) : Number(other)
{
}

Real::~Real()
{
}

double Real::Root(int degree) const
{
    if (degree == 0)
    {
        cerr << "Error: Root degree cannot be zero!" << endl;
        exit(EXIT_FAILURE);
    }

    double number = GetValue();

    if (number < 0 && degree % 2 == 0)
    {
        cerr << "Error: Even root of a negative number!" << endl;
        exit(EXIT_FAILURE);
    }

    double result;

    if (number < 0)
        result = -pow(-number, 1.0 / degree);
    else
        result = pow(number, 1.0 / degree);

    if (!isfinite(result))
    {
        cerr << "Error: Root calculation failed!" << endl;
        exit(EXIT_FAILURE);
    }

    return result;
}

double Real::PowerOfPi(double exponent) const
{
    if (!isfinite(exponent))
    {
        cerr << "Error: Invalid exponent!" << endl;
        exit(EXIT_FAILURE);
    }

    const double PI = acos(-1.0);

    double result = pow(PI, exponent);

    if (!isfinite(result))
    {
        cerr << "Error: Pi power calculation failed!" << endl;
        exit(EXIT_FAILURE);
    }

    return result;
}

void Real::DisplayReal() const
{
    cout << "Real number: " << GetValue() << endl;
}
