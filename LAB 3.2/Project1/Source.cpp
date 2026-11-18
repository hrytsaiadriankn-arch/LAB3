
#include "Person.h"
#include "Employee.h"
#include <iostream>

using namespace std;

// Функція отримує та повертає об'єкт базового класу
Person ProcessPerson(Person person)
{
    person.SetName(person.GetName() + " (processed)");

    return person;
}

int main()
{
    cout << "===== LABORATORY WORK 3.2 =====" << endl;
    cout << "Variant 14" << endl;

    // 1. Створення об'єкта Person
    cout << "\n--- Person class ---" << endl;

    Person p1;

    cin >> p1;

    cout << "\nPerson information:" << endl;
    cout << p1;

    // 2. Створення об'єкта Employee
    cout << "\n--- Employee class ---" << endl;

    Employee e1;

    cin >> e1;

    cout << "\nEmployee information:" << endl;
    cout << e1;

    // 3. Конструктор копіювання
    cout << "\n--- Copy constructor ---" << endl;

    Employee e2(e1);

    cout << "Copied employee:" << endl;
    cout << e2;

    // 4. Операція присвоювання
    cout << "\n--- Assignment operator ---" << endl;

    Employee e3;

    e3 = e1;

    cout << "Assigned employee:" << endl;
    cout << e3;

    // 5. Масив об'єктів Employee
    cout << "\n--- Array of employees ---" << endl;

    Employee employees[3] =
    {
        Employee("John", 25, "Manager", 15000),
        Employee("Michael", 30, "Programmer", 20000),
        Employee("David", 35, "Director", 30000)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        cout << employees[i];
    }

    // 6. Принцип підстановки
    cout << "\n--- Substitution principle ---" << endl;

    Person result = ProcessPerson(e1);

    cout << result;

    cout << "\nProgram finished successfully!" << endl;

    return 0;
}
