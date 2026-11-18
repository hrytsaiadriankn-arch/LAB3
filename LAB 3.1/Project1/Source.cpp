
#include "Real.h"
#include <iostream>

using namespace std;

// Функція отримує та повертає об'єкт базового класу
Number ProcessNumber(Number number)
{
    number.Multiply(2);
    return number;
}

int main()
{
    cout << "===== LABORATORY WORK 3.1 =====" << endl;
    cout << "Variant 14" << endl;

    // 1. Робота з базовим класом Number
    cout << "\n--- Base class Number ---" << endl;

    Number n1, n2;

    cout << "First number:" << endl;
    cin >> n1;

    cout << "Second number:" << endl;
    cin >> n2;

    Number multiplication = n1;
    multiplication.Multiply(n2.GetValue());

    Number subtraction = n1;
    subtraction.Subtract(n2.GetValue());

    cout << "\nMultiplication: "
        << multiplication << endl;

    cout << "Subtraction: "
        << subtraction << endl;

    // 2. Робота з похідним класом Real
    cout << "\n--- Derived class Real ---" << endl;

    Real r;

    cout << "Enter real number:" << endl;
    cin >> r;

    int degree;

    cout << "Enter root degree: ";
    cin >> degree;

    if (!cin)
    {
        cout << "Input error!" << endl;
        return 1;
    }

    cout << "Root result: "
        << r.Root(degree) << endl;

    double exponent;

    cout << "Enter exponent for PI: ";
    cin >> exponent;

    if (!cin)
    {
        cout << "Input error!" << endl;
        return 1;
    }

    cout << "PI power result: "
        << r.PowerOfPi(exponent) << endl;

    // 3. Масив об'єктів похідного класу
    cout << "\n--- Array of Real objects ---" << endl;

    Real arr[3] = {
        Real(4.0),
        Real(9.0),
        Real(16.0)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Element " << i + 1 << ": ";
        arr[i].DisplayReal();
    }

    // 4. Принцип підстановки
    cout << "\n--- Substitution principle ---" << endl;

    Real realNumber(5.5);

    Number result = ProcessNumber(realNumber);

    cout << "Original Real number: "
        << realNumber << endl;

    cout << "Result after multiplication by 2: "
        << result << endl;

    cout << "\nProgram finished successfully!" << endl;

    return 0;
}
