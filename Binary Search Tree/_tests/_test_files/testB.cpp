#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/bst_functions/bst_functions.h"
#include "../../includes/bst/bst.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_tree_from_sorted_list(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
  int size = 30;
  for (int i = 0; i < size; i++)
  {
    a[i] = i;
  }
    root = tree_from_sorted_list(a, size);
    tree_print(root);
    //tree_print_debug(root);
    
  }
  return true;
}

bool test_tree_height_balance(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
  int size = 20;
  for (int i = 0; i < size; i++)
  {
    a[i] = i;
  }
    root = tree_from_sorted_list(a, 20);
    
    tree_print_debug(root);
    
  }
  return true;
}

bool test_traversals(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 20;

    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }

    root = tree_from_sorted_list(a, size);
    tree_print(root);
    cout << "Pre-Order: "; pre_order(root); cout << endl;
    cout << "In-Order: "; in_order(root); cout << endl;
    cout << "Post-Order: "; post_order(root); cout << endl;

    cout << "-------------------------" << endl;

    cout << "Pre-Order String: " << pre_order_string(root) << endl;
    cout << "In-Order String: " << in_order_string(root) << endl;
    cout << "Post-Order String: " << post_order_string(root) << endl;
    
  }
  return true;
}

bool test_tree_erase(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 20;

    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }

    root = tree_from_sorted_list(a, 6);
    tree_print_debug(root);

    cout << "Erasing 199 now which is non-existent\n";
    tree_erase(root, 199);
    tree_print_debug(root);

  /*
    for(int i = 0; i < size/2; i++){
      cout << "Erasing " << i + 1 << " now\n";
      tree_erase(root, i + 1);
      test_print_debug(root);
    }*/

    int z = 3;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 5;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 0;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);


    z = 2;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 2;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 0;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 1;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 4;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    z = 4;
    cout << "Erasing " << z << " now\n";
    tree_erase(root, z);
    tree_print_debug(root);

    
  }
  return true;
}

bool test_tree_add(bool debug = false){

  if(debug){
    tree_node<int> *root_1 = nullptr;
    tree_node<int> *root_2 = nullptr;

    int a[40];
    int size = 10;
    for (int i = 0; i < size; i++)
    {
      a[i] = i*2;
    }

    root_1 = tree_from_sorted_list(a, size);
    cout << "Here is the first tree: " << endl;
    tree_print(root_1);

    for (int i = 0; i < size; i++)
    {
      a[i] = i*2+1;
    }
    root_2 = tree_from_sorted_list(a, size);

    cout << "\n\nHere is the second tree: " << endl;
    tree_print(root_2);

    cout << "\nAdding the two trees: " << endl;
    tree_add(root_1, root_2);
    tree_print(root_1);
    cout << endl
        << endl
        << "The other tree is untouched: " << endl;
    tree_print(root_2);
  }
  return true;
}

bool test_count_single_child(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 20;

    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }


    BST<int> bst(a,size);
    cout << bst << endl;
    int count = bst.count_single_child();

    cout << "The number of nodes with only one child: " << count << endl;

  }
  return true;
}

bool test_bst_ctor(bool debug = false){

  if(debug){
    tree_node<int> *root=nullptr;
    int a[40];
    int size = 5;

    for (int i = 0; i < size; i++)
    {
      a[i] = i;
    }


    BST<int> bst(a,size);
    cout << bst << endl;
    
    BST<int> bst2;
    bst2 = bst;
    cout << bst2 << endl;

  }
  return true;
}



TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_BST, Test_Tree_From_Sorted_List) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_tree_from_sorted_list(false));
}

TEST(TEST_BST, Test_HEIGHT_BALANCE) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_tree_height_balance(false));
}

TEST(TEST_BST, TestTraversals) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_traversals(false));
}

TEST(TEST_BST, TestErase) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_tree_erase(false));
}

TEST(TEST_BST, TestTreeAdd) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_tree_add(false));
}

TEST(TEST_BST, TestCountSingleChild) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_count_single_child(false));
}

TEST(TEST_BST, TestBstCtor) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_bst_ctor(true));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

