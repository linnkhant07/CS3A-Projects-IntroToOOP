#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/lab/lab.h"
#include "../../includes/plane/plane.h"
#include "../../includes/two_d_functions/two_d_functions.h"
using namespace std;

bool test_array_size(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};

  if (array_size(sizes) != 4)
  {

    cout << "The size of the array is 4 but " << array_size(sizes) << " was returned\n";
  }

  int sizes2[] = {-1};

  if (array_size(sizes2) != 0)
  {

    cout << "The size of the array is 0 but " << array_size(sizes2) << " was returned\n";
  }

  if (debug)
  {

    cout << array_size(sizes) << endl;
    cout << array_size(sizes2) << endl;
  }

  return true;
}

bool test_allocate_twod(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  if (twod_int[0][3] != 7 || twod_int[1][0] != 7 || twod_int[2][2] != 7 || twod_int[3][5] != 7)
  {
    cout << "All the indexes are supposed to be 7, but something is wrong";
    return false;
  }

  // TESTING WITH CHARACTERS
  char **twod_char = allocate_twod<char>(sizes);
  init_twod(twod_char, sizes, 'm');

  if (twod_char[0][3] != 'm' || twod_char[1][0] != 'm' || twod_char[2][2] != 'm' || twod_char[3][5] != 'm')
  {
    cout << "All the indexes are supposed to be m, but something is wrong";
    return false;
  }

  // TESTING WITH DOUBLES
  double **twod_double = allocate_twod<double>(sizes);
  init_twod(twod_double, sizes, 2.14);

  if (twod_double[0][3] != 2.14 || twod_double[1][0] != 2.14 || twod_double[2][2] != 2.14 || twod_double[3][5] != 2.14)
  {
    cout << "All the indexes are supposed to be 2.14, but something is wrong";
    return false;
  }

  if (debug)
  {
    cout << "twod integers:\n";
    print_twod(twod_int, sizes);

    cout << "twod characters:\n";
    print_twod(twod_char, sizes);

    cout << "twod doubles:\n";
    print_twod(twod_double, sizes);

    // TESTING WITH EMPTY SIZE
    int sizes2[] = {0, -1};
    int **twod_emp = allocate_twod<int>(sizes2);
    init_twod(twod_emp, sizes2, 7);
    cout << "twod empty:\n";
    print_twod(twod_emp, sizes2);
  }

  return true;
}

bool test_deallocate_twod(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  twod_int = deallocate_twod(twod_int, 4);
  // accessing a memory that has been deleted

  return true;
}

bool test_init_twod(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  if (twod_int[0][3] != 7 || twod_int[1][0] != 7 || twod_int[2][2] != 7 || twod_int[3][5] != 7)
  {
    cout << "All the indexes are supposed to be 7, but something is wrong";
    return false;
  }

  if (debug)
  {
    cout << "twod integers:\n";
    print_twod(twod_int, sizes);
    cout << "Trying to access sizes[0][3] which is legal: " << twod_int[0][3] << endl;
    cout << "Trying to access sizes[0][4] which is out of index: " << twod_int[0][4] << endl;
  }

  return true;
}

bool test_print_twod(bool debug = false)
{
  if (debug)
  {
    // TESTING WITH INTEGERS
    int sizes[] = {4, 5, 3, 6, -1};
    int **twod_int = allocate_twod<int>(sizes);
    init_pattern_twod(twod_int, sizes);
    print_twod(twod_int, sizes);
  }

  return true;
}

bool test_read_twod(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_pattern_twod(twod_int, sizes);

  if (read_twod(twod_int, 1, 1) != 11)
  {
    cout << "11 is supposed to be at [1][1] but " << read_twod(twod_int, 1, 1) << "was found instead.";
    return false;
  }

  // TESTING WITH CHARACTERS
  char **twod_char = allocate_twod<char>(sizes);
  init_twod(twod_char, sizes, 'm');

  if (read_twod(twod_char, 0, 3) != 'm')
  {
    cout << "m is supposed to be found at [0][3] but " << read_twod(twod_int, 0, 3) << "was found instead.";
    return false;
  }

  if (debug)
  {
    cout << "twod integers:\n";
    print_twod(twod_int, sizes);

    cout << "twod characters:\n";
    print_twod(twod_char, sizes);
  }

  return true;
}

