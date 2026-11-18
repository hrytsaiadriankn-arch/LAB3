#include "pch.h"
#include "PairB.h"
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>

Pair::Pair() : first(0), second(0)
{
}

Pair::Pair(long first, long second)
{
    if (first < 0 || second < 0)
    {
        cerr << "Invalid pair values!" << endl;
        exit(EXIT_FAILURE);
    }

    this->first = first;
    this->second = second;
}

Pair::Pair(const Pair& other)
    : first(other.first), second(other.second)
{
}

long Pair::GetFirst() const
{
    return first;
}

long Pair::GetSecond() const
{
    return second;
}

void Pair::SetFirst(long value)
{
    if (value < 0)
    {
        cerr << "Invalid first value!" << endl;
        exit(EXIT_FAILURE);
    }

    first = value;
}

void Pair::SetSecond(long value)
{
    if (value < 0)
    {
        cerr << "Invalid second value!" << endl;
        exit(EXIT_FAILURE);
    }

    second = value;
}

Pair& Pair::operator=(const Pair& other)
{
    if (this != &other)
    {
        SetFirst(other.first);
        SetSecond(other.second);
    }

    return *this;
}

bool Pair::operator==(const Pair& other) const
{
    return first == other.first && second == other.second;
}

bool Pair::operator!=(const Pair& other) const
{
    return !(*this == other);
}

bool Pair::operator>(const Pair& other) const
{
    return first > other.first ||
        (first == other.first && second > other.second);
}

bool Pair::operator<(const Pair& other) const
{
    return other > *this;
}

bool Pair::operator>=(const Pair& other) const
{
    return !(*this < other);
}

bool Pair::operator<=(const Pair& other) const
{
    return !(*this > other);
}

ostream& operator<<(ostream& out, const Pair& p)
{
    return out << "(" << p.first << ", " << p.second << ")";
}

istream& operator>>(istream& in, Pair& p)
{
    long first, second;

    cout << "Enter first number: ";
    in >> first;

    cout << "Enter second number: ";
    in >> second;

    if (in)
    {
        p.SetFirst(first);
        p.SetSecond(second);
    }

    return in;
}

// MoneyB

MoneyB::MoneyB() : Pair()
{
}

MoneyB::MoneyB(long h, int k) : Pair(h, k)
{
    if (k > 99)
    {
        cerr << "Kopecks must be between 0 and 99!" << endl;
        exit(EXIT_FAILURE);
    }
}

MoneyB::MoneyB(const MoneyB& other) : Pair(other)
{
}

long long MoneyB::ToKopecks() const
{
    return static_cast<long long>(GetFirst()) * 100 + GetSecond();
}

MoneyB MoneyB::operator-(const MoneyB& other) const
{
    long long result = ToKopecks() - other.ToKopecks();

    if (result < 0)
    {
        cerr << "Subtraction result cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }

    return MoneyB(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

MoneyB MoneyB::operator*(double number) const
{
    if (!isfinite(number) || number < 0)
    {
        cerr << "Invalid multiplier!" << endl;
        exit(EXIT_FAILURE);
    }

    long long result =
        static_cast<long long>(ToKopecks() * number + 0.5);

    return MoneyB(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

bool MoneyB::operator==(const MoneyB& other) const
{
    return ToKopecks() == other.ToKopecks();
}

bool MoneyB::operator!=(const MoneyB& other) const
{
    return !(*this == other);
}

bool MoneyB::operator>(const MoneyB& other) const
{
    return ToKopecks() > other.ToKopecks();
}

bool MoneyB::operator<(const MoneyB& other) const
{
    return ToKopecks() < other.ToKopecks();
}

MoneyB& MoneyB::operator=(const MoneyB& other)
{
    if (this != &other)
        Pair::operator=(other);

    return *this;
}

MoneyB::operator string() const
{
    stringstream ss;

    ss << GetFirst() << ",";

    if (GetSecond() < 10)
        ss << "0";

    ss << GetSecond() << " UAH";

    return ss.str();
}
