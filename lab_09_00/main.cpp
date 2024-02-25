#include <iostream>
#include <iomanip>
#include "includes/pointers/pointers.h"

using namespace std;

int main(int argv, char **argc)
{
    cout << "\n\n"
         << endl;

    // the section tests swapping the variables (values at pointers)
    cout << "--------------swap--------------\n";

    // declare integers
    int v1, v2;
    // delcare integer pointers
    int *p1, *p2; // both p1 and p2 can hold the address of an int

    v1 = 8;
    v2 = 21;

    p1 = &v1; // p1 points to v1
    p2 = &v2; // p2 points to v2

    // before swap
    cout << "----before swap----\n";
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    // swap the values at pointers
    // the values of variables will be swapped
    swap(p1, p2);

    // after swap
    cout << "----after swap----\n";
    cout << "v1: " << v1 << endl; // v1 is now 21
    cout << "v2: " << v2 << endl; // v2 is now 8

    // this section tests swapping the pointers
    cout << "--------------swapping the pointers--------------\n";
    cout << "p1 points at: " << p1 << endl;
    cout << "*p1 is v1: " << *p1 << endl;
    cout << "p2 points: " << p2 << endl;
    cout << "*p2 is v2: " << *p2 << endl;

    // currently p1 points at v1 and p2 points at v2
    int *temp; // temp holder to help swap

    // swapping the pointers
    temp = p1; // point temp to where p1 is pointing to
    p1 = p2;   // point p1 to where p2 is pointing to
    p2 = temp; // point p2 to where temp (originally p1) is pointing to

    cout << "\nPointers have been swapped\n\n";

    cout << "p1 points at: " << p1 << endl;
    cout << "*p1 is v2: " << *p1 << endl;
    cout << "p2 points: " << p2 << endl;
    cout << "*p2 is v1: " << *p2 << endl;

    // test for copying an array backwards
    cout << "--------------copying an array but backwards--------------\n";

    // create a soruce array
    int size = 4;
    int arr_src[size] = {1, 2, 3, 4};

    // create a pointer that will be assigned a dynamic array
    int *arr_copy = copy_array_backwards(arr_src, size);
    // arr_copy is now pointing at the first element of the dynamic array
    //  filled with the copy of elements from src (but backwards)

    // after the operation is done, print the results
    cout << "Src array: ";
    print_array(arr_src, size);
    cout << endl;

    cout << "Copy array: ";
    print_array(arr_copy, size);
    cout << endl;

    delete[] arr_copy; // deallocate the dynamic array because
                       // we no longer need it

    cout
        << "\n\n\n=====================" << endl;
    return 0;
}
