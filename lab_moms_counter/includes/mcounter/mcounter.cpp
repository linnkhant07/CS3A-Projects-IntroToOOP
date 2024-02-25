#include <iostream>
#include <iomanip>
#include "mcounter.h"

// constructor
MCounter::MCounter() : _count(0), _error(false) // initializer lists
{
}

int MCounter::add(int n)
{
    _count = _count + n;
    _error = is_error();
    if (_error)
        return -9999;
    else
        return _count;
}

int MCounter::add_1()
{
    if (_error)
        return -9999;

    return add(1);
}

int MCounter::add_10()
{
    if (_error)
        return -9999;

    return add(10);
}

int MCounter::add_100()
{
    if (_error)
        return -9999;

    return add(100);
}

int MCounter::add_1000()
{
    if (_error)
        return -9999;

    return add(1000);
}

int MCounter::reset()
{
    _count = 0;
    _error = is_error();
    return 1;
}

int MCounter::count() const
{
    if (_error)
        return -9999;

    return _count;
}

bool MCounter::error() const
{
    return _error;
}

bool MCounter::is_error() const
{
    if (_count > 9999)
        return true;

    else
        return false;
}

// TESTING FOR MAIN
void MCounter::display_counter() const
{
    cout << "-------\n";

    if (_error == false)
        cout << " " << setfill('0') << setw(4) << _count << endl;
    else
        cout << "|ERROR|\n";
    cout << "-------\n";
}

void test_MCounter()
{
    MCounter counter;
    char response;

    do
    {
        cout << "[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it\n";
        cin >> response;

        switch (toupper(response))
        {
        case 'A':
            counter.add_1000();
            break;

        case 'S':
            counter.add_100();
            break;

        case 'D':
            counter.add_10();
            break;

        case 'F':
            counter.add_1();
            break;

        case 'R':
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