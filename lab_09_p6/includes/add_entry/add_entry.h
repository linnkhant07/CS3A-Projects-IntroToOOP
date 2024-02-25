#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include "assert.h"
#include <iostream>
#include <string>

#include "../array_functions/array_functions.h"

using namespace std;

template <class T>
T *add_entry(T *list, const T &new_entry, int &size, int &capacity)
{
    // end if size and capacity are negative
    assert(capacity >= 0);
    assert(size >= 0);
    assert(capacity >= size);

    // if the array is full, double the capacity
    if (size == capacity)
    {
        capacity *= 2;
        list = reallocate(list, size, capacity);
        cout << "\nCapacity is now doubled to " << capacity << endl;
    }

    /* // pointer to the first opening spot in the array
        T *add_here = list + size;
    *add_here = new_entry;

    size++; // increase the size count*/
    append_array(list, size, new_entry);

    return list;

}; // push into the last element of the array

template <class T>
T *remove_entry(T *list, const T &delete_me, int &size, int &capacity)
{
    // search the delete_me element and get its index
    int index = search(list, size, delete_me);

    // remove the element and reduce size
    shift_left(list, size, index);

    // reduce capacity by half if size is 1/4 of capacity
    if (size == capacity / 4)
    {
        capacity = capacity / 2;
        list = reallocate(list, size, capacity);
        cout << "\n Capacity is now reduced to " << capacity << endl;
    }

    return list;

}; // delete first instance of delete_me

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity)
{

    // pointer to the last element of the array
    T *end = list + (size - 1);
    popped = *end; // to keep track of what is popped

    // pop the last element
    shift_left(list, size, end);

    // reduce capacity by half if size is 1/4 of capacity
    if (size <= capacity / 4)
    {
        capacity /= 2;
        list = reallocate(list, size, capacity);
        cout << "\n Capacity is now reduced to " << capacity << endl;
    }

    return list;

}; // pop the last element of the array
// popped will tell which element was popped

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity)
{
    // end if size and capacity are negative
    assert(capacity >= 0);
    assert(size >= 0);
    assert(capacity >= size);

    // if the array is full, double the capacity
    if (size == capacity)
    {
        capacity *= 2;
        list = reallocate(list, size, capacity);
        cout << "\nCapacity is now doubled to " << capacity << endl;
    }
    // pointer to the index to be inserted
    T *index = list + insert_here;

    // shift right at that index
    shift_right(list, size, index);

    // now, assign insert_this at that index
    *index = insert_this;

    return list;

}; // insert an element at insert here

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity)
{

    // shift left at that index
    shift_left(list, size, index);

    // reduce capacity by half if size is 1/4 of capacity
    if (size == capacity / 4)
    {
        capacity = capacity / 2;
        list = reallocate(list, size, capacity);
        cout << "\n Capacity is now reduced to " << capacity << endl;
    }

    return list;

}; // delete an element at index

#endif