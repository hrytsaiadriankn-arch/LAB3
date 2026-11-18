
#pragma once
#include "Person.h"

class Employee : public Person
{
private:
    string position;
    double salary;

public:
    Employee();
    Employee(string name, int age, string position, double salary);
    Employee(const Employee& other);
    ~Employee();

    string GetPosition() const;
    double GetSalary() const;

    void SetPosition(string position);
    void SetSalary(double salary);

    Employee& operator=(const Employee& other);

    friend ostream& operator<<(ostream& out, const Employee& employee);
    friend istream& operator>>(istream& in, Employee& employee);
};
