#include "MoneyA.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "===== LABORATORY WORK 3.3 A =====" << endl;
    cout << "Variant 14" << endl;

    cout << "\n--- Open inheritance ---" << endl;

    MoneyAOpen a(100, 50);
    MoneyAOpen b(30, 25);

    cout << "First amount: " << (BaseMoney&)a << endl;
    cout << "Second amount: " << (BaseMoney&)b << endl;

    MoneyAOpen difference = a - b;
    cout << "Subtraction: " << (string)difference << endl;

    MoneyAOpen multiplied = a * 2.5;
    cout << "Multiplication: " << (string)multiplied << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a == b: " << (a == b) << endl;

    MoneyAOpen copy(a);
    cout << "Copy: " << (string)copy << endl;

    cout << "\n--- Closed inheritance ---" << endl;

    MoneyAClosed c(200, 75);
    MoneyAClosed d(50, 25);

    MoneyAClosed result = c - d;
    cout << "Subtraction: ";
    result.Display();

    MoneyAClosed multipliedClosed = c * 2;
    cout << "Multiplication: ";
    multipliedClosed.Display();

    cout << "c > d: " << (c > d) << endl;

    cout << "\nProgram finished!" << endl;

    return 0;
}
