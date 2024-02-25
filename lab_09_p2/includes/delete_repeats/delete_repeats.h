#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H
#include "assert.h"
#include "../../includes/array_functions/array_functions.h"
#include <iostream>

using namespace std;

// precondition: an array has been created.
template <class T>
void delete_repeats(T *arr, int &size)
{
    // create a walker that points to the start of the array
    T *walker = arr;

    // to hold the result from search_entry
    T *result_ptr;

    // iterate through the array
    for (int i = 0; i < size; i++)
    {
        result_ptr = search_entry(arr, size, *walker);

        if (result_ptr == walker)
            walker++; // walker moves on to another index

        else
        {
            // shift left at current index
            shift_left(arr, size, walker);
            // reduce i since size got decremented too
            i--;
        }
    }
}
// postcondtion: the duplicate elements in the array have been deleted

#endif