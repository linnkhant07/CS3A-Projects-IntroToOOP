#include <iostream>
#include "term.h"
#include "assert.h"
#include <math.h>

using namespace std;

bool double_equals(double left, double right)
{
    return fabs(left - right) < 0.001;
}

Term::Term() : _coef(0), _exp(0)
{
}

Term::Term(double coef, int order) : _coef(coef), _exp(order)
{
}

Term &Term::operator+=(const Term &rhs)
{
    // end if exponents are not equal
    assert(_exp == rhs._exp);
    _coef += rhs._coef;
}

Term &Term::operator-=(const Term &rhs)
{
    // end if exponents are not equal
    assert(_exp == rhs._exp);
    _coef -= rhs._coef;
}
Term &Term::operator*=(const Term &rhs)
{
    _exp += rhs._exp;
    _coef *= rhs._coef;
}
Term &Term::operator/=(const Term &rhs)
{
    _exp -= rhs._exp;
    _coef /= rhs._coef;
}

bool operator==(const Term &lhs, const Term &rhs)
{
    return lhs._exp == rhs._exp;
}

bool operator!=(const Term &lhs, const Term &rhs)
{
    return lhs._exp != rhs._exp;
}

bool operator>(const Term &lhs, const Term &rhs)
{
    return lhs._exp > rhs._exp;
}

bool operator<(const Term &lhs, const Term &rhs)
{
    return lhs._exp < rhs._exp;
}

// used in Poly division operator
Term operator+(const Term &lhs, const Term &rhs)
{
    assert(lhs._exp == rhs._exp);
    Term temp(0, lhs._exp);
    temp._coef = lhs._coef + rhs._coef;

    return temp;
}

Term Term::operator-() const
{
    // negative the coef
    Term temp(0, _exp);
    temp._coef = _coef * -1;

    return temp;

} // unary operator

Term operator-(const Term &lhs, const Term &rhs)
{
    return lhs + (-rhs);
}

Term operator*(const Term &lhs, const Term &rhs)
{
    // powers of the same base combine
    Term temp(0, lhs._exp + rhs._exp);
    temp._coef = lhs._coef * rhs._coef;

    return temp;
}

Term operator/(const Term &lhs, const Term &rhs)
{
    // powers of the same base subtract
    Term temp(0, lhs._exp - rhs._exp);
    temp._coef = lhs._coef / rhs._coef;

    return temp;
}

ostream &operator<<(ostream &outs, const Term &t)
{
    // don't print if the coefficient is empty
    if (t._coef == 0)
        return outs;

    outs << ((t._coef > 0) ? "+" : "");

    if (t._exp == 1)
        outs << t._coef << "X ";
    else if (t._exp == 0)
        outs << t._coef << " ";
    else
        outs << t._coef << "X^" << t._exp << " ";

    return outs;
}

istream &operator>>(istream &ins, Term &t)
{
}
