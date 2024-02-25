#ifndef LAB_H
#define LAB_H
#include <iostream>

using namespace std;

// precondition: 2-d integer array, 1-d integer array have been created
int **init_lab(int *stations);
// postcondition: 2-d integer array has been initialized

// precondition: 2-d array initialized
bool login(int **labs, int lab, int station, int id);
// postcondition:  0 becomes the user's id at the chosen station

// precondition: 2-d array initialized, logged in at a place
bool logout(int **labs, int *sizes, int id);
// postcondition: all the logged-in stations of the user become 0

void lab_menu();

#endif