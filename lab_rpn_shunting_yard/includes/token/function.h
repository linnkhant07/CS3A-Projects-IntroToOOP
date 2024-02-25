#ifndef FUNCTION_H
#define FUNCTION_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class Function : public Token
{
public:
    Function() : variable("X"), Token("X", 3) {}
    Function(string v) : variable(v), Token(v, 3) {}

    void Print(ostream &outs) const { outs << token(); }

private:
    string variable;
};

#endif