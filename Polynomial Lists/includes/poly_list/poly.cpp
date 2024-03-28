#include <iostream>
#include <iomanip>
#include <math.h>
#include "../list_sorted/list_sorted.h"
#include "../term/term.h"
#include "poly.h"

using namespace std;

Poly::Poly() : _order(0), _poly(false, true)
{
    // add 0
    Term t(0, 0);
    _poly.insert(t);
}

Poly::Poly(double *term_array, int order) : _order(order), _poly(false, true)
{
    assert(term_array);
    double *walker = term_array;
    for (int i = 0; i < order + 1; i++, walker++)
    {

        Term t(*walker, i);
        _poly.insert(t);
    }

    delete_zeroes();
}

Poly::Poly(const vector<double> &terms) : _poly(false, true), _order(terms.size() - 1)
{
    // if the vector is empty
    if (!terms.size())
    {
        _order = 0;
        _poly.insert(Term(0, 0));
    }

    for (int i = 0; i < terms.size(); i++)
    {
        Term t(terms[i], i);
        _poly.insert(t);
    }

    delete_zeroes();
}
// big three

Poly::Poly(const Poly &copyThis) : _order(copyThis._order), _poly(false, true)
{
    _poly = copyThis._poly;
}

Poly &Poly::operator=(const Poly &RHS)
{
    if (this != &RHS)
    {
        _poly = RHS._poly;
        _order = RHS._order;
    }
    return *this;
}

Poly::~Poly()
{
    // where the hell is clear I forgot
}

Poly &Poly::operator+=(const Term &t)
{
    //_order = _order > t._exp ? _order : t._exp; // bigger exp
    _poly.insert(t);
    delete_zeroes();
}

Poly &Poly::operator*=(const Term &t)
{
    // where is order setting?
    //_order = _order + t._exp;
    List<Term>::Iterator it;
    for (it = _poly.begin(); it != _poly.end(); it++)
    {
        // term * term
        *it *= t;
    }

    delete_zeroes();
}

Poly &Poly::operator+=(const Poly &RHS)
{

    List<Term>::Iterator it;
    for (it = RHS._poly.begin(); it != RHS._poly.end(); it++)
    {
        // Poly + term
        *this += *it;
    }
}

Poly &Poly::operator*=(const Poly &RHS)
{

    Poly hold;
    List<Term>::Iterator it;
    for (it = RHS._poly.begin(); it != RHS._poly.end(); it++)
    {
        hold += (*this * *it);
    }
    *this = hold;
    return *this;
}

Poly &Poly::operator-=(const Poly &RHS)
{
    List<Term>::Iterator it;
    for (it = RHS._poly.begin(); it != RHS._poly.end(); it++)
    {
        // Poly + term
        *this += -(*it);
    }
}

bool operator==(const Poly &left, const Poly &right)
{
    return left._order == right._order;
}

bool operator!=(const Poly &left, const Poly &right)
{
    return left._order != right._order;
}

Poly operator+(const Poly &left, const Poly &right)
{
    Poly result(left);
    result += right;
    return result;
}
Poly operator-(const Poly &left, const Poly &right)
{
    Poly result(left);
    result -= right;
    return result;
}
Poly operator*(const Poly &left, const Poly &right)
{
    Poly result(left);
    result *= right;
    return result;
}

bool Poly::isZero() const
{
    List<Term>::Iterator it = _poly.last_node();
    Term t = *it;
    return t._coef == 0 ? true : false;
}
Poly operator/(const Poly &left, const Poly &right)
{
    Poly result;
    Poly dividend(left);
    Poly zero;

    assert(!right.isZero());
    while (dividend._order >= right._order && !(dividend.isZero()))
    {
        Term temp;
        temp = *(dividend._poly.begin()) / *(right._poly.begin());
        result += temp;
        Poly tp = right * temp;
        dividend -= (right * temp);
    }

    return result;
}
Poly operator%(const Poly &left, const Poly &right)
{
    Poly div = left / right;
    return left - div * right;
}
Poly Poly::operator-() const
{
}

Poly operator+(const Poly &left, const Term &t)
{
    Poly result(left);
    result += t;
    return result;
}
Poly operator*(const Poly &left, const Term &t)
{
    Poly result(left);
    result *= t;
    return result;
}

void Poly::delete_zeroes()
{
    // to make sure [0 x^0]-> ||| even after subtractions
    _poly.insert(Term(0, 0));

    List<Term>::Iterator it;
    for (it = _poly.begin(); it != _poly.last_node(); it++)
    {
        if (it->_coef == 0)
        {
            _poly.Delete(it);
        }
    }

    _order = _poly.begin()->_exp;
    if (_order > 0 && it->_coef == 0)
    {
        _poly.Delete(it);
    }
}

ostream &operator<<(ostream &outs, const Poly &print_me)
{
    List<Term>::Iterator it;
    outs << "[ ";
    for (it = print_me._poly.begin(); it != print_me._poly.end(); it++)
    {
        outs << fixed << setprecision(1) << *it;
    }
    outs << "] ";
    outs << "[" << print_me.order() << "]";
    return outs;
}
istream &operator>>(istream &outs, Poly &read_me)
{
}

const Term &Poly::operator[](const int exp) const
{
}
Term &Poly::operator[](const int exp)
{
}