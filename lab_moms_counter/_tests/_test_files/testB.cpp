#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/mcounter/mcounter.h"
using namespace std;

bool test_ctor(bool debug = false)
{
  MCounter c;

  if (debug)
  {
    cout << "c1: " << c.count() << endl;
  }

  if (c.count() != 0)
  {
    cout << "FAILED: constructor not working!";
    return false;
  }

  return true;
}

bool test_add(bool debug = false)
{
  MCounter c1;

  // increment 7
  for (int i = 0; i < 7; i++)
  {
    c1.add_1();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 7)
  {
    cout << "c1 should be 7 but " << c1.count() << endl;
    return false;
  }

  // increment 40
  for (int i = 0; i < 4; i++)
  {
    c1.add_10();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 47)
  {
    cout << "c1 should be 47 but " << c1.count() << endl;
    return false;
  }

  // increment 200
  for (int i = 0; i < 2; i++)
  {
    c1.add_100();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 247)
  {
    cout << "c1 should be 247 but " << c1.count() << endl;
    return false;
  }

  // increment 3000
  for (int i = 0; i < 3; i++)
  {
    c1.add_1000();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 3247)
  {
    cout << "c1 should be 3247 but " << c1.count() << endl;
    return false;
  }

  return true;
}

bool test_count_reset(bool debug = false)
{

  MCounter c;
  c.add_100();

  if (c.count() != 100)
  {
    cout << "Count should be 100!\n";
    return false;
  }

  c.reset();
  if (c.count() != 0)
  {
    cout << "Reset is not working\n";
    return false;
  }

  // make it over 9999
  for (int i = 0; i < 10; i++)
  {
    c.add_1000();
  }

  if (c.count() != -9999)
  {
    cout << "Count should be -9999!\n";
    return false;
  }

  c.reset();
  if (c.count() != 0)
  {
    cout << "Reset is not working\n";
    return false;
  }

  return true;
}

bool test_error(bool debug = false)
{

  MCounter c;
  c.add_100();

  if (c.is_error() != false)
  {
    cout << "Error shuld be false!\n";
    return false;
  }

  // make it over 9999
  for (int i = 0; i < 10; i++)
  {
    c.add_1000();
  }

  if (c.is_error() != true)
  {
    cout << "Error should true, count is over 9999!\n";
    return false;
  }

  c.reset();
  if (c.is_error() != false)
  {
    cout << "Error should be false, count is 0!\n";
    return false;
  }

  return true;
}

TEST(TEST_CLASS, TestCTOR)
{

  EXPECT_EQ(1, test_ctor(false));
}

TEST(TEST_CLASS, TestAdd)
{

  EXPECT_EQ(1, test_add(false));
}

TEST(TEST_CLASS, TestCountReset)
{

  EXPECT_EQ(1, test_count_reset(false));
}

TEST(TEST_CLASS, TestError)
{

  EXPECT_EQ(1, test_error(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
