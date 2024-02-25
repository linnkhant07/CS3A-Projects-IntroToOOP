#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include "assert.h"
#include <iostream>

using namespace std;

void _array_init(int a[], int size, int x = 0);

void _append(int a[], int &size, int append_me);

int _find(const int a[], int size, int find_me);

int &_at(int a[], int size, int pos);

template <typename T>
void _shift_left(T *a, int &size, int shift_here)
{
    // if given index is negative
    assert(shift_here >= 0);

    // if index is out of range
    assert(shift_here < size);

    // create a walker that points to the index
    T *walker = a + shift_here;

    // shift everything after the index to left
    for (; shift_here < size; shift_here++, walker++)
    {
        *walker = *(walker + 1); // the variable walker is pointing to will be replaced by the element that comes after
    }

    // reduce the size of the array
    size--;
}

template <typename T>
void _shift_left(T *a, int &size, T *shift_here)
{
    // calculate distance from the first element of the array and the shift_here element
    int distance = a - shift_here;

    _shift_left(a, size, distance);
}

template <typename T>
void _shift_right(T *a, int &size, int shift_here)
{
    // if given index is negative
    assert(shift_here >= 0);

    // if index is out of range
    assert(shift_here < size);

    // increment the size of the array
    size++;

    // create a walker that points to the end of the array
    T *walker = a + size;

    // shift everything to right starting from the index
    for (; shift_here < size; shift_here++, walker--)
    {
        *walker = *(walker - 1); // the variable walker is pointing to will be replaced by the element that comes before
    }
}

ostream &_print_array(const int a[], int size, ostream &outs = cout);
#endif