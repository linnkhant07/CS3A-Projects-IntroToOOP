#include "rpn.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../shunting_yard/shunting_yard.h"
#include <iostream>

using namespace std;

// man proposes god disposes

void RPN::set_input(Queue<Token *> iniQueue)
{
    postFix = iniQueue;
}
double RPN::operator()(double value)
{
    // DON'T DESTROYY!!!! WE WILL REPEAT THIS
    Stack<Token *> stack; // to store the integers

    while (!postFix.empty())
    {
        Token *temp = postFix.pop();

        // if it is integer
        if (temp->type() == 1)
        {
            stack.push(temp);
        }
        /*if it's function
            check number of arguments
        */

        // if it is function (variable x)
        else if (temp->type() == 3)
        {
            stack.push(new Integer(value));
        }
        // if it is operator
        else
        {
            Token *operand1 = stack.pop();
            Token *operand2 = stack.pop();
            // double num1 = stod(operand1->token());
            // double num2 = stod(operand2->token());
            // double result = castOP(temp)->eval(num2, num1);

            Token *result = castOP(temp)->eval(operand2, operand1);
            double num_result = stod(result->token());
            stack.push(new Integer(num_result));
        }
    }

    // only one double (final result) left
    return stod(stack.pop()->token());
}

/*
function evaluateRPN(expression):
    inputQueue = convertToRPN(expression)   // convert infix expression to RPN using shunting yard algorithm
    stack = empty stack

    while inputQueue is not empty:
        token = dequeue(inputQueue)
        if token is a number:
            push(stack, token)
        else if token is an operator:
            operand2 = pop(stack)
            operand1 = pop(stack)
            result = evaluate(operand1, operand2, token)
            push(stack, result)

    return pop(stack)
*/