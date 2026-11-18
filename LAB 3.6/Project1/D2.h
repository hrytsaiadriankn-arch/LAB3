#pragma once
#include "B1.h"

class D2 : private B1
{
private:
    int d2;

public:
    D2(int value, int baseValue);
    ~D2();

    void show() const;
};