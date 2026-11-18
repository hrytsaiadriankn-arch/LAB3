
#pragma once
#include <iostream>
#include <string>

using namespace std;

// Базовий клас
class BaseMoney
{
private:
    long hryvnias;
    unsigned char kopecks;

public:
    BaseMoney();
    BaseMoney(long hryvnias, int kopecks);
    BaseMoney(const BaseMoney& other);

    long GetHryvnias() const;
    int GetKopecks() const;

    long long GetTotalKopecks() const;

    friend ostream& operator<<(ostream& out, const BaseMoney& money);
    friend istream& operator>>(istream& in, BaseMoney& money);
};

// Відкрите успадкування
class MoneyAOpen : public BaseMoney
{
public:
    MoneyAOpen();
    MoneyAOpen(long hryvnias, int kopecks);
    MoneyAOpen(const MoneyAOpen& other);

    MoneyAOpen operator-(const MoneyAOpen& other) const;
    MoneyAOpen operator*(double number) const;

    bool operator==(const MoneyAOpen& other) const;
    bool operator!=(const MoneyAOpen& other) const;
    bool operator>(const MoneyAOpen& other) const;
    bool operator<(const MoneyAOpen& other) const;

    MoneyAOpen& operator=(const MoneyAOpen& other);

    operator string() const;
};

// Закрите успадкування
class MoneyAClosed : private BaseMoney
{
public:
    MoneyAClosed();
    MoneyAClosed(long hryvnias, int kopecks);

    long GetHryvnias() const;
    int GetKopecks() const;

    MoneyAClosed operator-(const MoneyAClosed& other) const;
    MoneyAClosed operator*(double number) const;

    bool operator==(const MoneyAClosed& other) const;
    bool operator>(const MoneyAClosed& other) const;

    void Display() const;
};
