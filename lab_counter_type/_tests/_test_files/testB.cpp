#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/counter_type/counter_type.h"

using namespace std;

bool test_ctor(bool debug = false)
{
  Counter_Type c1(7);
  Counter_Type c2;

  if (debug)
  {
    cout << "c1: " << c1.count() << endl;
    cout << "c2: " << c2.count() << endl;
  }

  if (c1.count() != 7)
  {
    cout << "FAILED: one-argument constructor not working!";
    return false;
  }

  if (c2.count() != 0)
  {
    cout << "FAILED: zero-argument constructor not working!";
    return false;
  }
}

bool test_inc_dec(bool debug = false)
{
  Counter_Type c1(3);

  // increment 7 times
  for (int i = 0; i < 7; i++)
  {
    c1.inc();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 10)
  {
    cout << "c1 should be 10 but " << c1.count() << endl;
    return false;
  }

  // decrement 10 times
  for (int i = 0; i < 10; i++)
  {
    c1.dec();

    if (debug)
    {
      cout << "c1: " << c1.count() << endl;
    }
  }

  if (c1.count() != 0)
  {
    cout << "c1 should be 0 but " << c1.count() << endl;
    return false;
  }
}

bool test_count(bool debug = false)
{
  Counter_Type c;
  bool success = c.inc();

  if (success != true)
  {
    cout << "success should be true but it is false\n";
    cout << "Error: " << c.is_error() << endl;
    return false;
  }

  c.dec();
  success = c.dec();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  success = c.inc();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  if (debug)
  {
    cout << boolalpha << c.is_error() << endl;
    cout << c.count() << endl;
  }
  return true;
}

bool test_is_error(bool debug = false)
{

  Counter_Type c;
  bool success = c.inc();

  if (success != true)
  {
    cout << "success should be true but it is false\n";
    cout << "Error: " << c.is_error() << endl;
    return false;
  }

  c.dec();
  success = c.dec();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  success = c.inc();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  if (debug)
  {
    cout << boolalpha << c.is_error() << endl;
    cout << c.count() << endl;
  }

  return true;
}

bool test_reset(bool debug = false)
{

  Counter_Type c;
  bool success = c.inc();

  if (success != true)
  {
    cout << "success should be true but it is false\n";
    cout << "Error: " << c.is_error() << endl;
    return false;
  }

  c.dec();
  success = c.dec();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  success = c.inc();

  if (success != false)
  {
    cout << "success should be false but it is true\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  if (debug)
  {
    cout << boolalpha << c.is_error() << endl;
    cout << c.count() << endl;
  }

  c.reset();
  if (c.count() != 0)
  {
    cout << "Count should be 0\n";
  }

  success = c.inc();

  if (success != true)
  {
    cout << "success should be true but it is false\n";
    cout << "Error: " << boolalpha << c.is_error() << endl;
    return false;
  }

  return true;
}

TEST(TEST_STUB, TestCTOR)
{

  EXPECT_EQ(1, test_ctor(false));
}

TEST(TEST_STUB, TestIncDec)
{

  EXPECT_EQ(1, test_inc_dec(false));
}

TEST(TEST_STUB, TestCount)
{

  EXPECT_EQ(1, test_count(false));
}

TEST(TEST_STUB, TestIsError)
{

  EXPECT_EQ(1, test_is_error(false));
}

TEST(TEST_STUB, TestReset)
{

  EXPECT_EQ(1, test_reset(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
