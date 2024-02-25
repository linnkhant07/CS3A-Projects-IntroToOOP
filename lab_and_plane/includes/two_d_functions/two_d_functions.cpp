#include <iostream>
using namespace std;

int array_size(int *sizes)
{
    int size = 0;
    // walker for sizes
    int *size_walker = sizes;
    // count the rows from sizes
    while (*size_walker >= 0)
    {
        size++;
        size_walker++;
    }
    return size;
}

void print_array(int *a)
{
    int *walker = a;
    while (*walker != -1)
    {
        for (int i = 0; i < *walker; i++)
        {

            cout << "0 ";
        }
        cout << endl;
        walker++;
    }
}

bool index_is_valid(int *sizes, int row, int col)
{

    // possible rows
    int legit_rows = array_size(sizes);

    if (row >= 0 && row < legit_rows)
    {

        int *col_pointer = sizes + row;
        if (col >= 0 && col < *col_pointer)
        {
            return true;
        }
    }

    return false;
}