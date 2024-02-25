#include "gtest/gtest.h" //Jan 26 2023 9:03 AM - clean reconfigured everything
#include <iostream>
#include <iomanip>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/add_entry/add_entry.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_add_entry(bool debug = false)
{
  cout << "\n---------------test_add_entry()---------------\n";
  int size = 0;
  int capacity = 2;
  // create an array and allocate 2 spaces
  int *arr = allocate<int>(capacity);

  // fill the array
  for (int i = 0; i < 3; i++)
    arr = add_entry(arr, i, size, capacity);

  if (size != 3)
  {
    cout << "Size is supposed to be to 3 but instead, it is " << size << endl;
    return false;
  }

  if (capacity != 4)
  {
    cout << "Capacity is supposed to be 4 but instead, it is " << capacity << endl;
    return false;
  }

  print_array(arr, size, capacity);
  cout << endl;

  return true;
}

bool test_remove_entry(bool debug = false)
{
  cout << "\n---------------test_remove_entry()---------------\n";
  int size = 0;
  int capacity = 2;
  // create an array and allocate 2 spaces
  int *arr = allocate<int>(capacity);

  // fill the array
  for (int i = 0; i < 3; i++)
    arr = add_entry(arr, i, size, capacity);
  //(3/4) [0,1,2]
  arr = add_entry(arr, 3, size, capacity);
  arr = add_entry(arr, 2, size, capacity);
  //(5/8) [0,1,2,3,2]

  // remove first instance of 2
  arr = remove_entry(arr, 2, size, capacity);
  //(4/8) [0,1,3,2]

  if (size != 4)
  {
    cout << "Size is supposed to be to 4 but instead, it is " << size << endl;
    return false;
  }

  if (capacity != 8)
  {
    cout << "Capacity is supposed to be 8 but instead, it is " << capacity << endl;
    return false;
  }

  if (search(arr, size, 2) != 3)
  {
    cout << "2 is supposed to be found at index 3 but, it is found at " << search(arr, size, 2);
    return false;
  }

  print_array(arr, size, capacity);
  cout << endl;

  return true;
}

bool test_remove_last_entry(bool debug = false)
{
  cout << "\n---------------test_remove_last_entry()---------------\n";
  int size = 0;
  int capacity = 2;
  // create an array and allocate 2 spaces
  int *arr = allocate<int>(capacity);

  // fill the array
  for (int i = 0; i < 3; i++)
    arr = add_entry(arr, i, size, capacity);
  //(3/4) [0,1,2]
  arr = add_entry(arr, 3, size, capacity);
  arr = add_entry(arr, 2, size, capacity);
  //(5/8) [0,1,2,3,2]

  int popped;
  // delete 3 elemets from the array
  for (int i = 0; i < 3; i++)
  {
    arr = remove_last_entry(arr, popped, size, capacity);
    cout << popped << " was popped! \n";
  }

  //(2/4)[0,1]
  if (size != 2)
  {
    cout << "Size is supposed to be to 2 but instead, it is " << size << endl;
    return false;
  }

  if (capacity != 4)
  {
    cout << "Capacity is supposed to be 4 but instead, it is " << capacity << endl;
    return false;
  }

  print_array(arr, size, capacity);
  cout << endl;

  return true;
}

bool test_insert_entry(bool debug = false)
{
  cout << "\n---------------test_insert_entry()---------------\n";
  int size = 0;
  int capacity = 2;
  // create an array and allocate 2 spaces
  int *arr = allocate<int>(capacity);

  // fill the array
  for (int i = 0; i < 5; i++)
    arr = add_entry(arr, i, size, capacity);
  //(5/8) [0,1,2,3,4]

  arr = insert_entry(arr, 711, 2, size, capacity);
  arr = insert_entry(arr, 2023, 0, size, capacity);
  //(7/8) [2023,0,1,711,2,3,4]

  if (search(arr, size, 711) != 3)
  {
    cout << "711 is supposed to be found at index 3 but, it is found at " << search(arr, size, 2) << endl;
    print_array(arr, size, capacity);
    return false;
  }

  if (size != 7)
  {
    cout << "Size is supposed to be to 7 but instead, it is " << size << endl;
    return false;
  }

  if (capacity != 8)
  {
    cout << "Capacity is supposed to be 8 but instead, it is " << capacity << endl;
    return false;
  }

  print_array(arr, size, capacity);
  cout << endl;

  return true;
}

bool test_erase_entry(bool debug = false)
{
  cout << "\n---------------test_erase_entry()---------------\n";
  int size = 0;
  int capacity = 2;
  // create an array and allocate 2 spaces
  int *arr = allocate<int>(capacity);

  // fill the array
  for (int i = 0; i < 3; i++)
    arr = add_entry(arr, i, size, capacity);
  //(3/4) [0,1,2]
  arr = add_entry(arr, 3, size, capacity);
  arr = add_entry(arr, 2, size, capacity);
  //(5/8) [0,1,2,3,2]

  // remove index 1 and 2
  arr = erase_entry(arr, 1, size, capacity);
  arr = erase_entry(arr, 2, size, capacity);
  //(3/8) [0,2,2]

  if (size != 3)
  {
    cout << "Size is supposed to be to 3 but instead, it is " << size << endl;
    return false;
  }

  if (capacity != 8)
  {
    cout << "Capacity is supposed to be 8 but instead, it is " << capacity << endl;
    return false;
  }

  if (search(arr, size, 2) != 1)
  {
    cout << "2 is supposed to be found at index 1 but, it is found at " << search(arr, size, 2) << endl;
    return false;
  }

  print_array(arr, size, capacity);
  cout << endl;

  return true;
}

TEST(TEST_STUB, TestStub)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_ARRAY, TestAddEntry)
{

  EXPECT_EQ(1, test_add_entry(false));
}

TEST(TEST_ARRAY, TestRemoveEntry)
{
  EXPECT_EQ(1, test_remove_entry(false));
}

TEST(TEST_ARRAY, TestRemoveLastEntry)
{
  EXPECT_EQ(1, test_remove_last_entry(false));
}

TEST(TEST_ARRAY, TestInsertEntry)
{
  EXPECT_EQ(1, test_insert_entry(false));
}

TEST(TEST_ARRAY, TestEraseEntry)
{
  EXPECT_EQ(1, test_erase_entry(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
