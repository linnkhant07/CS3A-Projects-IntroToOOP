#include <iostream>
#include "rational.h"
#include <string>

using namespace std;

/*  I WANTED TO SIMPLY THE FRACTIONS
// finds the greatest common denominator between two numbers
// larger int -> num1, smaller -> num2
int findGCD(int num1, int num2)
{
    // euclidean alogrithm to find GCD

    if (num2 == 0)
        return num1;

    else if (num2 > num1)
        return 1; // there is no GCD

    else
        return findGCD(num2, num1 % num2); // recursive until num2 is 0
}*/

Rational::Rational() : _n(0), _d(1), _error(0)
{
}

Rational::Rational(int num, int denom)
{
    set_num(num);
    set_denom(denom);
    _error = is_error();
}

Rational::Rational(int w)
{
    set_denom(1);
    set_num(w);
    _error = is_error();

} // whole number

// mutators / setters
void Rational::set(int num, int denom)
{
    set_num(num);
    set_denom(denom);
    _error = is_error();
}

void Rational::set_num(int n)
{
    _n = n;
}
void Rational::set_denom(int d)
{
    // Any function that alters the denominator of the rational number will have to call is_error() to see if _error code must be set
    _d = d;
    _error = is_error();
}

// accessors / getters
int Rational::get_num() const
{
    return _n;
}
int Rational::get_denom() const
{
    return _d;
}

// error handling routines
int Rational::is_error() const
{
    if (_d == 0)
        return 1; // 1 is the code for denom error
    else
        return 0; // no error
}

int Rational::error() const
{
    // if error is anything other than 0
    if (_error)
        return 1; // 1 represents unsuccessful

    else
        return 0; // 0 represents successful

}; // return error state
string Rational::error_description() const
{
    const int ZERO_DENOM = 1;
    const int NO_ERROR = 0;

    int err_code = is_error();
    switch (err_code)
    {
    case ZERO_DENOM:
        return "Denominator is zero!";
        break;

    case NO_ERROR:
        return "NO ERROR!";
        break;
    }
};
// return a descriptive error message

void Rational::reset()
{
    set_num(0);
    set_denom(1);
    _error = 0;
} // resets number to 0/1 and clears error state

// will return object whose error state is set
//    if one of the operands is in error.

// All operators will have to call the CTOR to return their result. Therefore, if one of the operands is in _error, the operator must ensure the result will be as well.
Rational operator+(const Rational &num1, const Rational &num2)
{
    // create a new Rational
    Rational num3(1, 1);

    // error checking for operands
    if (num1.error() == 1 || num2.error() == 1)
    {
        num3._error = 1;
        return num3;
    }

    // making the denoms equal so that we can combine nums
    int d = (num1._d * num2._d);
    int n = (num1._n * num2._d) + (num2._n * num1._d);
    num3.set(n, d);
    return num3;

    /* TO SIMPLIFY FRACTIONS
    // find gcd to simplify the num3 fraction if we can
    int gcd;
    if (num3._d >= num3._n)
        gcd = findGCD(num3._d, num3._n); // larger number should be at the front

    else
        gcd = findGCD(num3._n, num3._d);

    num3._d /= gcd;
    num3._n /= gcd;

    */
}

Rational operator-(const Rational &num1, const Rational &num2)
{
    // create a new Rational
    Rational num3(1, 1);

    // error checking for operants
    if (num1.error() == 1 || num2.error() == 1)
    {
        num3._error = 1;
        return num3;
    }

    // making the denoms equal so that we can combine nums
    int d = (num1._d * num2._d);
    int n = (num1._n * num2._d) - (num2._n * num1._d);
    num3.set(n, d);
    return num3;
}
Rational operator*(const Rational &num1, const Rational &num2)
{
    // create a new Rational
    Rational num3(1, 1);

    // error checking for operants
    if (num1.error() == 1 || num2.error() == 1)
    {
        num3._error = 1;
        return num3;
    }

    // making the denoms equal so that we can combine nums
    int d = num1._d * num2._d;
    int n = num1._n * num2._n;
    num3.set(n, d);
    return num3;
}
Rational operator/(const Rational &num1, const Rational &num2)
{
    // create a new Rational
    Rational num3(1, 1);

    // error checking for operants
    if (num1.error() == 1 || num2.error() == 1)
    {
        num3._error = 1;
        return num3;
    }

    // making the denoms equal so that we can combine nums
    int d = num1._d * num2._n;
    int n = num1._n * num2._d;
    num3.set(n, d);
    return num3;
}

// will print UNDEFINED if num is in error.
// the insertion operator will output "UNDEFINED" if the rational number is in _error.
// The calling function may call rational::error_description() to get a string containing the error message.
ostream &operator<<(ostream &outs, const Rational &num)
{
    // if there is error
    if (num.error() == 1)
        outs << "UNDEFINED";

    else
        outs << num._n << "/" << num._d;

    return outs;
}
istream &operator>>(istream &ins, Rational &num)
{
    /* I DONT KNOW
    char numer;
    char slash;
    char denom;

    ins.get(numer, 1);
    ins.get(slash, 1);
    ins.get(denom, 1);

    cout << numer << endl;
    // num.set(stoi(numer), stoi(denom)); // using CTOR so that error is checked
    */
    int n, d;
    char slash;
    ins >> n >> slash >> d;
    num.set(n, d);

    return ins;
}

// AUXILLIARY FUNCTIONS
void display_results(Rational r1, Rational r2)
{
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
    cout << "============================================\n";
}

void test_Rational()
{
    Rational r1(3, 4);
    Rational r2(5, 9);
    char response;

    do
    {
        cout << "A: " << r1 << "    B:" << r2 << endl;
        ;
        display_results(r1, r2);
        cout << "[A] [B]   e[X]it\n";
        cin >> response;
        switch (tolower(response))
        {
        case 'a':
            cout << "a: ";
            cin >> r1;
            break;

        case 'b':
            cout << "b: ";
            cin >> r2;
            break;
        }
    } while (tolower(response) != 'x');
}
