#include <iostream>
#include <iomanip>
#include "includes/lab/lab.h"
#include "includes/plane/plane.h"
#include "includes/two_d_functions/two_d_functions.h"

using namespace std;

int main(int argv, char **argc)
{
    cout << "\n\n"
         << endl;

    char choice;
    cout << "Enter a program [L]ab or [P]lane: ";
    cin >> choice;
    switch (tolower(choice))
    {
    case 'l':
        lab_menu();
        break;

    case 'p':
        plane_menu();
        break;
    }

    cout << "\n\n\n=====================" << endl;
    return 0;
}
