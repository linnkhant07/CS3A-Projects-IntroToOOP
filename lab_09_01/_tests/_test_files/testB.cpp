#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "../../includes/array_functions/array_functions.h"
using namespace std;

// copied from basic test
void fill_array(int *src, int size)
{
  for (int i = 0; i < size; i++)
  {
    src[i] = i + 1;
  }
}
// copied from basic test

bool test_allocate(bool debug = false)
{
  cout << "\n---------------testing allocate-------------------\n";
  const int size = 5;
  int *arr = allocate<int>(size); // assign a dynamic array

  fill_array(arr, 5); // fill up the array

  // create a walker for the dynamic array
  int *walker = arr;

  // check if the elements are correct
  for (int i = 0; i < size; i++, walker++)
  {

    // if the variable walker is pointing to is not equal to i + 1
    if (*walker != i + 1)
    {

      cout << (i + 1) << "is supposed to be found at i[" << i << "] but "
           << *walker << "was found instead";

      delete[] arr; // delete the dynamic array
      return false;
    }
  }

  print_array(arr, size);
  delete[] arr; // delete the dynamic array

  return true;
}

bool test_reallocate(bool debug = false)
{
  cout << "\n---------------testing reallocate-------------------\n";
  int size = 5;
  int *arr = allocate<int>(size); // assign a dynamic array

  fill_array(arr, size); // fill up the array

  int capacity = 7;                      // new capacity to be updated
  arr = reallocate(arr, size, capacity); // reallocate the array to size 7

  shift_right(arr, size, 1);
  shift_right(arr, size, 1); // fill the two new empty cells

  print_array(arr, size);
  delete[] arr; // delete the dynamic array

  return true;
}

bool test_shift_left(bool debug = false)
{
  cout << "\n---------------testing shift_left-------------------\n";

  int shift_here;

  // creates a character array
  int size = 7;
  cout << "Original size of the array is " << size << endl;
  // TO REPLACE WITH DYNAMIC ARRAYS LATER
  char arr[size] = {'g', 'o', 'o', 'd', 'b', 'y', 'e'};

  //-----------------------------------------------------------
  shift_here = 0; // case 1: shift at the start of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift left at " << shift_here << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  if (size != 6)
  {
    cout << "Size was supposed to reduce to 6!";
    return false;
  }

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = size - 1; // case 2: shift at the end of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift left at " << shift_here << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  cout << "Size of the array is now " << size << endl;

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = 3; // case 3: shift in the middle of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift left at " << shift_here << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  cout << "Size of the array is now " << size << endl;

  //-----------------------------------------------------------

  return true;
}

bool test_shift_left2(bool debug = false)
{
  cout << "\n---------------testing shift_left ver 2 -------------------\n";

  int *shift_here, distance;

  // creates a character array
  int size = 7;
  int arr[size] = {0, 1, 2, 3, 4, 5, 6};

  //-----------------------------------------------------------
  shift_here = arr; // case 1: shift at the start of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift left at " << distance << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  if (size != 6)
  {
    cout << "Size was supposed to reduce to 6!";
    return false;
  }

  cout << "Size of the array is now " << size << endl;

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = &arr[size - 1]; // case 2: shift at the end of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift left at " << distance << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  cout << "Size of the array is now " << size << endl;

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = &arr[3]; // case 3: shift in the middle of the array

  // before shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift left at " << distance << ": \n";

  shift_left(arr, size, shift_here);

  // after shift_left
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  cout << "Size of the array is now " << size << endl;

  //-----------------------------------------------------------

  return true;
}

bool test_shift_right(bool debug = false)
{
  cout << "\n---------------testing shift_right-------------------\n";

  int shift_here;

  // creates a character array
  int size = 7;
  char arr[size] = {'g', 'o', 'o', 'd', 'b', 'y', 'e'};

  //-----------------------------------------------------------
  shift_here = 0; // case 1: shift at the start of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift right at " << shift_here << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  if (size != 8)
  {
    cout << "Size was supposed to increment to 8!";
    return false;
  }

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = size - 1; // case 2: shift at the end of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift right at " << shift_here << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;
  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = 3; // case 3: shift in the middle of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Shift right at " << shift_here << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * shift_here); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;
  //-----------------------------------------------------------

  return true;
}

bool test_shift_right2(bool debug = false)
{
  cout << "\n---------------testing shift_right ver 2-------------------\n";

  int *shift_here, distance;

  // creates a character array
  int size = 7;
  int arr[size] = {0, 1, 2, 3, 4, 5, 6};

  //-----------------------------------------------------------
  shift_here = arr; // case 1: shift at the start of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift right at " << distance << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  if (size != 8)
  {
    cout << "Size was supposed to increment to 8!";
    return false;
  }

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = &arr[size - 1]; // case 2: shift at the end of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift right at " << distance << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  //-----------------------------------------------------------

  //-----------------------------------------------------------
  shift_here = &arr[3]; // case 3: shift in the middle of the array

  // before shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // calculate distance from the first element of the array and the shift_here element
  distance = shift_here - arr;
  cout << "Shift right at " << distance << ": \n";

  shift_right(arr, size, shift_here);

  // after shift_right
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // the indicator arrow for visualization
  for (int i = 0; i < (2 * distance); i++)
  {
    cout << " ";
  }
  cout << "^" << endl;

  //-----------------------------------------------------------

  return true;
}

