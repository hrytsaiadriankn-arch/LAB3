#include "pch.h"
#include "B2.h"

B2::B2(int value)
{
    b2 = value;
}

B2::~B2()
{
}

void B2::show() const
{
    cout << "Class B2:" << endl;
    cout << "B2::b2 = " << b2 << endl;
}