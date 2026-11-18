
#include "ObjectC.h"
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>

int Object::objectCount = 0;

Object::Object()
{
    objectCount++;
}

Object::Object(const Object& other)
{
    objectCount++;
}

Object::~Object()
{
    objectCount--;
}

int Object::GetObjectCount()
{
    return objectCount;
}

// MoneyC

MoneyC::MoneyC() : Object(), hryvnias(0), kopecks(0)
{
}

MoneyC::MoneyC(long h, int k) : Object()
{
    SetHryvnias(h);
    SetKopecks(k);
}

MoneyC::MoneyC(const MoneyC& other)
    : Object(other),
    hryvnias(other.hryvnias),
    kopecks(other.kopecks)
{
}

long MoneyC::GetHryvnias() const
{
    return hryvnias;
}

int MoneyC::GetKopecks() const
{
    return kopecks;
}

void MoneyC::SetHryvnias(long value)
{
    if (value < 0)
    {
        cerr << "Invalid hryvnias!" << endl;
        exit(EXIT_FAILURE);
    }

    hryvnias = value;
}

void MoneyC::SetKopecks(int value)
{
    if (value < 0 || value > 99)
    {
        cerr << "Kopecks must be between 0 and 99!" << endl;
        exit(EXIT_FAILURE);
    }

    kopecks = static_cast<unsigned char>(value);
}

long long MoneyC::ToKopecks() const
{
    return static_cast<long long>(hryvnias) * 100 + kopecks;
}

MoneyC& MoneyC::operator=(const MoneyC& other)
{
    if (this != &other)
    {
        hryvnias = other.hryvnias;
        kopecks = other.kopecks;
    }

    return *this;
}

MoneyC MoneyC::operator-(const MoneyC& other) const
{
    long long result = ToKopecks() - other.ToKopecks();

    if (result < 0)
    {
        cerr << "Subtraction result cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }

    return MoneyC(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

MoneyC MoneyC::operator*(double number) const
{
    if (!isfinite(number) || number < 0)
    {
        cerr << "Invalid multiplier!" << endl;
        exit(EXIT_FAILURE);
    }

    long long result =
        static_cast<long long>(ToKopecks() * number + 0.5);

    return MoneyC(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

bool MoneyC::operator==(const MoneyC& other) const
{
    return ToKopecks() == other.ToKopecks();
}

bool MoneyC::operator!=(const MoneyC& other) const
{
    return !(*this == other);
}

bool MoneyC::operator>(const MoneyC& other) const
{
    return ToKopecks() > other.ToKopecks();
}

bool MoneyC::operator<(const MoneyC& other) const
{
    return ToKopecks() < other.ToKopecks();
}

// «б≥льшенн€ на одну коп≥йку
MoneyC& MoneyC::operator++()
{
    long long value = ToKopecks() + 1;

    hryvnias = static_cast<long>(value / 100);
    kopecks = static_cast<unsigned char>(value % 100);

    return *this;
}

MoneyC MoneyC::operator++(int)
{
    MoneyC temp(*this);
    ++(*this);
    return temp;
}

// «меншенн€ на одну коп≥йку
MoneyC& MoneyC::operator--()
{
    if (ToKopecks() == 0)
    {
        cerr << "Cannot decrease zero money!" << endl;
        exit(EXIT_FAILURE);
    }

    long long value = ToKopecks() - 1;

    hryvnias = static_cast<long>(value / 100);
    kopecks = static_cast<unsigned char>(value % 100);

    return *this;
}

MoneyC MoneyC::operator--(int)
{
    MoneyC temp(*this);
    --(*this);
    return temp;
}

MoneyC::operator string() const
{
    stringstream ss;

    ss << hryvnias << ",";

    if (kopecks < 10)
        ss << "0";

    ss << static_cast<int>(kopecks) << " UAH";

    return ss.str();
}

ostream& operator<<(ostream& out, const MoneyC& money)
{
    return out << static_cast<string>(money);
}

istream& operator>>(istream& in, MoneyC& money)
{
    long h;
    int k;

    cout << "Enter hryvnias: ";
    in >> h;

    cout << "Enter kopecks: ";
    in >> k;

    if (in)
    {
        money.SetHryvnias(h);
        money.SetKopecks(k);
    }

    return in;
}
