#ifndef AVL_FUNCTIONS_H
#define AVL_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "tree_node.h"

// ---------------- ROTATIONS --------------------------
template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root){

    tree_node<T>* temp = root->_left;
    root->_left = temp->_right;

    temp->_right = root;
    root = temp;

    temp = nullptr;

    //update height of og parent and changed child
    root->_right->update_height();
    root->update_height();
    
    return root;
}

template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root){

    tree_node<T>* temp = root->_right;
    root->_right = temp->_left;

    temp->_left = root;
    root = temp;

    temp = nullptr;

    //update height of og parent and changed child
    root->_left->update_height(); //order here is important - update the child first
    root->update_height();

    return root;
    

}

template <typename T>
tree_node<T>* rotate(tree_node<T>* & root){

    //case 1: right heavy
    if(root->balance_factor() < -1){

        //case 2: zig zag right heavy
        //checking if signs are opposite
        if(abs(root->balance_factor() - root->_right->balance_factor()) > 1){
            //right rotate right child
            rotate_right(root->_right);
        }

        //left rotate self
        return rotate_left(root);
    }

    //case 3: left heavy 
    else if(root->balance_factor() > 1){
        
        //case 4: zig zag left heavy
        if(abs(root->balance_factor() - root->_left->balance_factor()) > 1){
            //left rotate left child
            rotate_left(root->_left);
        }

        //right rotate self
        return rotate_right(root);
    }
    

} //decide which rotate is needed based on balance factor


template <typename T>
void tree_count_single_child(tree_node<T>* &root, int& count){
    //we will do pre-order traversal
    if(root){
        //if has a single child
        if(root->_height == 1 && (!root->_left || !root->_right)){
            count++;
            T child_item = root->_left ? root->_left->_item : root->_right->_item;

            cout << "Node:[" << root->_item << "] -> Child Node [" <<  child_item <<"]" << endl; 
        }

        tree_count_single_child(root->_left, count);
        tree_count_single_child(root->_right, count);
    }
}

//-------------------------------------------------

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){

    //don't add duplicates

    if(root == NULL){
        root = new tree_node<T>(insert_me);
    }

    else if(insert_me < root->_item){
        //insert item into the left subtree
        tree_insert(root->_left, insert_me);
    }

    else{
        tree_insert(root->_right, insert_me);
    }

    root->update_height();
    rotate(root);
}

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    const bool debug = false;

    if(!root){
        if(debug) cout << "tree-search: " << "Not found. root is NULL" << endl;
        return root;
    }

    else if(root->_item == target){
        if(debug) cout << "tree search: " << "found target: [" << root->_item << "]" << endl;
        return root;
    }

    else if(target < root->_item){
        if(debug) cout << "tree_search: going left" << endl;
        return tree_search(root->_left, target);
    }

    else if(target > root->_item){
        if(debug) cout << "tree_search: going right" << endl;
        return tree_search(root->_right, target);
    }

    cout << "How did I get here?!!" << endl;
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr){

    return found_ptr = tree_search(root, target) ? true : false;

}

template<typename T>
void tree_print(tree_node<T>* root, int depth=0,
                                    ostream& outs=cout){
    if(root){
        tree_print(root -> _right, depth + 1);
        outs << setw(4*depth) << "" << "[" << root->_item << "]" << endl;
        tree_print(root->_left, depth+1);
    }                    
}

template<typename T> //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int depth=0,
                                          ostream& outs=cout){

    if(root){
        tree_print_debug(root -> _right, depth + 1);
        outs << setw(4*depth) << "" << "[" << root->_item << ":" << root->_height << " (" << root->balance_factor() << ")]" << endl;
        tree_print_debug(root->_left, depth+1);
    }                                     
}

template <typename T> //clear the tree
void tree_clear(tree_node<T>* &root){
    
    if(root){
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = NULL;
    }
}


template <typename T> //erase rightmost node from the tree -> max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){
    
    //base case
    if(!root->_right) {
        max_value = root->_item;
        cout << "max_value in replace_max() is " << max_value << endl;
        //to help delete
        tree_node<T>* temp = root;
        root = root->_left;

        delete temp;
        temp = nullptr;
    }

    else{
        tree_remove_max(root->_right, max_value);
        //THIS CAUSED ME ERRORS
        root->update_height(); 
    }

    
}

