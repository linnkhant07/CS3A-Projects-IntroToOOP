#include "shunting_yard.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/operator.h"
#include <iostream>

using namespace std;

// man proposes god disposes
Operator *castOP(Token *p)
{
    return static_cast<Operator *>(p);
}

Queue<Token *> ShuntingYard::postfix(Queue<Token *> fixMe)
{
    Queue<Token *> queue; // for output
    Stack<Token *> stack; // for operators

    while (!fixMe.empty())
    {
        // pop each token from the queue
        Token *popped = fixMe.pop();

        // if it is an integer or function
        if (popped->type() == 1 || popped->type() == 3)
        {
            queue.push(popped);
            continue; // skip to next loop
        }

        // it is an operator
        // If the token is a left parenthesis, push it onto the stack.
        if (popped->type() == 4)
            stack.push(popped);

        // If the token is a right parenthesis, pop operators from the stack and add them to the output queue until a left parenthesis is found, which is then discarded.
        else if (popped->type() == 5)
        {
            Token *temp = stack.pop();
            while (temp->type() != 4)
            {
                queue.push(temp);
                temp = stack.pop();
            }
        }

        // If the operator on top of the stack is left paren
        else if (!stack.empty() && stack.top()->type() == 4)
        {
            stack.push(popped);
        }

        // If the operator on top of the stack has higher or equal precedence, pop it from the stack and add it to the output queue
        else if (!stack.empty() && castOP(popped)->get_prec() <= castOP(stack.top())->get_prec())
        {
            queue.push(stack.pop());
            stack.push(popped);
        }
        // If the operator on top of the stack has lower precedence, push the new operator onto the stack.
        else
        {
            stack.push(popped);
        }
    }

    // Pop any remaining operators from the stack and add them to the output queue.
    while (!stack.empty())
        queue.push(stack.pop());

    return queue;
}

Queue<Token *> ShuntingYard::postfix()
{
    return postfix(tokenQueue);
}

void ShuntingYard::infix(Queue<Token *> fixMe)
{
    tokenQueue = fixMe;
}
