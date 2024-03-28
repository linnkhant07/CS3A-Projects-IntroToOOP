#include <iostream>
#include <iomanip>
#include "includes/poly/poly.h"

using namespace std;

// major arithmetic operators
void test_plus(const Poly &p, const Poly &q);
void test_minus(const Poly &p, const Poly &q);
void test_multiply(const Poly &p, const Poly &q);
void test_division(const Poly &p, const Poly &q);
void print_operation(char p, char q, char sign);

int main(int argv, char **argc)
{
    cout << "\n\n----------------------------"
         << endl;

    // P: [+3.0X^3 +2.0X^2 +X +5.0 ]
    // Q: [+4.0X^4 +3.0X^3 +2.0X^2 +X +5.0 ]
    double coefs1[] = {5.0, 1.0, 2.0, 3.0};
    double coefs2[] = {5.0, 1.0, 2.0, 3.0, 4.0};
    Poly p(coefs1, 3);
    Poly q(coefs2, 4);

    // for response
    char response = ' ';

    do
    {
        switch (tolower(response))
        {
        case 'p':
            cout << "[P]: ";
            cin >> p;
            break;

        case 'q':
            cout << "[Q]: ";
            cin >> q;
            break;
        }

        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
        //+
        print_operation('p', 'q', '+');
        test_plus(p, q);
        print_operation('q', 'p', '+');
        test_plus(q, p);
        //-
        print_operation('p', 'q', '-');
        test_minus(p, q);
        print_operation('q', 'p', '-');
        test_minus(q, p);
        //*
        print_operation('p', 'q', '*');
        test_multiply(p, q);
        print_operation('q', 'p', '*');
        test_multiply(q, p);
        // div
        print_operation('p', 'q', '/');
        test_division(p, q);
        print_operation('q', 'p', '/');
        test_division(q, p);

        cout << "[P]  [Q]     e[X]it ";
        cin >> response;
        cout << endl;

    } while (tolower(response) != 'x');

    cout << "\n\n\n----------------------------" << endl;
    return 0;
}

// major arithmetic operators
void test_plus(const Poly &p, const Poly &q)
{
    Poly r = p + q;
    cout << p << " + " << q << endl;
    cout << "      = " << r;

    // if r = p + q then r - q should be equal to p:
    if (r - q == p)
    {
        cout << "VERIFIED" << endl;
    }
    else
    {
        cout << endl
             << "   ***VERIFICATION FAILED" << endl;
        cout << "   r - q: " << r - q << endl;
        cout << "   r - q: " << r - q << "=/=" << p << endl;
    }
}

void test_minus(const Poly &p, const Poly &q)
{
    Poly r = p - q;
    cout << p << " - " << q << endl;
    cout << "      = " << r;

    // if r = p - q then p should be equal to r + q:
    if (r + q == p)
    {
        cout << "VERIFIED" << endl;
    }
    else
    {
        cout << endl
             << "   ***VERIFICATION FAILED" << endl;
        cout << "   r + q: " << r + q << endl;
        cout << "   r + q: " << r + q << "=/=" << p << endl;
    }
}

void test_multiply(const Poly &p, const Poly &q)
{
    Poly r = p * q;
    cout << p << " * " << q << endl;
    cout << "      = " << r;

    // if r = p * q then p should be equal to r / q:
    if (r / q == p)
    {
        cout << "VERIFIED" << endl;
    }
    else
    {
        cout << endl
             << "   ***VERIFICATION FAILED" << endl;
        cout << "   r / q: " << r / q << endl;
        cout << "   r / q: " << r / q << "=/=" << p << endl;
    }
}

void test_division(const Poly &p, const Poly &q)
{
    Poly r = p / q;
    Poly rem = p % q;
    cout << p << " / " << q << endl;
    cout << "      = " << r << "   rem = " << rem;

    // if r = p / q then r * q + p % q should be equal to p:
    if (r * q + p % q == p)
    {
        cout << "VERIFIED" << endl;
    }
    else
    {
        cout << endl
             << "   ***VERIFICATION FAILED" << endl;
        cout << "   r * q: " << r * q << endl;
        cout << "   p % q: " << p % q << endl;
        cout << "   r * q + p % q: " << r * q + p % q << "=/=" << p << endl;
    }
}

void print_operation(char p, char q, char sign)
{
    cout << "\n------- " << p << " " << sign << " " << q << " ----------------------\n";
}
