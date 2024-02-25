#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H
#include "assert.h"
#include "../../includes/array_functions/array_functions.h"
#include <iostream>

using namespace std;

template <class T>
void _append(T a[], int &size, T append_me)
{
    // increments size by 1 and append the append_me value to the index of size
    a[size++] = append_me;
};

template <class T>
int _find(const T a[], int size, T find_me)
{
    // iterate the array
    for (int i = 0; i < size; i++)
    {
        // return the index of the array when find_me is found
        if (a[i] == find_me)
            return i;
    }

    return -1;
};

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
// postcondtion: the duplicate elements in the array have been deleted.

/* NOT WORKING!!!!!!!!
template <class T>
T *delete_repeats(T *arr, int &size, int &size_unique)
{
    // create a dynamic array that is currently empty
    size_unique = 0;
    T *unique = new T[size_unique];

    // walker points to the start of the original array
    T *walker = arr;

    // loop through the original array
    for (int i = 0; i < size; i++, walker++)
    {
        // the element the walker is pointing to
        T at_index = *walker;

        // find if the current element is already in the
        // unique array
        // returned index if true, -1 if false
        int found = _find(unique, size_unique, at_index);

        // if not found
        if (found == -1)
        {
            // append that element to the unique array
            // increases the size in the process
            _append(unique, size_unique, at_index);
        }
    }

    return unique; // dont forget to delete unique
}
*/

#endif