bool test_write_twod(bool debug = false)
{
  // TESTING WITH INTEGERS
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  write_twod(twod_int, 0, 3, -1);

  if (read_twod(twod_int, 0, 3) != -1)
  {
    cout << "-1 is supposed to be found at [0][3] but " << read_twod(twod_int, 0, 3) << "was found instead.";
  }

  // TESTING WITH CHARACTERS
  char **twod_char = allocate_twod<char>(sizes);
  init_twod(twod_char, sizes, 'm');

  write_twod(twod_char, 0, 3, 'z');
  if (read_twod(twod_char, 0, 3) != 'z')
  {
    cout << "z is supposed to be found at [0][3] but " << read_twod(twod_char, 0, 3) << "was found instead.";
    return false;
  }

  if (debug)
  {
    cout << "Before writing 5 at [3][5]:\n";
    print_twod(twod_int, sizes);

    write_twod(twod_int, 3, 5, 5);

    cout << "After writing 5 at [3][5]:\n";
    print_twod(twod_int, sizes);

    cout << "Before writing x at [0][0]:\n";
    print_twod(twod_char, sizes);

    write_twod(twod_char, 0, 0, 'x');

    cout << "After writing x at [0][0]:\n";
    print_twod(twod_char, sizes);
  }

  return true;
}

bool test_get_twod(bool debug = false)
{
  // initialize a two-d array
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  // set [0][1] to 59
  get_twod(twod_int, 0, 1) = 59;
  if (read_twod(twod_int, 0, 1) != 59)
  {
    cout << "It should be 72 at row 2 col 1 but it was " << read_twod(twod_int, 2, 1);
    return false;
  }

  // check reading
  if (get_twod(twod_int, 0, 0) != 7)
  {
    cout << "twod_int[0][0] should be 7 but it was " << get_twod(twod_int, 0, 0);
    return false;
  }

  if (debug)
  {
    cout << "Before using get_twod:\n";
    print_twod(twod_int, sizes);

    // set [2][1] to 72
    get_twod(twod_int, 2, 1) = 72;
    cout << "After using get_twod: \n";
    print_twod(twod_int, sizes);
  }

  return true;
}

bool test_search_twod1(bool debug = false)
{
  int row, col;
  // initialize a two-d array
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  // set [0][1] to 59
  get_twod(twod_int, 0, 1) = 59;
  search_twod(twod_int, sizes, 59, row, col);
  if (row != 0 || col != 1)
  {
    cout << "Row is supposed to be 0 and Col is supposed to be 1.\n";
    cout << "Row: " << row << endl;
    cout << "Col: " << col << endl;
    return false;
  }

  return true;
}

bool test_search_twod2(bool debug = false)
{
  // initialize a two-d array
  int sizes[] = {4, 5, 3, 6, -1};
  int **twod_int = allocate_twod<int>(sizes);
  init_twod(twod_int, sizes, 7);

  // set [0][1] to 59
  get_twod(twod_int, 0, 1) = 59;
  int *search_ptr = search_twod(twod_int, sizes, 59);
  if (*search_ptr != 59)
  {
    cout << "search_ptr should point to 59 but it points to" << *search_ptr;
    return false;
  }

  return true;
}

bool test_print_array(bool debug = false)
{
  // create a size array
  int sizes[] = {4, 5, 3, 6, -1};

  if (debug)
  {
    // print out rows and columns in 0
    print_array(sizes);
  }

  return true;
}

bool test_index_is_valid(bool debug = false)
{
  // create a size array
  int sizes[] = {4, 5, 3, 6, -1};

  if (index_is_valid(sizes, 0, 0) != true)
  {
    cout << "[0][3] should be valid";
    return false;
  }

  if (index_is_valid(sizes, 3, 5) != true)
  {
    cout << "[3][5] should be valid";
    return false;
  }

  if (index_is_valid(sizes, 4, 0) != false)
  {
    cout << "[4][0] should not be valid";
    return false;
  }

  if (index_is_valid(sizes, 2, 3) != false)
  {
    cout << "[2][3] should not be valid";
    return false;
  }

  return true;
}

bool test_init_lab(bool debug = false)
{
  // create a lab of rows(lab) and columns (stations)
  int stations[] = {3, 4, 5, 1, 3, -1};
  int **labs = init_lab(stations);

  if (get_twod(labs, 2, 4) != 0)
  {
    cout << "Stations[2][4] should be 0 but it is " << get_twod(labs, 2, 4);
  }

  if (debug)
  {
    print_twod(labs, stations);
  }

  return true;
}

bool test_login_logout(bool debug = false)
{
  // create a lab of rows(lab) and columns (stations)
  int stations[] = {3, 4, 5, 1, 3, -1};
  int **labs = init_lab(stations);

  // 1999 takes the seat at [3][2]
  if (debug)
  {
    print_array(stations);
  }

  login(labs, 2, 2, 1999);
  if (read_twod(labs, 2, 2) != 1999)
  {
    cout << "id 1999 is logged in at [2][2] but " << read_twod(labs, 2, 2) << " was found\n";
    return false;
  }

  bool out_is_valid = logout(labs, stations, 1234);

  if (out_is_valid == true)
  {
    cout << "No one is logged in at [1][1] but the log out was successful\n";
    return false;
  }

  out_is_valid = logout(labs, stations, 7012);

  if (out_is_valid == true)
  {
    cout << "7012 one is logged in but the log out was successful\n";
    return false;
  }

  if (debug)
  {
    print_twod(labs, stations);
  }

  return true;
}

