#include "pch.h"

#include "Array.h"

template <typename T>
Array<T>::Array()
{
    count = 0;
}

template <typename T>
Array<T>::Array(int size, const T& value)
{
    if (size < 0 || size > MAX_SIZE)
        throw std::invalid_argument("Invalid array size!");

    count = size;

    for (int i = 0; i < count; i++)
        elements[i] = value;
}

template <typename T>
void Array<T>::rangeCheck(int index) const
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Array index out of range!");
}

template <typename T>
int Array<T>::GetCount() const
{
    return count;
}

template <typename T>
int Array<T>::GetMaxSize() const
{
    return MAX_SIZE;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    rangeCheck(index);
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    rangeCheck(index);
    return elements[index];
}
