
#include "Person.h"
#include <cstdlib>

Person::Person()
{
    name = "Unknown";
    age = 0;
}

Person::Person(string name, int age)
{
    SetName(name);
    SetAge(age);
}

Person::Person(const Person& other)
{
    name = other.name;
    age = other.age;
}

Person::~Person()
{
}

string Person::GetName() const
{
    return name;
}

int Person::GetAge() const
{
    return age;
}

void Person::SetName(string name)
{
    if (name.empty())
    {
        cerr << "Error: Name cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }

    this->name = name;
}

void Person::SetAge(int age)
{
    if (age < 0 || age > 120)
    {
        cerr << "Error: Invalid age!" << endl;
        exit(EXIT_FAILURE);
    }

    this->age = age;
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        SetName(other.name);
        SetAge(other.age);
    }

    return *this;
}

ostream& operator<<(ostream& out, const Person& person)
{
    out << "Name: " << person.name << endl;
    out << "Age: " << person.age << endl;

    return out;
}

istream& operator>>(istream& in, Person& person)
{
    string name;
    int age;

    cout << "Enter name: ";
    getline(in >> ws, name);

    cout << "Enter age: ";
    in >> age;

    if (!in)
    {
        cerr << "Input error!" << endl;
        exit(EXIT_FAILURE);
    }

    person.SetName(name);
    person.SetAge(age);

    return in;
}
