
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number
{
private:
    double value;

public:
    Number();
    Number(double value);
    Number(const Number& other);
    ~Number();

    double GetValue() const;
    void SetValue(double value);

    void Init(double value);
    void Read();
    void Display() const;

    void Multiply(double number);
    void Subtract(double number);

    operator string() const;

    friend ostream& operator<<(ostream& out, const Number& number);
    friend istream& operator>>(istream& in, Number& number);
};
