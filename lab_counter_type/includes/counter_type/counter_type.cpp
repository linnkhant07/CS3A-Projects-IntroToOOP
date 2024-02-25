#include <iostream>
#include <iomanip>
#include "counter_type.h"

// constructors
Counter_Type::Counter_Type() : _count(0), _error(false) // initialzier lists
{
}

Counter_Type::Counter_Type(int n)
{
    _count = n;
    _error = is_error(); // check error everytime constructor is executed

} // set initial value of the counter

bool Counter_Type::inc()
{
    _error = is_error();
    // if theres an error
    if (_error)
        return false;

    _count++;
    return true;

} // increment by one

bool Counter_Type::dec()
{
    _count--;

    _error = is_error();
    if (_error)
        return false;
    else
        return true;
} // decrement by one

bool Counter_Type::is_error() const
{
    if (_count < 0)
        return true;

    else
        return false;
} // true: the object is in error (underflow)

bool Counter_Type::reset()
{
    _count = 0;
    _error = is_error();

    return true;
} // reset _count to zero and _error to false
int Counter_Type::count() const
{
    return _count;
}

// FOR TESTING IN MAIN
void Counter_Type::display_counter() const
{
    cout << "-------\n";

    if (_error == false)
        cout << " " << setfill('0') << setw(4) << _count << endl;
    else
        cout << "|ERROR|\n";
    cout << "-------\n";
}

void test_Counter_Type()
{
    Counter_Type counter;
    char response;

    do
    {

        cout << "[+]  [-]     [R]eset:  e[X]it\n";
        cin >> response;

        switch (response)
        {
        case '+':
            counter.inc();
            break;

        case '-':
            counter.dec();
            break;

        case 'r':
            counter.reset();
            break;
        }

        if (response != 'x')
        {
            counter.display_counter();
        }

    } while (response != 'x');

    cout << "END OF PROGRAM\n";
}