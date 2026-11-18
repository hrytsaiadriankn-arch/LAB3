
#pragma once
#include <iostream>
#include <string>

using namespace std;

class SymString
{
protected:
    string id;
    string value;

public:
    SymString();
    SymString(string id, string value);
    SymString(const SymString& other);
    virtual ~SymString();

    string GetId() const;
    string GetValue() const;

    void SetId(string id);
    void SetValue(string value);

    virtual void Show() const;

    // Видалення підрядка
    SymString operator-(const SymString& other) const;

    virtual operator string() const;

    friend ostream& operator<<(ostream& out, const SymString& obj);
    friend istream& operator>>(istream& in, SymString& obj);
};

// Похідний клас десяткового рядка
class DecString : public SymString
{
public:
    DecString();
    DecString(string id, string value);
    DecString(const DecString& other);
    ~DecString() override;

    void SetValue(string value);

    // Показ числа у двійковій системі
    void ShowBin() const;

    // Віднімання десяткових чисел
    DecString operator-(const DecString& other) const;

    void Show() const override;

    operator string() const override;
};

// Фабрика створення та видалення об'єктів
class Factory
{
public:
    static SymString* CreateSymString(string id, string value);
    static SymString* CreateDecString(string id, string value);

    static void Delete(SymString* obj);
};
