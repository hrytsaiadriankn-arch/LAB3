
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Object
{
private:
    static int objectCount;

public:
    Object();
    Object(const Object& other);
    virtual ~Object();

    static int GetObjectCount();
};

class MoneyC : public Object
{
private:
    long hryvnias;
    unsigned char kopecks;

public:
    MoneyC();
    MoneyC(long hryvnias, int kopecks);
    MoneyC(const MoneyC& other);

    long GetHryvnias() const;
    int GetKopecks() const;

    void SetHryvnias(long value);
    void SetKopecks(int value);

    long long ToKopecks() const;

    MoneyC& operator=(const MoneyC& other);

    MoneyC operator-(const MoneyC& other) const;
    MoneyC operator*(double number) const;

    bool operator==(const MoneyC& other) const;
    bool operator!=(const MoneyC& other) const;
    bool operator>(const MoneyC& other) const;
    bool operator<(const MoneyC& other) const;

    MoneyC& operator++();
    MoneyC operator++(int);
    MoneyC& operator--();
    MoneyC operator--(int);

    operator string() const;

    friend ostream& operator<<(ostream& out, const MoneyC& money);
    friend istream& operator>>(istream& in, MoneyC& money);
};
