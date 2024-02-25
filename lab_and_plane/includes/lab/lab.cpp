#include <iostream>
#include "../two_d_functions/two_d_functions.h"

using namespace std;

int **init_lab(int *stations)
{
    int **arr = allocate_twod<int>(stations);
    init_twod(arr, stations, 0);

    return arr;
}

// precondition: assuming the validity of the index has been checked
bool login(int **labs, int lab, int station, int id)
{
    if (read_twod(labs, lab, station) != 0)
    {
        return false;
    }

    else
    {
        get_twod(labs, lab, station) = id;
        return true;
    }
}
bool logout(int **labs, int *sizes, int id)
{
    // search if the user is logged in
    if (search_twod(labs, sizes, id) != nullptr)
    {
        // in case the user is logged in inside multiple stations
        while (search_twod(labs, sizes, id) != nullptr)
        {
            // set 0 to the variable at that index
            *search_twod(labs, sizes, id) = 0;
        }
    }

    // if the user is not logged in
    else
    {
        return false;
    }

    return true;
}

// menu function
void lab_menu()
{
    cout << "----------Lab Menu ----------\n";
    cout << "Currently available lab stations: \n";

    // init
    int lab_sizes[] = {4, 3, 2, -1};
    int *size_walker = lab_sizes;
    int **labs = init_lab(lab_sizes);
    print_twod(labs, lab_sizes);

    char response;
    int id, lab, station;

    do
    {
        cout << "\nlog[i]n    log[o]ut      e[x]it" << endl;
        cout << "input: ";
        cin >> response;

        switch (tolower(response))
        {
        case 'i':
            cout << "---- LOG IN: ------" << endl;
            cout << "labs:          ";
            while (*size_walker != -1)
            {
                cout << *size_walker << " ";
                size_walker++;
            }
            cout << endl;

            // take input
            cout << "id: ";
            cin >> id;
            cout << "lab: ";
            cin >> lab;
            cout << "station: ";
            cin >> station;

            //-1 because users start counting from 1
            if (index_is_valid(lab_sizes, lab - 1, station - 1))
            {
                if (login(labs, lab - 1, station - 1, id))
                {

                    cout << "you are logged in in lab " << lab << ", station: " << station << endl;
                    print_twod(labs, lab_sizes);
                }
                else
                {
                    cout << "lab " << lab << ", station " << station << " is occupied" << endl;
                }
            } // valid index
            else
            {
                cout << "[" << lab << "][" << station << "] is invalid. " << endl;
            }

            break;

        case 'o':
            int found;
            cout << "---- LOG OUT: ------" << endl;
            cout << "id: ";
            cin >> id;

            // if id was in the lab
            if (logout(labs, lab_sizes, id))
            {
                cout << "you have successfully logged out\n";
                print_twod(labs, lab_sizes);
            }

            else
            {
                cout << "you are not logged in. id: " << id;
            }

            break;
        }
    } while (tolower(response) != 'x');
}