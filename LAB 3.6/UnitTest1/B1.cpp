#include "pch.h"
#include "B1.h"

B1::B1(int value)
{
    b1 = value;
}

B1::~B1()
{
}

void B1::show() const
{
    cout << "Class B1:" << endl;
    cout << "B1::b1 = " << b1 << endl;
}