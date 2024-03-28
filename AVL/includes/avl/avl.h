#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <iomanip>
#include <string>
#include "tree_node.h"
#include "avl_functions.h"

using namespace std;

template <typename T>
class AVL{
public:
    AVL();
    AVL(const T *list, int size = -1);
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    AVL(const AVL<T> &copy_me);
    AVL<T> &operator=(const AVL<T> &rhs);
    ~AVL();
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    bool insert(const T &insert_me);
    bool erase(const T &target);

    bool contains(const T &target) const;

    void clear();
    void clear_all();
    bool empty()const;
    string pre_order() const;
    string in_order() const;
    string post_order() const;

    bool search(const T &target, tree_node<T> *&found_ptr) const;

    void output_inorder(ostream &outs);

    friend ostream& operator <<(ostream& outs, const AVL<T>& tree){
        tree_print_debug(tree._root, 0, outs);
        return outs;
    }
    AVL<T> &operator+=(const AVL<T> &rhs);

private:

    tree_node<T>* _root;
};

template <typename T>
AVL<T>::AVL():_root(NULL){

}

template <typename T>
AVL<T>::AVL(const T *list, int size):_root(NULL){
    
    for(int i = 0; i < size; i++){
        this->insert(list[i]);
    }
}
//. . . . . . . . . . . . . BIG THREE. . . . . . . . . . . . . . . . . .
template <typename T>
AVL<T>::AVL(const AVL<T> &copy_me){
    _root = tree_copy(copy_me._root);
}

template <typename T>
AVL<T>& AVL<T>::operator=(const AVL<T> &rhs){

    //if not self assignment
    if(this != &rhs){

        //delete first
        tree_clear(_root);
        _root = tree_copy(rhs._root);
    }
    
    return *this;
}

template <typename T>
AVL<T>::~AVL(){
    tree_clear(_root);
}
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename T>
bool AVL<T>::insert(const T &insert_me){
    //only insert unique ones
    if(!this->contains(insert_me)){
        tree_insert(_root, insert_me);
        return true;
    }
    
    return false; //there was a duplicate
}

template <typename T>
bool AVL<T>::erase(const T &target){
    return tree_erase(_root, target);
}

template <typename T>
bool AVL<T>::contains(const T &target) const{
    return tree_search(_root, target);
}

template <typename T>
void AVL<T>::clear(){
    //what's the difference?
}

template <typename T>
void AVL<T>::clear_all(){
    tree_clear(_root);
}

template <typename T>
bool AVL<T>::empty()const{
     return !_root;
}

template <typename T>
string AVL<T>::pre_order() const{
    return pre_order_string(_root);
}

template <typename T>
string AVL<T>::in_order() const{
    return in_order_string(_root);
}

template <typename T>
string AVL<T>::post_order() const{
    return post_order_string(_root);
}

template <typename T>
bool AVL<T>::search(const T &target, tree_node<T> *&found_ptr) const{
    return tree_search(target, found_ptr); //need to check
}

template <typename T>
void AVL<T>::output_inorder(ostream &outs){

}

template <typename T>
AVL<T> & AVL<T>::operator+=(const AVL<T> &rhs){
    //prof said don't do it for now
    tree_add(this->_root, rhs._root);
    return *this;
}

#endif