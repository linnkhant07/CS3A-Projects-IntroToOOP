#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <string>
#include <iomanip>
#include "token.h"
#include "constants.h"

using namespace std;

class Integer : public Token
{
public:
    // integer type is 1: these are enums! {INTEGER, OPERATOR}
    Integer(double i = 0) : Token(to_string(i), 1), _value(i) {}
    Integer(const string &n = "0.0") : Token(n, 1), _value(stod(n)) {}
    void int_only() { cout << "hello from integer!"; }
    void Print(ostream &outs) const { outs << fixed << setprecision(2) << _value << " "; }

private:
    double _value;
};

#endif

/*
2. Read each token (usually numbers and operators) from left to right:
        - If the token is a number or variable, add it to the output queue.
        - If the token is an operator, compare its precedence with that of the operator on top of the stack:
        - If the operator on top of the stack has higher precedence, pop it from the stack and add it to the output queue.
        - If the operator on top of the stack has equal or lower precedence, push the new operator onto the stack.
        - If the token is a left parenthesis, push it onto the stack.
        - If the token is a right parenthesis, pop operators from the stack and add them to the output queue until a left parenthesis is found, which is then discarded.

        3. Continue until all tokens have been read.
*/