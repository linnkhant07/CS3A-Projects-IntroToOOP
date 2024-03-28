#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/avl/avl.h"
#include "../../includes/avl/avl_functions.h"
using namespace std;

bool test_template(bool debug = false){

  if(debug){

  }

  return true;
}

bool test_insert(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
  int size = 20;
  for (int i = 0; i < size; i++)
  {
    a[i] = i;
  }
    root = tree_from_sorted_list(a, 1);
    
    
    tree_print(root);

    
    for (int i = 1; i < 30; i++)
    {
      cout << "Inserting: " << endl;
      tree_insert(root, i);
      tree_print(root);
    }

    string in_order = in_order_string(root);
    cout << "In_order string is " << in_order << endl;
    
  }
  return true;
}

bool test_AVL_CTOR(bool debug = false){

  if(debug){
    AVL<int> a0;
    cout << a0 << endl;

    int a[40];
    int size = 5;
  for (int i = 0; i < size; i++)
  {
    a[i] = i;
  }
    AVL<int> a1(a, size);
    cout << "a1 is " << endl << a1 << endl;

    AVL<int> a2(a1);
    cout << "a2 is " << endl << a2 << endl;
  }
  

  return true;
}

bool test_avl_insert(bool debug = false){

  if(debug){
    AVL<int> a0;
    cout << a0 << endl;

    int a[40];
    int size = 5;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
    AVL<int> a1(a, size);
    cout << "a1 is " << endl << a1 << endl;

    a1.insert(1);
    cout << "a1 is " << endl << a1 << endl;

    a0.insert(1);
    cout << "a0 is " << endl << a0 << endl;
  }

  

  return true;
}

bool test_avl_erase(bool debug = false){

  if(debug){
    AVL<int> a0;
    cout << a0 << endl;

    int a[40];
    int size = 30;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
    AVL<int> a1(a, size);
    cout << "a1 is " << endl << a1 << endl;

    a1.insert(30);
    a1.insert(31);

    for (int i = 0; i < size; i++)
    {
      a1.erase(i);
      cout << "After deleting " << i << endl << a1 << endl;
    }
    

  }

  

  return true;
}


bool test_avl_copy_ctor(bool debug = false){
  if(debug){
    AVL<int> a0;
    cout << a0 << endl;

    int a[40];
    int size = 10;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
    AVL<int> a1(a, size);
    cout << "a1 is " << endl << a1 << endl;


    AVL<int> a2(a1);
    cout << "a2 is " << endl << a2 << endl;

    for (int i = 0; i < size; i++)
    {
      a2.erase(i);
      cout << "After deleting " << i << endl << a2 << endl;
    }
    
    cout << "a1: " << a1.in_order() << endl;
    cout << "a2: " << a2.in_order() << endl;

  }

  return true;
}

bool test_big_three(bool debug = false){
    if(debug){
    AVL<int> a0;
    cout << a0 << endl;

    int a[40];
    int size = 30;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
    AVL<int> a1(a, 10);
    cout << "a1 is " << endl << a1 << endl;


    AVL<int>a2;
    a2 = a1;
    cout << "a2 is " << endl << a2 << endl;

    a2 = a2;
    cout << "a2 is " << endl << a2 << endl;
  }

  return true;
}

bool test_rotate_left(bool debug = false){
  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 3;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
      root = tree_from_sorted_list(a, size);
      tree_insert(root, 4);
      tree_insert(root, 3);
      tree_print(root);
     
      rotate(root->_right);
      cout << "after rotation(): " << endl;
      tree_print(root);

  }



  return true;
}

bool test_rotate_right(bool debug = false){
  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 3;
    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }
      root = tree_from_sorted_list(a, size);
      tree_insert(root, -2);
      tree_insert(root, -1);
      tree_print(root);
     
      rotate(root->_right);
      cout << "after rotation(): " << endl;
      tree_print(root);

  }



  return true;
}

bool test_erase_zigzag(bool debug = false){
  if(debug){

    //left heavy zig zag case
    tree_node<int> *root=nullptr;
    int a[40] {0,2,3};
    int size = 3;

    root = tree_from_sorted_list(a, 3);
    //tree_print(root);
    tree_insert(root, 1);
    tree_print(root);

    tree_erase(root, 3);
    cout << "after removing 3: " << endl;
    tree_print(root);
    cout << "--------------------------------" << endl;
      
    //left heavy normal case
    tree_node<int> *root1 =nullptr;
    int a1[40] {1, 2,3};

    root1 = tree_from_sorted_list(a1, 3);
    //tree_print(root1);
    tree_insert(root1, 0);
    tree_print(root1);

    tree_erase(root1, 3);
    cout << "after removing 3: " << endl;
    tree_print(root1);
     cout << "--------------------------------" << endl;

    //right heavy zig zag case
    tree_node<int> *root2=nullptr;
    int a2[40] {0,1,3};

    root2 = tree_from_sorted_list(a2, 3);
    //tree_print(root2);
    tree_insert(root2, 2);
    tree_print(root2);

    tree_erase(root2, 0);
    cout << "after removing 3: " << endl;
    tree_print(root2);
    cout << "--------------------------------" << endl;

    //right heavy normal case
    tree_node<int> *root3=nullptr;
    int a3[40] {0,1,2};

    root3 = tree_from_sorted_list(a3, 3);
    //tree_print(root3);
    tree_insert(root3, 3);
    tree_print(root3);

    tree_erase(root3, 0);
    cout << "after removing 3: " << endl;
    tree_print(root3);
    cout << "--------------------------------" << endl;
    
    //edge case 1
    tree_node<int> *root4=nullptr;
    int a4[40] {5,10,15};

    root4 = tree_from_sorted_list(a4, 3);
    //tree_print(root4);
    tree_insert(root4, 6);
    tree_insert(root4, 16);
    tree_insert(root4, 17);
    tree_insert(root4, 14);
    tree_print_debug(root4);

    tree_erase(root4, 10);
    cout << "after removing 10: " << endl;
    tree_print_debug(root4);
    cout << "--------------------------------" << endl;

  }



  return true;
}



TEST(TEST_AVL, TestInsert) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_insert(false));
}

TEST(TEST_AVL, TestTemplate) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_template(false));
}

TEST(TEST_AVL, TestAVLCTor) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_AVL_CTOR(false));
}

TEST(TEST_AVL, TestAvlInsert) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_avl_insert(false));
}


TEST(TEST_AVL, TestAvlErase) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_avl_erase(false));
}

TEST(TEST_AVL, TestAvlCopyCtor) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_avl_copy_ctor(false));
}

TEST(TEST_AVL, TestBigThree) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_big_three(false));
}

TEST(TEST_AVL, TestRotateLeft) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_rotate_left(false));
}

TEST(TEST_AVL, TestRotateRight) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_rotate_right(false));
}

TEST(TEST_AVL, TestEraseZigZag) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_erase_zigzag(true));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

