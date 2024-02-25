#ifndef ALPHA_H
#define VARIALBE_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class Variable : public Token
{
public:
    Variable() : variable("X"), Token("X", 3) {}
    Variable(string v) : variable(v), Token(v, 3) {}

    void Print(ostream &outs) { outs << token(); }

private:
    string variable;
};

#endif