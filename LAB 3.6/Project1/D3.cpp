
#include "D3.h"

D3::D3(int value, int d1Value, int b1First,
    int d2Value, int b1Second, int b2Value)
    : D1(d1Value, b1First),
    D2(d2Value, b1Second),
    B2(b2Value)
{
    d3 = value;
}

D3::~D3()
{
}

void D3::show() const
{
    cout << "Class D3:" << endl;

    cout << "\nPublic inheritance from D1:" << endl;
    D1::show();

    cout << "\nPublic inheritance from D2:" << endl;
    D2::show();

    cout << "\nPrivate inheritance from B2:" << endl;
    B2::show();

    cout << "\nD3::d3 = " << d3 << endl;
}