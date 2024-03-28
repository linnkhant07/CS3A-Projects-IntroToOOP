#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/list_iterated/list_iterated.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/node/node.h"

using namespace std;

int random_number(int size = 50)
{
  return rand() % size; // random number from 0 to size
}

void *init(List<int> &main)
{
  for (int i = 0; i < 5; i++)
  {
    main.insert_head(random_number());
  }
}

bool test_CTOR(bool debug = false)
{

  if (debug)
  {
    List<int> li;
    li.insert_head(7);
    li.insert_head(6);
    li.Print();

    List<int>::Iterator iter(li.begin());
    cout << "Iterator 1 is " << *iter << endl;
  }

  return true;
}

bool test_insert(bool debug = false)
{
  if (debug)
  {
    List<int> li;
    List<int>::Iterator iter = li.insert_head(7);
    cout << "Iterator is " << *iter << endl;

    iter = li.insert_after(79, iter);
    cout << "Iterator after inserting 79 after 7: " << *iter << endl;

    iter = li.insert_before(83, iter);
    cout << "Iterator after inserting 89 before 7: " << *iter << endl;

    li.Print();
  }

  return true;
}

bool test_operators(bool debug = false)
{
  if (debug)
  {
    List<int> li;
    init(li);

    // dereference
    List<int>::Iterator iter = li.search(34);
    cout << "Found 34: " << *iter << endl;

    // member access
    //----to come later ----

    // inequality
    List<int>::Iterator iter2 = li.search(34);
    if (iter != iter2)
    {
      cout << "They should be equal\n";
      return false;
    }

    // equality
    List<int>::Iterator iter3 = li.search(19);
    if (iter2 == iter3)
    {
      cout << "They should not be equal\n";
      return false;
    }

    // prefix ++
    //[19]->[0]->[34]->[17]->[41]->|||, iter3 -> [0]
    cout << "iter2 before: " << *iter2 << endl;
    cout << "iter3 before: " << *iter3 << endl;
    iter2 = ++iter3;
    cout << "iter2 after: " << *iter2 << endl;
    cout << "iter3 after: " << *iter3 << endl;

    // postfix ++
    cout << "--POSTFIX---\n";
    cout << "iter2 before: " << *iter2 << endl;
    cout << "iter3 before: " << *iter3 << endl;
    iter2 = iter3++;
    cout << "iter2 after: " << *iter2 << endl;
    cout << "iter3 after: " << *iter3 << endl;
  }

  return true;
}

TEST(TEST_LIST, testCTOR)
{

  EXPECT_EQ(1, test_CTOR(false));
}

TEST(TEST_LIST, testInsert)
{

  EXPECT_EQ(1, test_insert(false));
}

TEST(TEST_LIST, testOperators)
{

  EXPECT_EQ(1, test_operators(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
