#include <iostream>
#include <iomanip>

#include "includes/two_d_pointers/two_d_pointers.h"

using namespace std;

int main(int argv, char **argc)
{
    int row = 3;
    int col = 4;

    // allocate a two-d array of row 3 col 4
    int **main_ptr = allocate_two_d<int>(3, 4);
    main_ptr = fill_two_d(main_ptr, row, col);

    cout << "Print Array: \n";
    print_two_d(main_ptr, row, col);
    cout << endl;

    // after shift col left
    cout << "After shift column left at index 1: \n\n";
    shift_col_left(main_ptr, row, col, 3);

    print_two_d(main_ptr, row, col);
    cout << "row: " << row << endl;
    cout << "column: " << col << endl;

    // after shift col right
    cout << "After shift column right at index 1: \n\n";
    shift_col_right(main_ptr, row, col, 1);

    print_two_d(main_ptr, row, col);
    cout << "row: " << row << endl;
    cout << "column: " << col << endl;

    cout << "\n=====================" << endl;
    return 0;
}
