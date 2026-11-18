#include "pch.h"
#include "Employee.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

Employee::Employee() : Person()
{
    position = "Unknown";
    salary = 0.0;
}

Employee::Employee(string name, int age, string position, double salary)
    : Person(name, age)
{
    SetPosition(position);
    SetSalary(salary);
}

Employee::Employee(const Employee& other)
    : Person(other)
{
    position = other.position;
    salary = other.salary;
}

Employee::~Employee()
{
}

string Employee::GetPosition() const
{
    return position;
}

double Employee::GetSalary() const
{
    return salary;
}

void Employee::SetPosition(string position)
{
    if (position.empty())
    {
        cerr << "Error: Position cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }

    this->position = position;
}

void Employee::SetSalary(double salary)
{
    if (!isfinite(salary) || salary < 0)
    {
        cerr << "Error: Invalid salary!" << endl;
        exit(EXIT_FAILURE);
    }

    this->salary = salary;
}

Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Person::operator=(other);

        SetPosition(other.position);
        SetSalary(other.salary);
    }

    return *this;
}

ostream& operator<<(ostream& out, const Employee& employee)
{
    out << static_cast<const Person&>(employee);

    out << "Position: " << employee.position << endl;
    out << "Salary: " << employee.salary << endl;

    return out;
}

istream& operator>>(istream& in, Employee& employee)
{
    in >> static_cast<Person&>(employee);

    string position;
    double salary;

    cout << "Enter position: ";
    getline(in >> ws, position);

    cout << "Enter salary: ";
    in >> salary;

    if (!in)
    {
        cerr << "Input error!" << endl;
        exit(EXIT_FAILURE);
    }

    employee.SetPosition(position);
    employee.SetSalary(salary);

    return in;
}
