#ifndef POLY_H
#define POLY_H

#include "../node/node.h"
#include "../list_sorted/list_sorted.h"
#include "../term/term.h"
#include <iostream>
#include <vector>

using namespace std;

class Poly
{
public:
    Poly();
    Poly(double *term_array, int order);
    Poly(const vector<double> &terms);
    // big three
    Poly(const Poly &copyThis);
    Poly &operator=(const Poly &RHS);
    ~Poly();
    // bg3

    Poly &operator+=(const Term &t);
    Poly &operator*=(const Term &t);

    Poly &operator+=(const Poly &RHS);
    Poly &operator*=(const Poly &RHS);
    Poly &operator-=(const Poly &RHS);

    friend bool operator==(const Poly &left, const Poly &right);
    friend bool operator!=(const Poly &left, const Poly &right);
    friend Poly operator+(const Poly &left, const Poly &right);
    friend Poly operator-(const Poly &left, const Poly &right);
    friend Poly operator*(const Poly &left, const Poly &right);
    friend Poly operator/(const Poly &left, const Poly &right);
    friend Poly operator%(const Poly &left, const Poly &right);
    Poly operator-() const;

    friend Poly operator+(const Poly &left, const Term &t);
    friend Poly operator*(const Poly &left, const Term &t);

    friend ostream &operator<<(ostream &outs, const Poly &print_me);
    friend istream &operator>>(istream &outs, Poly &read_me);

    const Term &operator[](const int exp) const;
    Term &operator[](const int exp);
    List<Term> list() const { return _poly; }
    int order() const { return _order; } // I added these
    void delete_zeroes();
    bool isZero() const;

private:
    List<Term> _poly; // descending sorted list
    int _order;
};

#endif