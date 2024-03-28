#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;   
    int _height;
    int balance_factor();

    int height();
    int update_height();

    tree_node(T item = T(), tree_node* left = NULL, tree_node* right = NULL):_item(item), _left(left), _right(right){
        //don't forget to set the _height.
        update_height();
    }

    friend ostream& operator <<(ostream& outs, const tree_node<T>& t_node){
        outs << "|" << t_node._item << "|";
    }
};

template <typename T>
int tree_node<T>::balance_factor(){
    //balance factor = height of the left subtree 
        //                        - the height of the right subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
    int left_height = _left ? _left->_height: -1;
    int right_height = _right ? _right->_height: -1;

    return left_height - right_height;
}

template <typename T>
int tree_node<T>::height(){

    // Height of a node is 1 + height of the "taller" child
    //A leaf node has a height of zero: 1 + max(-1,-1)
    int left_height = _left ? _left->_height: -1;
    int right_height = _right ? _right->_height: -1;

    return max(left_height, right_height) + 1;
}

template <typename T>
int tree_node<T>::update_height(){
    //set the _height member variable (call height();)
    _height = height();

    return _height;
}   


#endif