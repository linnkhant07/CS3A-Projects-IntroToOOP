#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/list_sorted/list_sorted.h"

void *init(List<int> &main)
{
  for (int i = 0; i < 5; i++)
  {
    // 1,3,5,7...
    main.insert(2 * i + 1);
  }
}

bool test_insert(bool debug = false)
{
  if (debug)
  {
    List<int> list;
    init(list);
    cout << "The initial list is : ";
    list.Print();

    cout << "Add 0: ";
    list.insert(0);
    list.Print();

    cout << "Add 4: ";
    list.insert(4);
    list.Print();

    cout << "Add 11: ";
    list.insert(11);
    list.Print();

    cout << "Add 7: ";
    list.insert(7);
    list.Print();

    cout << "Add 8: ";
    list.insert(8);
    list.Print();

    cout << "Add 0: ";
    list.insert(0);
    list.Print();

    cout << "Add -1: ";
    list.insert(-1);
    list.Print();
  }
  return true;
}

bool test_assignment(bool debug = false)
{

  if (debug)
  {
    List<int> list;
    init(list);
    cout << "The original list is : ";
    list.Print();

    List<int> list2;
    list2 = list;
    cout << "The new list is: ";
    list2.Print();
  }
  return true;
}

TEST(TEST_STUB, TestWTG)
{
  EXPECT_EQ(1, test_insert(true));
}

TEST(TEST_STUB, TestAssignment)
{
  EXPECT_EQ(1, test_assignment(true));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
