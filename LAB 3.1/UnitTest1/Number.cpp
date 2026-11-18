
#include "Number.h"
#include <sstream>
#include <cmath>
#include <cstdlib>

Number::Number()
{
    value = 0.0;
}

Number::Number(double value)
{
    SetValue(value);
}

Number::Number(const Number& other)
{
    value = other.value;
}

Number::~Number()
{
}

double Number::GetValue() const
{
    return value;
}

void Number::SetValue(double value)
{
    if (!isfinite(value))
    {
        cerr << "Error: Invalid number!" << endl;
        exit(EXIT_FAILURE);
    }

    this->value = value;
}

void Number::Init(double value)
{
    SetValue(value);
}

void Number::Read()
{
    double number;

    cout << "Enter number: ";
    cin >> number;

    if (!cin)
    {
        cerr << "Input error!" << endl;
        exit(EXIT_FAILURE);
    }

    SetValue(number);
}

void Number::Display() const
{
    cout << *this << endl;
}

void Number::Multiply(double number)
{
    if (!isfinite(number) || !isfinite(value * number))
    {
        cerr << "Error: Invalid multiplication!" << endl;
        exit(EXIT_FAILURE);
    }

    value *= number;
}

void Number::Subtract(double number)
{
    if (!isfinite(number) || !isfinite(value - number))
    {
        cerr << "Error: Invalid subtraction!" << endl;
        exit(EXIT_FAILURE);
    }

    value -= number;
}

Number::operator string() const
{
    stringstream ss;
    ss << value;
    return ss.str();
}

ostream& operator<<(ostream& out, const Number& number)
{
    return out << (string)number;
}

istream& operator>>(istream& in, Number& number)
{
    double temp;

    cout << "Enter number: ";
    in >> temp;

    if (in)
        number.SetValue(temp);

    return in;
}
