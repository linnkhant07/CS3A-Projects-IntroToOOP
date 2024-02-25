#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <math.h>
#include "integer.h"

using namespace std;

void Operator::set_prec()
{
    switch (token()[0])
    {

    case '-':
        _prec = 1;
        break;
    case '+':
        _prec = 1;
        break;
    case '/':
        _prec = 2;
        break;
    case '*':
        _prec = 2;
        break;
    case '^':
        _prec = 3;
        break;
    /*
    case '(':
        _prec = 5;
        break;
    case ')':
        _prec = 6;
        break;*/
    default:
        assert(false);
    }
}

Token *Operator::eval(Token *left, Token *right)
{
    double num_l = stod(left->token());
    double num_r = stod(right->token());

    switch (token()[0])
    {

    case '-':
        return new Integer(num_l - num_r);
    case '+':
        return new Integer(num_l + num_r);
    case '/':
        return new Integer(num_l / num_r);
    case '*':
        return new Integer(num_l * num_r);
    case '^':
        return new Integer(pow(num_l, num_r));
    default:
        assert(false);
    }
}