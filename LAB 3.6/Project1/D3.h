#pragma once

#include "D1.h"
#include "D2.h"
#include "B2.h"

class D3 : public D1, public D2, private B2
{
private:
    int d3;

public:
    D3(int value, int d1Value, int b1First,
        int d2Value, int b1Second, int b2Value);

    ~D3();

    void show() const;
};