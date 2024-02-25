#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "operator.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class RightParen : public Token
{
public:
    RightParen() : Token(")", 5) {}
    void Print(ostream &outs) { outs << token(); }
};

#endif