bool test_print_array(bool debug = false)
{
  cout << "\n---------------testing print_array-------------------\n";
  // create an array
  int size = 6;
  int arr[size] = {10, 8, 18, 1, 21, 49};

  print_array(arr, size);
  shift_left(arr, size, 2);
  print_array(arr, size);

  cout << endl;
  return true;
}

bool test_search(bool debug = false)
{
  cout << "\n---------------testing search-------------------\n";
  int found, search_me;
  // create an array
  int size = 6;
  int arr[size] = {10, 8, 18, 1, 21, 49};

  search_me = 10;
  found = search(arr, size, search_me);
  if (found != 0)
  {
    cout << search_me << "is supposed to be at index 0 but found at " << found << endl;
    return false;
  }

  search_me = 49;
  found = search(arr, size, search_me);
  if (found != 5)
  {
    cout << search_me << "is supposed to be at index 5 but found at " << found << endl;
    return false;
  }

  search_me = 1234;
  found = search(arr, size, search_me);
  if (found != -1)
  {
    cout << search_me << "is not in the array. It should not be found at index " << found << endl;
    return false;
  }

  cout << endl;
  return true;
}

bool test_search_entry(bool debug = false)
{
  cout << "\n---------------testing search_entry-------------------\n";
  int *found, search_me, index;
  // create an array
  int size = 6;
  int arr[size] = {10, 8, 18, 1, 21, 49};

  search_me = 10;
  found = search_entry(arr, size, search_me);

  // finding the index by pointer subtraction
  index = found - arr;
  if (index != 0)
  {
    cout << search_me << " is supposed to be at index 0 but found at " << index << endl;
    return false;
  }

  search_me = 49;
  found = search_entry(arr, size, search_me);
  // finding the index by pointer subtraction
  index = found - arr;

  if (index != 5)
  {
    cout << search_me << " is supposed to be at index 5 but found at " << index << endl;
    return false;
  }

  search_me = 1234;
  found = search_entry(arr, size, search_me);

  if (found != nullptr)
  {
    cout << search_me << " is not in the array. Nullptr should be returned, not " << found << endl;
    return false;
  }

  cout << endl;
  return true;
}

bool test_copy_array(bool debug = false)
{
  cout << "\n---------------testing copy_array-------------------\n";
  const int size = 6;

  // create source array
  double src[size] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

  // create dest array
  double dest[size];

  copy_array(dest, src, size);

  cout << "Source array: ";
  print_array(src, size);
  cout << "Destination array: ";
  print_array(dest, size);

  if (dest[1] != 1.0)
  {
    cout << "1.0 is supposed to be at index 1 of the destination array but " << dest[1] << " was found instead.";
    return false;
  }

  cout << endl;
  return true;
}

bool test_copy_array2(bool debug = false)
{
  cout << "\n---------------testing copy_array2 (pointer return)-------------------\n";
  const int size = 6;

  // create source array
  double src[size] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

  // create dest array
  double *dest = copy_array(src, size); // assigns the copied array

  cout << "Source array: ";
  print_array(src, size);
  cout << "Destination array: ";
  print_array(dest, size);

  if (dest[1] != 1.0)
  {
    cout << "1.0 is supposed to be at index 1 of the destination array but " << dest[1] << " was found instead.";
    return false;
  }

  cout << endl;
  return true;
}

bool test_array_string(bool debug = false)
{
  cout << "\n---------------testing array_string-------------------\n";
  int size = 5;
  string result1, result2, result3;

  // create arrays to test
  char arr1[size] = {'T', 'H', 'U', 'Y', 'A'};
  int arr2[size] = {0, 1, 2, 3, 4};
  double arr3[size] = {1.0, 2.0, 3.0, 4.0, 5.0};

  result1 = array_string(arr1, size);
  result2 = array_string(arr2, size);
  result3 = array_string(arr3, size);

  cout << result1 << endl;
  cout << result2 << endl;
  cout << result3 << endl;

  cout << endl;
  return true;
}

TEST(TEST_ARRAY, TestAllocate)
{
  EXPECT_EQ(1, test_allocate(false));
}

TEST(TEST_ARRAY, TestReallocate)
{
  EXPECT_EQ(1, test_reallocate(false));
}

TEST(TEST_ARRAY, TestShiftLeft)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shift_left(false));
}

TEST(TEST_ARRAY, TestShiftLeft2)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shift_left2(false));
}

TEST(TEST_ARRAY, TestShiftRight)
{
  EXPECT_EQ(1, test_shift_right(false));
}

TEST(TEST_ARRAY, TestShiftRight2)
{
  EXPECT_EQ(1, test_shift_right2(false));
}

TEST(TEST_ARRAY, TestPrintArray)
{

  EXPECT_EQ(1, test_print_array(false));
}

TEST(TEST_ARRAY, TestSearchArray)
{

  EXPECT_EQ(1, test_search(false));
}

TEST(TEST_ARRAY, TestSearchEntryArray)
{

  EXPECT_EQ(1, test_search_entry(false));
}

TEST(TEST_ARRAY, TestCopyArray)
{

  EXPECT_EQ(1, test_copy_array(false));
}

TEST(TEST_ARRAY, TestCopyArray2)
{
  EXPECT_EQ(1, test_copy_array2(false));
}

TEST(TEST_ARRAY, TestArrayString)
{

  EXPECT_EQ(1, test_array_string(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
