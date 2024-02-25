#include <iostream>
#include "../two_d_functions/two_d_functions.h"

using namespace std;

bool **init_plane()
{
    // 7 x 4 seats
    int *seats = new int[8]{4, 4, 4, 4, 4, 4, 4, -1};

    bool **arr = allocate_twod<bool>(seats);
    init_twod(arr, seats, false);

    delete[] seats;

    return arr;
}

// precondition: assuming the validity of the index has been checked
bool reserve(bool **plane, int row, int seat)
{

    if (read_twod(plane, row, seat) == false)
    {
        write_twod(plane, row, seat, true);
        return true;
    }

    else
    {
        return false;
    }
}
bool cancel(bool **plane, int row, int seat)
{
    if (read_twod(plane, row, seat) == true)
    {
        get_twod(plane, row, seat) = false;
        return true;
    }

    else
    {
        return false;
    }
}
void print_plane(bool **plane)
{
    // 7 x 4 seats
    int seats[] = {4, 4, 4, 4, 4, 4, 4, -1};
    char alphabets[] = {'A', 'B', 'C', 'D'};
    int plane_size = array_size(seats);

    bool **row_walker = plane;
    // points to the address inside row_walker
    bool *col_walker = *row_walker;
    int *seat_walker = seats;

    cout << "  | A B C D \n";
    cout << "------------\n";
    // while it is not the last row
    for (int i = 0; i < plane_size; i++)
    {
        cout << i + 1
             << " | ";
        for (int j = 0; j < *seat_walker; j++, col_walker++)
        {
            if (*col_walker == true)
            {
                char *alpha_walker = alphabets + j;
                cout << *alpha_walker << " ";
            }

            else
            {
                cout << "X ";
            }
        }
        cout << endl;
        row_walker++;
        seat_walker++;
        // points to the new address inside row_walker
        col_walker = *row_walker;
    }
}

// menu function
void plane_menu()
{
    cout << "----------Plane Menu ----------\n";
    cout << "Currently available seats: \n";

    // seats
    int *seats = new int[8]{4, 4, 4, 4, 4, 4, 4, -1};

    // init
    bool **plane = init_plane();
    print_plane(plane);

    char response, seat;
    int row, col;

    do
    {
        cout << "\n[r]eserve    [c]ancel      e[x]it" << endl;
        cout << "input: ";
        cin >> response;

        switch (tolower(response))
        {
        case 'r':
            cout << "---- RESERVE: ------" << endl;
            cout << "available seats:\n";
            print_plane(plane);

            cout << "row: ";
            cin >> row;
            cout << "seat: ";
            cin >> seat;              // can combine into one line
            col = tolower(seat) - 97; // get the col using ASCII values

            //-1 because users start counting from 1
            if (index_is_valid(seats, row - 1, col))
            {
                if (reserve(plane, row - 1, col))
                {

                    cout << "you reserved the seat " << seat << " at row " << row << endl;
                    print_plane(plane);
                }
                else
                {
                    cout << "the seat " << seat << " at row " << row << " is occupied" << endl;
                }
            } // valid index
            else
            {
                cout << "Seat " << seat << " at row " << row << " is invalid. " << endl;
            }

            break;

        case 'c':
            int found;
            cout << "---- CANCEL: ------" << endl;
            cout << "seats:\n";
            print_plane(plane);

            cout << "row: ";
            cin >> row;
            cout << "seat: ";
            cin >> seat;
            col = tolower(seat) - 97;

            if (index_is_valid(seats, row - 1, col))
            {
                // if the seat had been booked
                if (cancel(plane, row - 1, col))
                {
                    cout << "you have successfully cancelled the booking for seat " << seat << " at row " << row << endl;
                    print_plane(plane);
                }

                else
                {
                    cout << "The seat " << seat << " at row " << row << " is not booked.\n";
                }
            } // valid index
            else
            {
                cout << "Seat " << seat << " at row " << row << " is invalid. " << endl;
            }
            break;
        }
    } while (tolower(response) != 'x');
}