bool test_init_plane(bool debug = false)
{

  bool **plane = init_plane();

  if (get_twod(plane, 2, 3) != false)
  {
    cout << "seats[2][3] should be true but it is " << get_twod(plane, 2, 4);
    return false;
  }

  if (debug)
  {
    reserve(plane, 1, 3);
    reserve(plane, 5, 1);

    reserve(plane, 5, 1);
    reserve(plane, 0, 0);
    cancel(plane, 0, 0);

    print_plane(plane);
  }

  return true;
}

bool test_reserve(bool debug = false)
{
  bool **plane = init_plane();
  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  bool valid_reserve;
  int row;
  int col;
  row = 0;
  col = 0;
  valid_reserve = reserve(plane, row, col);

  if (valid_reserve != true)
  {
    cout << "It is reserved at row " << row << " col " << col << " but the seat is empty";
    return false;
  }

  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  row = 6;
  col = 3;
  valid_reserve = reserve(plane, row, col);
  if (valid_reserve != true)
  {
    cout << "It is reserved at row " << row << " col " << col << " but the seat is empty\n";
    return false;
  }
  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  valid_reserve = reserve(plane, row, col);
  if (valid_reserve != false)
  {
    cout << "It is occupied at row " << row << " col " << col << " but the seat was booked again\n";
    return false;
  }
  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  row = 3;
  col = 2;
  valid_reserve = reserve(plane, row, col);
  if (valid_reserve != true)
  {
    cout << "It is reserved at row " << row << " col " << col << " but the seat is empty\n";
    return false;
  }
  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }
}

bool test_cancel(bool debug = false)
{
  // initialize the plane
  bool **plane = init_plane();
  if (debug)
  {
    print_plane(plane);
    cout << endl;
  }

  int row, col;
  bool valid_cancel;
  row = 0;
  col = 0;
  reserve(plane, row, col);
  valid_cancel = cancel(plane, 0, 0);

  if (valid_cancel != true)
  {
    cout << "cancellation of [0][0] should be true but it was false";
    return false;
  }

  row = 6;
  col = 3;
  reserve(plane, row, col);
  valid_cancel = cancel(plane, row, col);

  if (valid_cancel != true)
  {
    cout << "cancellation of [6][3] should be true but it was false";
    return false;
  }

  row = 6;
  col = 3;
  valid_cancel = cancel(plane, row, col);

  if (valid_cancel != false)
  {
    cout << "cancellation of [6][3] should be false but it was true";
    return false;
  }

  return true;
}

TEST(TEST_TWOD, TestAllocateTwoD)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_allocate_twod(false));
}

TEST(TEST_TWOD, TestDeallocateTwoD)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_deallocate_twod(false));
}

TEST(TEST_TWOD, TestInitTwoD)
{

  EXPECT_EQ(1, test_init_twod(false));
}

TEST(TEST_TWOD, TestPrintTwod)
{

  EXPECT_EQ(1, test_print_twod(false));
}

TEST(TEST_TWOD, TestReadTwod)
{

  EXPECT_EQ(1, test_read_twod(false));
}

TEST(TEST_TWOD, TestWriteTwod)
{

  EXPECT_EQ(1, test_write_twod(false));
}

TEST(TEST_TWOD, TestArraySize)
{

  EXPECT_EQ(1, test_array_size(false));
}

TEST(TEST_TWOD, TestGetTwod1)
{

  EXPECT_EQ(1, test_get_twod(false));
}

TEST(TEST_TWOD, TestSearchTwod1)
{

  EXPECT_EQ(1, test_search_twod1(false));
}

TEST(TEST_TWOD, TestSearchTwod2)
{

  EXPECT_EQ(1, test_search_twod2(false));
}

TEST(TEST_TWOD, TestPrintArray)
{

  EXPECT_EQ(1, test_print_array(false));
}

TEST(TEST_TWOD, TestIndexIsValid)
{

  EXPECT_EQ(1, test_index_is_valid(false));
}

TEST(TEST_TWOD, TestInitLab)
{

  EXPECT_EQ(1, test_init_lab(false));
}

TEST(TEST_TWOD, TestLoginLogout)
{

  EXPECT_EQ(1, test_login_logout(false));
}

TEST(TEST_TWOD, TestInitPlane)
{

  EXPECT_EQ(1, test_init_plane(false));
}

TEST(TEST_TWOD, TestReserve)
{

  EXPECT_EQ(1, test_reserve(false));
}

TEST(TEST_TWOD, TestCancel)
{

  EXPECT_EQ(1, test_cancel(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
