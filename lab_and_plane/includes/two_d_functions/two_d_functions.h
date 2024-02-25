#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H
#include <iostream>

using namespace std;

// precondition: 1-d size array created
int array_size(int *sizes);
// postcondition: the length of the array has been returned (excluding -1)

// precondition: 1-d array created
void print_array(int *a);
// postcondition: 1-d array printed

// precondition: user typed in row and col
bool index_is_valid(int *sizes, int row, int col);
// postcondition: validity the [row][col] has been checked

// precondition: 1-d array of sizes have been created
template <class T>
T **allocate_twod(int *sizes)
{
    // variable to keep track of rows (from sizes)
    int row = array_size(sizes);

    // walker for sizes
    int *size_walker = sizes;

    // allocate a two d pointer
    // size is row + 1 because the last spot is for nullptr
    T **twod = new T *[row + 1];
    T **twod_walker = twod;

    for (int i = 0; i < row; i++)
    {
        *twod_walker = new T[*size_walker];
        twod_walker++;
        size_walker++;
    }

    // assign the last available space with nullptr
    T **end_pointer = twod + row;
    *end_pointer = nullptr;

    return twod;
}
// postcondition: a dynamic 2-d array has been created

// precondition: a dynamic 2-d array has been created
template <class T>
T **deallocate_twod(T **twod, int size)
{
    T **twod_walker = twod;
    /*for (int i = 0; i < size; i++, twod_walker++)
    {
        // delete each one d array
        delete[] * twod_walker;
    }*/

    // delete two d array
    // delete[] twod_walker;

    while (*twod_walker != nullptr)
    {
        delete[] * twod_walker;
        twod_walker++;
    }

    delete[] twod;

    return nullptr;
};
// postcondition: a dynamic 2-d array has been deallocated

// precondition: row and col have been checked for validity
template <class T>
T &get_twod(T **twod, int row, int col)
{
    T **row_walker = twod + row;       // points to the row
    T *col_walker = *row_walker + col; // points to the col at the row

    return *col_walker; // return the variable at col_walker
}
// postcondition: variable at [row][col] have been returned

// precondition: row and col have been checked for validity
template <class T>
T read_twod(T **twod, int row, int col)
{
    /*
    // points to the row to be read
    T **row_walker = twod + row;
    // points to the col to be read
    T *col_walker = *row_walker + col;
    */

    T found = get_twod(twod, row, col);
    return found;
}
// postcondition: value at [row][col] have been returned

// precondition: row and col have been checked for validity
template <class T>
void write_twod(T **twod, int row, int col, const T &item)
{
    /*
    // points to the row to be read
    T **row_walker = twod + row;
    // points to the col to be read
    T *col_walker = *row_walker + col;

    *col_walker = item;
    */

    get_twod(twod, row, col) = item;
}
// postcondition: variable at [row][col] have been assigned the value from 'item'

// precondition: a 2-d array created
template <class T>
void init_twod(T **twod, int *sizes, T init_item = T())
{

    T **row_walker = twod;
    int *size_walker = sizes;
    // points to the address inside row_walker
    T *col_walker = *row_walker;

    // while it is not the last row
    while (col_walker != nullptr)
    {

        for (int i = 0; i < *size_walker; i++, col_walker++)
        {
            // assign init_item to the variable
            // that col_walker is pointing to
            *col_walker = init_item;
        }

        row_walker++;
        size_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
    }
}
// postcondition: 2-d array initialzied

// precondition: 2-d array initialized, 1-d array of sizes
template <class T>
bool search_twod(T **twod, int *sizes, const T &key, int &row, int &col)
{
    // variable to keep track of total rows (from sizes)
    int size = array_size(sizes);

    T **row_walker = twod;
    int *size_walker = sizes;
    // points to the address inside row_walker
    T *col_walker = *row_walker;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < *size_walker; j++, col_walker++)
        {
            // check if the indexed variable is the key
            if (*col_walker == key)
            {
                row = i;
                col = j;
                return true;
            }
        }

        row_walker++;
        size_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
    }

    return false;
}
// postcondition: row and col has been set to the found index (if found)

// precondition: precondition: 2-d array initialized, 1-d array of sizes
template <class T>
T *search_twod(T **twod, int *sizes, const T &key)
{
    // variable to keep track of total rows (from sizes)
    int size = array_size(sizes);

    T **row_walker = twod;
    int *size_walker = sizes;
    // points to the address inside row_walker
    T *col_walker = *row_walker;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < *size_walker; j++, col_walker++)
        {
            // check if the indexed variable is the key
            if (*col_walker == key)
            {
                return col_walker;
            }
        }

        row_walker++;
        size_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
    }
    return nullptr;
}
// postcondition: returned a pointer to the item if found, nullptr if not found

// precondition: a 2-d array initialized
template <class T>
void print_twod(T **twod, int *sizes)
{
    T **row_walker = twod;
    // points to the address inside row_walker
    T *col_walker = *row_walker;
    int *size_walker = sizes;

    // while it is not the last row
    while (col_walker != nullptr)
    {
        for (int i = 0; i < *size_walker; i++, col_walker++)
        {
            cout << *col_walker << " ";
        }
        cout << endl;
        row_walker++;
        size_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
    }
}
// postcondition: 2-d array has been printed

// OWN FUNCTIONS NOT IN THE ASSIGNMENT

// precondition: a 2-d array created
// postcondition: 2-d array initialized with a pattern
template <class T>
void init_pattern_twod(T **twod, int *sizes)
{

    T **row_walker = twod;
    int *size_walker = sizes;
    // points to the address inside row_walker
    T *col_walker = *row_walker;

    int j = 0;

    // while it is not the last row
    while (col_walker != nullptr)
    {

        for (int i = 0; i < *size_walker; i++, col_walker++)
        {
            // assign init_item to the variable
            // that col_walker is pointing to
            *col_walker = (j * 10) + i;
        }

        row_walker++;
        size_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
        j++;
    }
}

#endif