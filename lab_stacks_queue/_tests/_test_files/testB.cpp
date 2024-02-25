#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"

bool test_stack_CTOR(bool debug = false)
{
  if (debug)
  {
    Stack<int> s;
    cout << "s1: " << s << endl;
    s.push(10);
    s.push(20);
    cout << "s1: " << s << endl;

    Stack<int> s2(s);
    cout << "s2: " << s2 << endl;
  }

  return true;
}

bool test_stack_assign(bool debug = false)
{
  if (debug)
  {
    Stack<int> s;
    cout << "s1: " << s << endl;
    s.push(10);
    s.push(20);
    cout << "s1: " << s << endl;

    Stack<int> s2;
    s2.push(-1);
    s2.push(-2);
    s2.push(-3);
    cout << "s2: " << s2 << endl;

    s = s2;
    cout << "s1: " << s << endl;
    cout << "s2: " << s2 << endl;

    Stack<int> s3;
    s2 = s3;
    cout << "s2: " << s2 << endl;
  }
  return true;
}

bool test_stack_pushpop(bool debug = false)
{
  if (debug)
  {
    Stack<int> s;
    cout << s << endl;

    cout << "Push 3: ";
    s.push(3);
    cout << s << endl;

    cout << "Push 2: ";
    s.push(2);
    cout << s << endl;

    cout << "Push 1: ";
    s.push(1);
    cout << s << endl;

    int popped = s.pop();
    cout << "popped: " << popped << endl;
    cout << s << endl;

    popped = s.pop();
    cout << "popped: " << popped << endl;
    cout << s << endl;

    popped = s.pop();
    cout << "popped: " << popped << endl;
    cout << s << endl;
  }
  return true;
}

bool test_queue_CTOR(bool debug = false)
{
  if (debug)
  {
    Queue<int> q;
    cout << "q1: " << q << endl;
    q.push(10);
    q.push(20);
    cout << "q1: " << q << endl;

    Queue<int> q2(q);
    cout << "q2: " << q2 << endl;
  }

  return true;
}

bool test_queue_assign(bool debug = false)
{
  if (debug)
  {
    Queue<int> q;
    cout << "q1: " << q << endl;
    q.push(10);
    q.push(20);
    cout << "q1: " << q << endl;

    Queue<int> q2;
    q2.push(-1);
    q2.push(-2);
    q2.push(-3);
    cout << "q2: " << q2 << endl;

    q = q2;
    cout << "q1: " << q << endl;
    cout << "q2: " << q2 << endl;

    Queue<int> q3;
    q2 = q3;
    cout << "q2: " << q2 << endl;
  }
  return true;
}

bool test_queue_pushpop(bool debug = false)
{
  if (debug)
  {
    Queue<int> q;
    cout << q << endl;

    cout << "Push 3: ";
    q.push(3);
    cout << q << endl;

    cout << "Push 2: ";
    q.push(2);
    cout << q << endl;

    cout << "Push 1: ";
    q.push(1);
    cout << q << endl;

    int popped = q.pop();
    cout << "popped: " << popped << endl;
    cout << q << endl;

    popped = q.pop();
    cout << "popped: " << popped << endl;
    cout << q << endl;

    popped = q.pop();
    cout << "popped: " << popped << endl;
    cout << q << endl;
  }
  return true;
}

TEST(TEST_STUB, TestStackCTOR)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stack_CTOR(false));
}
TEST(TEST_STUB, TestStackAssign)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stack_assign(false));
}
TEST(TEST_STUB, TestStackPushPop)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stack_pushpop(false));
}

TEST(TEST_STUB, TestQueueCTOR)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_queue_CTOR(true));
}

TEST(TEST_STUB, TestQueueAssign)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_queue_assign(false));
}

TEST(TEST_STUB, TestQueuePushPop)
{

  // EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_queue_pushpop(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}
