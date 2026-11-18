
#include "ObjectC.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "===== LABORATORY WORK 3.3 C =====" << endl;
    cout << "Variant 14" << endl;

    cout << "\nInitial object count: "
        << Object::GetObjectCount() << endl;

    {
        MoneyC a(100, 50);
        MoneyC b(30, 25);

        cout << "\nFirst amount: " << a << endl;
        cout << "Second amount: " << b << endl;

        cout << "Object count: "
            << Object::GetObjectCount() << endl;

        MoneyC difference = a - b;
        cout << "Subtraction: " << difference << endl;

        MoneyC multiplied = a * 2.5;
        cout << "Multiplication: " << multiplied << endl;

        cout << "\nComparisons:" << endl;
        cout << "a == b: " << (a == b) << endl;
        cout << "a > b: " << (a > b) << endl;

        cout << "\nIncrement:" << endl;
        cout << "Before: " << a << endl;
        ++a;
        cout << "After prefix ++: " << a << endl;

        a--;

        cout << "After postfix --: " << a << endl;

        cout << "\nCopy constructor:" << endl;
        MoneyC copy(a);
        cout << "Copy: " << copy << endl;

        cout << "\nArray of objects:" << endl;

        MoneyC arr[3] =
        {
            MoneyC(10, 50),
            MoneyC(20, 75),
            MoneyC(30, 25)
        };

        for (int i = 0; i < 3; i++)
        {
            cout << "Element " << i + 1
                << ": " << arr[i] << endl;
        }

        cout << "\nObject count after creating array: "
            << Object::GetObjectCount() << endl;
    }

    cout << "\nObject count after leaving block: "
        << Object::GetObjectCount() << endl;

    cout << "\nProgram finished!" << endl;

    return 0;
}
