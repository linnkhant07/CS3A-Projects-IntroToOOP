#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/rational/rational.h"
using namespace std;

bool test_CTOR(bool debug = false)
{
  Rational r;
  if (r.get_denom() != 1 || r.get_num() != 0 || r.error() != 0)
  {
    cout << "No-Argument CTOR not working\n";
    return false;
  }

  Rational r2(7);
  if (r2.get_denom() != 1 || r2.get_num() != 7 || r2.error() != 0)
  {
    cout << "One-Argument CTOR not working\n";
    return false;
  }

  Rational r3(2, 5);
  if (r3.get_denom() != 5 || r3.get_num() != 2 || r3.error() != 0)
  {
    cout << "Two-Argument CTOR not working\n";
    return false;
  }

  return true;
}

bool test_set_get_num(bool debug = false)
{
  Rational r;
  r.set_num(2);
  if (r.get_num() != 2 || r.error() != 0)
  {
    cout << "set_num(2) not working\n";
    return false;
  }

  r.set_num(0);
  if (r.get_num() != 0 || r.error() != 0)
  {
    cout << "set_num(0) not working\n";
    return false;
  }

  return true;
}

bool test_set_get_denom(bool debug = false)
{
  Rational r;
  r.set_denom(2);
  if (r.get_denom() != 2 || r.error() != 0)
  {
    cout << "set_denom(2) not working\n";
    return false;
  }

  r.set_denom(0);
  if (r.get_denom() != 0 || r.error() != 1)
  {
    cout << "set_denom(0) not working\n";
    return false;
  }

  return true;
}

bool test_errors(bool debug = false)
{
  Rational r;
  r.set_num(0);
  if (r.error() != 0)
  {
    cout << "error() not working properly on .set_num(0)\n";
    return false;
  }

  Rational r1;
  r1.set_denom(0);
  if (r1.error() != 1)
  {
    cout << "error() not working on .set_denom(0)\n";
    return false;
  }

  Rational r2(1, 0);
  if (r2.error() != 1)
  {
    cout << "error() not working on two-argument CTOR\n";
    return false;
  }

  Rational r3;
  r3 = r + r2; // one of the operands is in error
  if (r3.error() != 1)
  {
    cout << "Operation result should be in error if one of the operands is in error\n";
    return false;
  }

  r3 = r - r2; // one of the operands is in error
  if (r3.error() != 1)
  {
    cout << "Operation result should be in error if one of the operands is in error\n";
    return false;
  }

  r3 = r * r2; // one of the operands is in error
  if (r3.error() != 1)
  {
    cout << "Operation result should be in error if one of the operands is in error\n";
    return false;
  }

  r3 = r / r2; // one of the operands is in error
  if (r3.error() != 1)
  {
    cout << "Operation result should be in error if one of the operands is in error\n";
    return false;
  }

  r3 = r1 + r2; // both of the operands are in error
  if (r3.error() != 1)
  {
    cout << "Operation result should be in error if both of the operands are in error\n";
    return false;
  }

  r3 = r + r; // if operands are error free
  if (r3.error() != 0)
  {
    cout << "Operation result should not be in error if none of the operands is in error\n";
    return false;
  }

  return true;
}

bool test_reset(bool debug = false)
{
  Rational r(1, 0); // in error
  r.reset();
  if (r.error() != 0 || r.get_num() != 0 || r.get_denom() != 1)
  {
    cout << "Reset not working\n";
    return false;
  }

  return true;
}

bool test_operators(bool debug = false)
{
  // no-error operands
  Rational r1(1, 2);
  Rational r2(1, 4);
  // error operands
  Rational r3(2, 0);
  Rational r4;
  r4.set_denom(0);

  // for plus
  Rational r = r1 + r2;
  if (r.get_num() != 6 || r.get_denom() != 8 || r.error() != 0)
  {
    cout << "+ operator not working for two legal operands\n";
    return false;
  }

  r = r1 + r3;
  if (r.error() != 1)
  {
    cout << "+ operator not working for one illegal operand\n";
    return false;
  }

  r = r3 + r4;
  if (r.error() != 1)
  {
    cout << "- operator not working for one illegal operand\n";
    return false;
  }

  // for minus
  r = r1 - r2;
  if (r.get_num() != 2 || r.get_denom() != 8 || r.error() != 0)
  {
    cout << "- operator not working for two legal operands\n";
    return false;
  }

  r = r2 - r1;
  if (r.get_num() != -2 || r.get_denom() != 8 || r.error() != 0)
  {
    cout << "- operator not working for two legal operands\n";
    return false;
  }

  r = r1 - r3;
  if (r.error() != 1)
  {
    cout << "- operator not working for one illegal operand\n";
    return false;
  }

  r = r3 - r4;
  if (r.error() != 1)
  {
    cout << "- operator not working for one illegal operand\n";
    return false;
  }

  // for multiplication
  r = r1 * r2;
  if (r.get_num() != 1 || r.get_denom() != 8 || r.error() != 0)
  {
    cout << "* operator not working for two legal operands\n";
    return false;
  }

  r = r1 * r3;
  if (r.error() != 1)
  {
    cout << "* operator not working for one illegal operand\n";
    return false;
  }

  r = r3 * r4;
  if (r.error() != 1)
  {
    cout << "* operator not working for one illegal operand\n";
    return false;
  }

  // for division
  r = r1 / r2;
  if (r.get_num() != 4 || r.get_denom() != 2 || r.error() != 0)
  {
    cout << "/ operator not working for two legal operands\n";
    return false;
  }

  r = r1 / r3;
  if (r.error() != 1)
  {
    cout << "/ operator not working for one illegal operand\n";
    return false;
  }

  r = r3 * r4;
  if (r.error() != 1)
  {
    cout << "/ operator not working for one illegal operand\n";
    return false;
  }

  return true;
}

TEST(TEST_RATIONAL, TestCTOR)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_CTOR(false));
}

TEST(TEST_RATIONAL, TestSetGetNum)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_set_get_num(false));
}

TEST(TEST_RATIONAL, TestSetGetDenom)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_set_get_denom(false));
}

TEST(TEST_RATIONAL, TestErrors)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_errors(false));
}

TEST(TEST_RATIONAL, TestReset)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_reset(false));
}

TEST(TEST_RATIONAL, TestOpeators)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_operators(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
