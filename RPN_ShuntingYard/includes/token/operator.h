#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <string>
#include "token.h"
#include "constants.h"

using namespace std;

class Operator : public Token
{
public:
    Operator(const string &op) : Token(op, 2) // it is 2 i guess
    {
        set_prec();
    }

    void set_prec();
    int get_prec() { return _prec; }
    Token *eval(Token *left, Token *right);
    void Print(ostream &outs) const { outs << token(); }

private:
    int _prec;
};

#endif