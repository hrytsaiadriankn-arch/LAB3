#include "pch.h"
#include "D1.h"

D1::D1(int value, int baseValue)
    : B1(baseValue)
{
    d1 = value;
}

D1::~D1()
{
}

void D1::show() const
{
    cout << "Class D1:" << endl;
    B1::show();
    cout << "D1::d1 = " << d1 << endl;
}