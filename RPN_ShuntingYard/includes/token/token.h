#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>

using namespace std;

class Token
{
    // I know what my type is, I know what my face looks like... or do you?
public:
    Token(const string &s = "?", int type = 0) : _token(s), _type(type) {}
    virtual void Print(ostream &outs) const {};
    int type() { return _type; }
    string token() const { return _token; }

    friend ostream &operator<<(ostream &os, const Token *t)
    {
        t->Print(os);
        return os;
    }

private:
    int _type;
    string _token;
};

/*

    3 + 8  ---->[Shunting Yard ]---> 3 8 +  ------> [RPN] ------->11

*/

#endif
