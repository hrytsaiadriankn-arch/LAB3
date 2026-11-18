
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();
    Person(string name, int age);
    Person(const Person& other);
    virtual ~Person();

    string GetName() const;
    int GetAge() const;

    void SetName(string name);
    void SetAge(int age);

    Person& operator=(const Person& other);

    friend ostream& operator<<(ostream& out, const Person& person);
    friend istream& operator>>(istream& in, Person& person);
};
