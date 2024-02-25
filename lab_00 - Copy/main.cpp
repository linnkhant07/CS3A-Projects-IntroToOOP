/*
 * Author: Linn Khant Thuya
 * Project: Setting up for the semester
 * Purpose: To set up the machines for class, famialiarize with git hub and version control
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argv, char **argc)
{
    cout << "\n\n"
         << endl;

    char arr1[10] = {'a', 'b', 'c', 'd'};
    char *p1 = arr1;
    char *p2 = arr1 + 5;

    *p1 = *p2;

    cout << "p1: " << *p1 << endl;
    cout << "hi";

    cout << "\n\n\n=====================" << endl;
    return 0;
}
