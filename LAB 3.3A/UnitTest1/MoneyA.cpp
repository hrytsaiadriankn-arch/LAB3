#include "pch.h"
#include "MoneyA.h"
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <sstream>

static void CheckMoney(long hryvnias, int kopecks)
{
    if (hryvnias < 0 || kopecks < 0 || kopecks > 99)
    {
        cerr << "Invalid money value!" << endl;
        exit(EXIT_FAILURE);
    }
}

BaseMoney::BaseMoney() : hryvnias(0), kopecks(0)
{
}

BaseMoney::BaseMoney(long hryvnias, int kopecks)
{
    CheckMoney(hryvnias, kopecks);
    this->hryvnias = hryvnias;
    this->kopecks = static_cast<unsigned char>(kopecks);
}

BaseMoney::BaseMoney(const BaseMoney& other)
    : hryvnias(other.hryvnias), kopecks(other.kopecks)
{
}

long BaseMoney::GetHryvnias() const
{
    return hryvnias;
}

int BaseMoney::GetKopecks() const
{
    return kopecks;
}

long long BaseMoney::GetTotalKopecks() const
{
    return static_cast<long long>(hryvnias) * 100 + kopecks;
}

ostream& operator<<(ostream& out, const BaseMoney& money)
{
    out << money.hryvnias << ","
        << setw(2) << setfill('0')
        << static_cast<int>(money.kopecks)
        << " UAH";

    return out;
}

istream& operator>>(istream& in, BaseMoney& money)
{
    long hryvnias;
    int kopecks;

    cout << "Enter hryvnias: ";
    in >> hryvnias;

    cout << "Enter kopecks: ";
    in >> kopecks;

    if (in)
    {
        CheckMoney(hryvnias, kopecks);
        money.hryvnias = hryvnias;
        money.kopecks = static_cast<unsigned char>(kopecks);
    }

    return in;
}

// MoneyAOpen

MoneyAOpen::MoneyAOpen() : BaseMoney()
{
}

MoneyAOpen::MoneyAOpen(long h, int k) : BaseMoney(h, k)
{
}

MoneyAOpen::MoneyAOpen(const MoneyAOpen& other)
    : BaseMoney(other)
{
}

MoneyAOpen MoneyAOpen::operator-(const MoneyAOpen& other) const
{
    long long result = GetTotalKopecks() -
        other.GetTotalKopecks();

    if (result < 0)
    {
        cerr << "Subtraction result cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }

    return MoneyAOpen(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

MoneyAOpen MoneyAOpen::operator*(double number) const
{
    if (!isfinite(number) || number < 0)
    {
        cerr << "Invalid multiplier!" << endl;
        exit(EXIT_FAILURE);
    }

    long long result = static_cast<long long>(
        GetTotalKopecks() * number + 0.5
        );

    return MoneyAOpen(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

bool MoneyAOpen::operator==(const MoneyAOpen& other) const
{
    return GetTotalKopecks() == other.GetTotalKopecks();
}

bool MoneyAOpen::operator!=(const MoneyAOpen& other) const
{
    return !(*this == other);
}

bool MoneyAOpen::operator>(const MoneyAOpen& other) const
{
    return GetTotalKopecks() > other.GetTotalKopecks();
}

bool MoneyAOpen::operator<(const MoneyAOpen& other) const
{
    return GetTotalKopecks() < other.GetTotalKopecks();
}

MoneyAOpen& MoneyAOpen::operator=(const MoneyAOpen& other)
{
    if (this != &other)
        BaseMoney::operator=(other);

    return *this;
}

MoneyAOpen::operator string() const
{
    stringstream ss;
    ss << GetHryvnias() << ",";

    if (GetKopecks() < 10)
        ss << "0";

    ss << GetKopecks() << " UAH";

    return ss.str();
}

// MoneyAClosed

MoneyAClosed::MoneyAClosed() : BaseMoney()
{
}

MoneyAClosed::MoneyAClosed(long h, int k) : BaseMoney(h, k)
{
}

long MoneyAClosed::GetHryvnias() const
{
    return BaseMoney::GetHryvnias();
}

int MoneyAClosed::GetKopecks() const
{
    return BaseMoney::GetKopecks();
}

MoneyAClosed MoneyAClosed::operator-(const MoneyAClosed& other) const
{
    long long result =
        BaseMoney::GetTotalKopecks() -
        other.BaseMoney::GetTotalKopecks();

    if (result < 0)
    {
        cerr << "Subtraction result cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }

    return MoneyAClosed(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

MoneyAClosed MoneyAClosed::operator*(double number) const
{
    if (!isfinite(number) || number < 0)
    {
        cerr << "Invalid multiplier!" << endl;
        exit(EXIT_FAILURE);
    }

    long long result = static_cast<long long>(
        BaseMoney::GetTotalKopecks() * number + 0.5
        );

    return MoneyAClosed(
        static_cast<long>(result / 100),
        static_cast<int>(result % 100)
    );
}

bool MoneyAClosed::operator==(const MoneyAClosed& other) const
{
    return BaseMoney::GetTotalKopecks() ==
        other.BaseMoney::GetTotalKopecks();
}

bool MoneyAClosed::operator>(const MoneyAClosed& other) const
{
    return BaseMoney::GetTotalKopecks() >
        other.BaseMoney::GetTotalKopecks();
}

void MoneyAClosed::Display() const
{
    cout << GetHryvnias() << ",";

    if (GetKopecks() < 10)
        cout << "0";

    cout << GetKopecks() << " UAH" << endl;
}