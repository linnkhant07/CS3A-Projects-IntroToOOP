#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

using namespace std;

#include "../../includes/heap/heap.h"
#include "../../includes/heap/pqueue.h"

bool print_heap(Heap<int> heap){

    int* arr = heap.heap_array();

    for (int i = 0; i < heap.size(); i++)
    {
        cout <<"|"<< arr[i];
    }
    delete[] arr;
}

bool test_heap_insert(bool debug = false)
{
  if(debug){
    Heap<int> h;
    
    
    h.insert(30);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(40);


    print_heap(h);


    cout << endl;

    cout << h.top() << endl;


  }

  return true;

}

bool test_big_child_index(bool debug = false)
{
  if(debug){
    	Heap<int> h;

      h.insert(30);
      cout << h << endl;
      h.insert(10);
      cout << h << endl;
      h.insert(20);
      cout << h << endl;
      h.insert(5);
      cout << h << endl;
      h.insert(40);
      cout << h << endl;
      h.insert(3);
      cout << h << endl;
      h.insert(-1);
      cout << h << endl;
      print_heap(h);
      cout << endl;
      cout << "Big child index is " << h.big_child_index(0) << endl;
      cout << "Big child index is " << h.big_child_index(1) << endl;
      cout << "Big child index is " << h.big_child_index(2) << endl;


  }

  return true;

}

bool test_heap_remove(bool debug = false)
{
  if(debug){
    	Heap<int> h;

      h.insert(40);
      h.insert(40);
      h.insert(40);
      h.insert(10);

      cout << h;
      cout << endl;
      
      const int root = 0;
      if(h.verify()) {
        cout << "Verified" << endl;
      }

      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      cout << "After removing: " << h.remove() << endl;
      cout << h << endl;
      
  }

  return true;

}

bool test_PQ_pop(bool debug = false)
{
  if(debug){
    PQueue<string> pq;
    cout << "Priority Queue Test: " <<endl;

    pq.push("bill", 2);
    pq.push("Marie", 0);
    pq.push("sam after bill", 2);
    pq.push("Kathy tarde", 6);
    pq.push("Jose later", 8);
    pq.push("bill the second", 2);
    pq.print_tree();

     while (!pq.is_empty()){
        cout<<"POPPED: "<<pq.pop()<<endl;
        pq.print_tree();
    }
  }

  return true;

}

TEST(TEST_HEAP, TestHeapInsert) {

  EXPECT_EQ(1, test_heap_insert(false));

}

TEST(TEST_HEAP, TestBigChild) {

  EXPECT_EQ(1, test_big_child_index(false));

}

TEST(TEST_Heap, TestHeapRemove) {

  EXPECT_EQ(1, test_heap_remove(false));

}

TEST(TEST_PQ, TestPQPop) {

  EXPECT_EQ(1, test_PQ_pop(true));

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

