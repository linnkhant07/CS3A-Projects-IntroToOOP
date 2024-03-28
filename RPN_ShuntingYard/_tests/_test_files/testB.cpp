#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
// Files we are testing:

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/token/constants.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
using namespace std;

bool test_shunting_yard(bool debug = false)
{

  if (debug)
  {
    //(5 + 3 * 2 - 1) / (4 - 2) / 3
    Queue<Token *> infix;
    infix.push(new LeftParen());
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(1));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("-"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new Integer(3));

    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++)
    {
      (*it)->Print(cout);
      // cout << setw(3) << (*it)->token();
    }
    cout << endl;
    // 5 3 2 * + 1 - 4 2 - / 3 /
  }
  return true;
}

bool test_rpn(bool debug = false)
{
  if (debug)
  {
    //(5 + 3 * 2 - 1) / (4 - 2) / 3
    Queue<Token *> infix;
    infix.push(new LeftParen());
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(1));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("-"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.push(new Operator("/"));
    infix.push(new Integer(3));

    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    RPN rpn(postfix);
    cout << "(5 + 3 * 2 - 1) / (4 - 2) / 3 = " << rpn() << endl;
    // 1.66667
  }
  return true;
}

bool free_test(bool debug = false)
{
  int x = VARIABLE;
  cout << "x is " << x << endl;
  cout << "free testing\n";
  return true;
}

TEST(TEST, FreeTest)
{
  EXPECT_EQ(1, free_test(true));
}

TEST(TEST_RPN, TestShuntingYard)
{
  EXPECT_EQ(1, test_shunting_yard(false));
}

TEST(TEST_RPN, TestRPN)
{
  EXPECT_EQ(1, test_rpn(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