template <typename T> //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){
    
    if(!root){
        return false;
    }

    else if(target > root->_item){
        tree_erase(root->_right, target);
        root->update_height();
        //check along the path after everything is done
        rotate(root);
    }

    else if(target < root->_item){
        tree_erase(root->_left, target);
        root->update_height();
        //check along the path after everything is done
        rotate(root);
    }

    else if(root->_item == target){

        //target has no left subtree
        if(!root->_left){
            //to help delete
            tree_node<T>* temp = root;
            
            root = root->_right;
            delete temp;
            temp = nullptr;
        }

        //target has left subtree
        else{
            tree_remove_max(root->_left, root->_item);
        }

        if(root) {
            root->update_height();
            rotate(root); //don't need rotate here since children are not affected
        }
        return true;

    }

   
}


template <typename T> //print in_order
void in_order(tree_node<T>* root,ostream& outs=cout){
    
    if(root){
        in_order(root->_left);
        cout << "  " << root->_item;
        in_order(root->_right);
    }
}

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root,ostream& outs=cout){
    if(root){
        cout << "  " << root->_item;
        pre_order(root->_left);
        pre_order(root->_right);
    }
}

template <typename T> //print post_order
void  post_order(tree_node<T>* root,ostream& outs=cout){
    if(root){
        post_order(root->_left);
        post_order(root->_right);
        cout << "  " << root->_item;
    }
}

//----------------THIS IS TO HELP STRINGIFYING------

template <typename T> //print in_order
void in_order(tree_node<T>* root, string& s){
    
    if(root){
        in_order(root->_left, s);
        s.append("[");
        s.append(to_string(root->_item));
        s.append("]");
        in_order(root->_right, s);
    }
}

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root, string& s){
    if(root){
        
        s.append("[");
        s.append(to_string(root->_item));
        s.append("]");
        pre_order(root->_left, s);
        pre_order(root->_right, s);
    }
}

template <typename T> //print post_order
void  post_order(tree_node<T>* root, string& s){
    if(root){
        post_order(root->_left, s);
        post_order(root->_right, s);
        s.append("[");
        s.append(to_string(root->_item));
        s.append("]");
    }
}
//------------------------------------------------------

template <typename T> //string in_order
string in_order_string(tree_node<T>* root){
    
    string s; 
    in_order(root, s);
    return s;
}


template <typename T> //string pre_order
string pre_order_string(tree_node<T>* root){
    
    string s;
    pre_order(root, s);
    return s;
}

template <typename T> //string post_order
string post_order_string(tree_node<T>* root){
    
    string s;
    post_order(root, s);
    return s;
}


template <typename T> //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){
    
    if(root){
        return new tree_node<T>(root->_item, tree_copy(root->_left), tree_copy(root->_right));
    }

    else return NULL;
}

template <typename T> //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    
    if(src){
        //will try to add with in-order fashion
        tree_add(dest, src->_left);
        tree_insert(dest, src->_item);// cout << "Inserting " << src->_item << endl;
        tree_add(dest, src->_right);

    }
}

template <typename T> // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){

    //base case (if nothing to add, don't add)

    //recursive case (if something, keep recursing)
    if(size > 0){

        int mid = size/2;
        tree_node<T>* temp = new tree_node<T>(a[mid], tree_from_sorted_list(a, size/2), tree_from_sorted_list(a+mid+1, (size-1)/2));
        temp->update_height();
        return temp;
        //the right parameter is genius omfg
    }

    else return nullptr;
}

template <typename T> // NOT USING RIGHT NOW
tree_node<T>* tree_from_unsorted_list(const T* a, int size){

    tree_node<T>* temp = nullptr;
    for(int i = 0; i < size; i++){
        tree_insert(temp, a[i]);
        cout << "tree is now " << endl;
        tree_print(temp);
    }

    return temp;
}

template <typename T> //sorted array of ints -> tree
tree_node<T>* tree_from_sorted_list(const T* a){
    
    //idk what this is doing
    return nullptr;
}

#endif