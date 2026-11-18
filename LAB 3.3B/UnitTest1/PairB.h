
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair
{
private:
    long first;
    long second;

public:
    Pair();
    Pair(long first, long second);
    Pair(const Pair& other);

    long GetFirst() const;
    long GetSecond() const;

    void SetFirst(long value);
    void SetSecond(long value);

    Pair& operator=(const Pair& other);

    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;
    bool operator>(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator>=(const Pair& other) const;
    bool operator<=(const Pair& other) const;

    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
};

class MoneyB : public Pair
{
public:
    MoneyB();
    MoneyB(long hryvnias, int kopecks);
    MoneyB(const MoneyB& other);

    MoneyB operator-(const MoneyB& other) const;
    MoneyB operator*(double number) const;

    bool operator==(const MoneyB& other) const;
    bool operator!=(const MoneyB& other) const;
    bool operator>(const MoneyB& other) const;
    bool operator<(const MoneyB& other) const;

    MoneyB& operator=(const MoneyB& other);

    operator string() const;

    long long ToKopecks() const;
};
