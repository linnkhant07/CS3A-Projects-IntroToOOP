#ifndef PLANE_H
#define PLANE_H
#include <iostream>

using namespace std;

// precondition: 2-d boolean array created
bool **init_plane();
// postcondition: 2-d array has been initialized with false(s)

// precondition: 2-d array initialized
bool reserve(bool **plane, int row, int seat);
// postcondition: the chosen seat becomes true

// precondition: a seat has been reserved
bool cancel(bool **plane, int row, int seat);
// postcondition: the canceled seat becomes false

// precondition: a 2-d array initialzied
void print_plane(bool **plane);
// postcondition: 2-d array of plane has been printed

void plane_menu();

#endif