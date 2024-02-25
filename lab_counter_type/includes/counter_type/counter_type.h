#ifndef COUNTER_TYPE_H
#define COUNTER_TYPE_H

#include <iostream>
using namespace std;

// for testing in the main
void test_Counter_Type();

class Counter_Type
{
public:
    Counter_Type();
    Counter_Type(int n);          // set initial value of the counter
    bool inc();                   // increment by one
    bool dec();                   // decrement by one
    bool is_error() const;        // true: the object is in error (underflow)
    bool reset();                 // reset _count to zero and _error to false
    int count() const;            // retrieve the _count
    void display_counter() const; // displays the current count of the object
private:
    int _count;
    bool _error;
};

#endif