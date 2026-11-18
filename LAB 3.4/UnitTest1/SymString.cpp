#include "pch.h"
#include "SymString.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// ===============================
// ¡¿«Œ¬»…  À¿— SymString
// ===============================

SymString::SymString()
{
    id = "Unknown";
    value = "";
}

SymString::SymString(string id, string value)
{
    SetId(id);
    SetValue(value);
}

SymString::SymString(const SymString& other)
{
    id = other.id;
    value = other.value;
}

SymString::~SymString()
{
}

string SymString::GetId() const
{
    return id;
}

string SymString::GetValue() const
{
    return value;
}

void SymString::SetId(string id)
{
    if (id.empty())
    {
        cerr << "Error: ID cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }

    this->id = id;
}

void SymString::SetValue(string value)
{
    this->value = value;
}

void SymString::Show() const
{
    cout << "ID: " << id << endl;
    cout << "Value: " << value << endl;
}

SymString SymString::operator-(const SymString& other) const
{
    string result = value;

    size_t position = result.find(other.value);

    if (position != string::npos && !other.value.empty())
    {
        result.erase(position, other.value.length());
    }

    return SymString(id + "_result", result);
}

SymString::operator string() const
{
    return value;
}

ostream& operator<<(ostream& out, const SymString& obj)
{
    out << "ID: " << obj.id << endl;
    out << "Value: " << obj.value;

    return out;
}

istream& operator>>(istream& in, SymString& obj)
{
    string newId;
    string newValue;

    cout << "Enter ID: ";
    getline(in >> ws, newId);

    cout << "Enter string: ";
    getline(in, newValue);

    if (in)
    {
        obj.SetId(newId);
        obj.SetValue(newValue);
    }

    return in;
}

// ===============================
// œŒ’≤ƒÕ»…  À¿— DecString
// ===============================

DecString::DecString() : SymString()
{
}

DecString::DecString(string id, string value)
    : SymString(id, "")
{
    SetValue(value);
}

DecString::DecString(const DecString& other)
    : SymString(other)
{
}

DecString::~DecString()
{
}

void DecString::SetValue(string value)
{
    if (value.empty())
    {
        cerr << "Error: Decimal value cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }

    for (char c : value)
    {
        if (!isdigit(static_cast<unsigned char>(c)))
        {
            cerr << "Error: Only positive decimal integers are allowed!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    try
    {
        stoull(value);
    }
    catch (...)
    {
        cerr << "Error: Decimal number is too large!" << endl;
        exit(EXIT_FAILURE);
    }

    this->value = value;
}

void DecString::ShowBin() const
{
    unsigned long long number = stoull(value);

    if (number == 0)
    {
        cout << "Binary: 0" << endl;
        return;
    }

    string binary;

    while (number > 0)
    {
        binary = char('0' + number % 2) + binary;
        number /= 2;
    }

    cout << "Binary: " << binary << endl;
}

DecString DecString::operator-(const DecString& other) const
{
    unsigned long long first = stoull(value);
    unsigned long long second = stoull(other.value);

    if (first < second)
    {
        cerr << "Error: Result cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }

    return DecString(
        id + "_result",
        to_string(first - second)
    );
}

void DecString::Show() const
{
    cout << "ID: " << id << endl;
    cout << "Decimal value: " << value << endl;
}

DecString::operator string() const
{
    return value;
}

// ===============================
//  À¿— Factory
// ===============================

SymString* Factory::CreateSymString(string id, string value)
{
    return new SymString(id, value);
}

SymString* Factory::CreateDecString(string id, string value)
{
    return new DecString(id, value);
}

void Factory::Delete(SymString* obj)
{
    delete obj;
}
