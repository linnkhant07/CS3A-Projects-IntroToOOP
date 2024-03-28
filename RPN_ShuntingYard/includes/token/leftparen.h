#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class LeftParen : public Token
{
public:
    LeftParen() : Token("(", 4) {}
    void Print(ostream &outs) { outs << token(); }
};

#endif