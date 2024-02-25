#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
// Files we are testing:
#include "../../includes/delete_repeats/delete_repeats.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_delete_repeats(bool debug = false)
{
  //-----------testing with integer array-----------//
  // initialize an array
  int b[10] = {1, 1, 1, 1, 0, 1};
  int size = 6;
  cout << "\n\noriginal list: ";
  print_array(b, size); // print before delete
  cout << endl;

  int size_unique = 0;
  int *arr_unique = delete_repeats(b, size, size_unique);
  cout << "\n\nunique values: ";
  print_array(arr_unique, size_unique); // print after delete
  cout << endl;

  //-----------testing with double array-----------//
  double arr2[10] = {0.2, 0.2, 3.0};
  size = 3;
  cout << "\n\noriginal list: ";
  print_array(arr2, size);
  cout << endl;

  delete_repeats(arr2, size, size_unique);
  cout << "\n\nunique values: ";
  print_array(arr2, size);
  cout << endl;
  cout << "The size of unique valued array is: " << size << endl;

  delete[] arr_unique;

  return true;
}

TEST(TEST_STUB, TestStub)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_STUB, TestDeleteRepeats)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_delete_repeats(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
