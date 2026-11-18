#include <iostream>
#include "B1.h"
#include "D1.h"
#include "D2.h"
#include "B2.h"
#include "D3.h"

using namespace std;

int main()
{
    // Object of B1
    B1 objB1(10);

    cout << "========== OBJECT B1 ==========" << endl;
    cout << "sizeof(B1) = " << sizeof(B1) << endl;
    objB1.show();

    // Object of D1
    D1 objD1(20, 21);

    cout << "\n========== OBJECT D1 ==========" << endl;
    cout << "sizeof(D1) = " << sizeof(D1) << endl;
    objD1.show();

    // Object of D2
    D2 objD2(30, 31);

    cout << "\n========== OBJECT D2 ==========" << endl;
    cout << "sizeof(D2) = " << sizeof(D2) << endl;
    objD2.show();

    // Object of B2
    B2 objB2(40);

    cout << "\n========== OBJECT B2 ==========" << endl;
    cout << "sizeof(B2) = " << sizeof(B2) << endl;
    objB2.show();

    // Object of D3
    D3 objD3(50, 60, 61, 70, 71, 80);

    cout << "\n========== OBJECT D3 ==========" << endl;
    cout << "sizeof(D3) = " << sizeof(D3) << endl;
    objD3.show();

    return 0;
}