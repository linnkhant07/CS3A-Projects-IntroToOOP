#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include "assert.h"
#include <iostream>
#include <string>

using namespace std;

const int MINIMUM_CAPACITY = 3;

template <class T>
T *allocate(int capacity = MINIMUM_CAPACITY)
{
    // create a dynamic array of size "capacity"
    T *arr = new T[capacity];
    return arr; // return the pointer to that dynamic array
}
// allocate 'capacity'
//       elements.
//   return array

template <class T>
void copy_array(T *dest, const T *src, int many_to_copy)
{
    // create a walker that points to the start of the src array
    const T *walker_src = src;

    // create a walker that points to the start of the dest array
    T *walker_dest = dest;

    // iterate through the arrays
    for (int i = 0; i < many_to_copy; i++, walker_src++, walker_dest++)
    {
        *walker_dest = *walker_src; // anything at src will be assigned to
                                    // the variable walker_dest is pointing at
    }

} // copy from src to dest

template <class T>
T *reallocate(T *a, int size, int capacity)
{
    T *arr_new = new T[capacity]; // create a new dynamic array of size "capacity"
    copy_array(arr_new, a, size); // copy the src array into the new array

    // delete the src array
    delete a;

    return arr_new; // return the pointer to the new array
} // take array, resize it
  //   return new array.
  //   delete old array

template <class T>
void print_array(T *a, int size, int capacity = 0)
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

} // prints
  //   (size/capacity)
  //   for debugging

template <class T>
void print(T *a, unsigned int how_many)
{

    // they are the same functions
    print_array(a, how_many);

} // print array

template <class T>
T *search_entry(T *a, int size, const T &find_me)
{

    // create a walker that points to the start of the array
    T *walker = a;

    // iterate over the array and check
    for (int i = 0; i < size; i++, walker++)
    {
        if (*walker == find_me)
        {
            return walker; // return the pointer
        }
    }

    cout << "Element not found in the array";
    return nullptr; // if find_me wasn't found

} // search for 'find me'

template <class T>
int search(T *a, int size, const T &find_me)
{
    // create a walker that points to the start of the array
    T *walker = a;

    // iterate over the array and check
    for (int i = 0; i < size; i++, walker++)
    {
        if (*walker == find_me)
        {
            return i; // return the index
        }
    }

    cout << "Element not found in the array";
    return -1; // if find_me wasn't found

} // search for 'find_me'

template <class T>
void shift_left(T *a, int &size, int shift_here)
{
    // if given index is negative
    if (shift_here < 0)
    {
        cout << "Index cannot be negative";
    }

    // if index is out of range
    else if (shift_here >= size)
    {
        cout << "Index is out of range";
    }

    // if the array is empty
    else if (size == 0)
    {
        cout << "The array is empty";
    }

    else
    {
        // create a walker that points to the index
        T *walker = a + shift_here;

        // create a second walker to that points to to the index
        // that comes after
        T *walker2;

        // shift everything after the index to left
        for (; shift_here < size; shift_here++, walker++)
        {
            walker2 = walker + 1;
            *walker = *walker2; // the variable walker is pointing to will
                                // be replaced by the element that comes after
        }

        // reduce the size of the array
        size--;
    }

} // shift left @ pos:
  //     erases @ pos
template <class T>
void shift_left(T *a, int &size, T *shift_here)
{
    // calculate distance from the first element of the array and the shift_here element
    int distance = shift_here - a;

    shift_left(a, size, distance); // recall the already defined function
} // shift left @ pos:
  //     erases @ pos

template <class T>
void shift_right(T *a, int &size, int shift_here)
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
}; // shift right:
   //       make a hole

template <class T>
void shift_right(T *a, int &size, T *shift_here)
{
    // calculate distance from the first element of the array and the shift_here element
    int distance = shift_here - a;

    shift_right(a, size, distance); // recall the already defined function
};                                  // shift right:
                                    //    make a hole

template <class T>
T *copy_array(const T *src, int size)
{
    T *arr_copy = new T[size];       // create a dynamic array of size "size"
    copy_array(arr_copy, src, size); // copy the src array into the arr_copy

    return arr_copy;
}; // return a
   //   copy of src

template <class T>
string array_string(const T *a, int size)
{
    char character; // if it was array of characters
    // initialize the result string
    string result = "";

    // create a walker that walks through the array
    const T *walker = a;

    // iterate through the array
    for (int i = 0; i < size; i++, walker++)
    {
        // if the element is a character
        if (isalpha(*walker))
        {
            character = *walker;
            result = result + character + " ";
        }
        // if the element is an int, double or others
        else
        {
            result = result + to_string(*walker) + " ";
        }
    }

    return result;
} // return array
  //   as a string

#endif