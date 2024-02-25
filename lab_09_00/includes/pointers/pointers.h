#ifndef POINTERS_H
#define POINTERS_H
#include "assert.h"
#include <iostream>

using namespace std;

// precondition: two pointers of any type are going to be
// put in the arguments
template <typename T>
void swap(T *var1, T *var2)
{
    T temp; // create a pointer to help swap

    temp = *var1; // assign temp with whatever var1 is pointing at

    *var1 = *var2; // assign the value (being pointed by var2) to
                   // whatever var1 is pointing at

    *var2 = temp; // var2 is being dereferenced
                  // assign the value of temp to the place p is pointing to
}
// postcondition: the values at two pointers have been
// swapped with each other

// precondition: a source array has been initialized and
// a pointer is waiting to be assigned a dynamic array
template <class T>
T *copy_array_backwards(const T *src, int many_to_copy)
{
    // allocate a dynamic array with the size of many_to_copy
    //(to act as destination array)
    T *dest = new T[many_to_copy];

    // create a walker that points to the start of the dest array
    T *walker_dest = dest;

    // create a walker that points to the END of the src array
    const T *walker_src = src + (many_to_copy - 1);

    // iterate through the arrays
    for (int i = 0; i < many_to_copy; i++, walker_src--, walker_dest++)
    {
        // NOTICE: walker_src is decrementing since its going backwards

        *walker_dest = *walker_src; // anything at src will be assigned to
                                    // the variable walker_dest is pointing at
    }

    return dest; // return the dynamic array
}
// postcondition: the pointer has been assigned a dynamic array with
// reversed elements of the source array. Source array did not change.

// precondition: an array has been initialized
template <class T>
void print_array(T *a, int size)
{

    // create a walker that points to the start of the array
    T *walker = a;

    cout << "[";
    // iterate over the array and print
    for (int i = 0; i < size; i++, walker++)
    {
        cout << *walker << "|";
    }
    cout << "]\n";
}
// postcondition: the elements of the array are printed

#endif