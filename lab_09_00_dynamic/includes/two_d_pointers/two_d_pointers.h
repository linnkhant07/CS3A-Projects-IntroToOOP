#ifndef TWO_D_POINTERS_H
#define TWO_D_POINTERS_H
#include <iostream>
#include <cassert>
#include "../array_pointers/array_pointers.h"

using namespace std;

// precondition: a dynamic 2-d array pointer has been created
template <class T>
T **allocate_two_d(int row, int col)
{
    // allocates spaces of type T pointer, and assigns to a
    // T-pointer pointer
    T **arr = new T *[row]; // T* * means pointer to an T pointer
    T **walker = arr;

    // iterate the arr and allocate space for T pointers
    for (int i = 0; i < row; i++, walker++)
    {
        *walker = new T[col];
    }
    return arr;
}
// postcondition: a dynamic two-d array has been allocated

// precondition: a 2-d array has been created
template <class T>
T **fill_two_d(T **arr, int row, int col)
{
    T **row_walker = arr;
    T *col_walker;
    for (int i = 0; i < row; i++, row_walker++)
    {
        col_walker = *row_walker;
        for (int j = 0; j < col; j++, col_walker++)
        {
            *col_walker = j + 1;
        }
    }
    return arr;
}
// postcondition: 2-d array has been filled

// precondition: a 2-d array has been created
template <class T>
void print_two_d(T **arr, int row, int col)
{
    T **row_walker = arr;
    T *col_walker;
    for (int i = 0; i < row; i++, row_walker++)
    {
        col_walker = *row_walker;
        for (int j = 0; j < col; j++, col_walker++)
        {
            cout << *col_walker << " ";
        }
        cout << endl;
    }
}
// postcondition: 2-d array has been printed

// precondition: a 2-d array has been initialized
template <class T>
void shift_col_left(T **a, int &row, int &col, int shift_here)
{
    // take in a two d array
    T **row_walker = a;
    T *col_walker;

    for (int i = 0; i < row; i++, row_walker++)
    {
        col_walker = *row_walker;
        shift_left(col_walker, col, shift_here);
    }

    // reduce the size of the column
    col--;
}
// postcondition: column from 2-d array shifted left and col reduced

// precondition: a 2-d array has been initialized
template <class T>
void shift_col_right(T **a, int &row, int &col, int shift_here)
{
    // take in a two d array
    T **row_walker = a;
    T *col_walker;

    for (int i = 0; i < row; i++, row_walker++)
    {
        col_walker = *row_walker;
        shift_right(col_walker, col, shift_here);
    }

    // reduce the size of the column
    col++;
}
// postcondition: column from 2-d array shifted right and col increased

#endif