
#pragma once

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
protected:
    static const int MAX_SIZE = 100;

    T elements[MAX_SIZE];
    int count;

    void rangeCheck(int index) const;

public:
    Array();
    Array(int size, const T& value = T());

    int GetCount() const;
    int GetMaxSize() const;

    T& operator[](int index);
    const T& operator[](int index) const;
};

#include "Array.cpp"