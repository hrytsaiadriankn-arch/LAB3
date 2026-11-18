
#include "PairB.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "===== LABORATORY WORK 3.3 B =====" << endl;
    cout << "Variant 14" << endl;

    MoneyB a(150, 75);
    MoneyB b(50, 25);

    cout << "\nFirst amount: " << (string)a << endl;
    cout << "Second amount: " << (string)b << endl;

    MoneyB result = a - b;
    cout << "Subtraction: " << (string)result << endl;

    MoneyB multiplied = a * 2.5;
    cout << "Multiplication: " << (string)multiplied << endl;

    cout << "\nComparisons:" << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;

    cout << "\n--- Pair base class ---" << endl;

    Pair p1(10, 20);
    Pair p2(10, 15);

    cout << "Pair 1: " << p1 << endl;
    cout << "Pair 2: " << p2 << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;

    cout << "\nProgram finished!" << endl;

    return 0;
}
