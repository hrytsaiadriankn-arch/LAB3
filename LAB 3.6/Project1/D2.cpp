
#include "D2.h"

D2::D2(int value, int baseValue)
    : B1(baseValue)
{
    d2 = value;
}

D2::~D2()
{
}

void D2::show() const
{
    cout << "Class D2:" << endl;
    B1::show();
    cout << "D2::d2 = " << d2 << endl;
}