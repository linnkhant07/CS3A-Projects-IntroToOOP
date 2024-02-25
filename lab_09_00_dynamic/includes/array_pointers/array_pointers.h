#ifndef ARRAY_POINTERS_H
#define ARRAY_POINTERS_H
#include <iostream>
#include <cassert>

using namespace std;

// precondition: an array has been initialized
template <class T>
void shift_left(T *a, int &size, int shift_here)
{
    // if given index is negative
    assert(shift_here >= 0);

    // if index is out of range
    assert(shift_here < size);

    // walker pointing to the end of the array
    T *end = a + (size - 1);

    // create a walker that points to the index
    T *walker = a + shift_here;

    // create a second walker to that points to to the index
    // that comes after
    T *walker2 = walker + 1;

    while (walker != end)
    {
        *walker = *walker2;
        // move pointers to the right
        walker++;
        walker2++;
    }
}
// postcondition: all the elements after 'shift_here' have been shifted to left
// size of the array is decremented by 1

// precondition: an array has been initialized
template <class T>
void shift_right(T *a, int &size, int shift_here)
{
    // if given index is negative
    assert(shift_here >= 0);

    // if index is out of range
    assert(shift_here < size);

    // pointer that points to the shift_here index
    T *shift_here_ptr = a + shift_here;

    // create a walker that points to one index after the end of the array
    T *walker = a + size;

    // create a second walker to that points to the end of the array
    T *walker2 = walker - 1;

    while (walker != shift_here_ptr)
    {
        *walker = *walker2;
        // move pointers to the left
        walker--;
        walker2--;
    }
};
    // postcondition: all the elements after 'shift_here' have been shifted to right
    // size of the array is incremented by 1

#endif