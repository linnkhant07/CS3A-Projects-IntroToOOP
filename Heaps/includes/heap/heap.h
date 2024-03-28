#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void swap(T& a, T& b);

template <typename T>
class Heap
{
public:
    Heap():_how_many(0){
        //default ctor
    }

    void insert(const T& insert_me);    //insert into the heap
    T remove();                         //remove and return top value 
    T top();                            //return the value at the top of heap
    bool is_empty() const;
    int size() const;
    int capacity() const;
    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree(outs);
        return outs;
    }
    bool verify() const;                //true if tree is verified to be a heap
    T *heap_array();                    //returns a copy of underlying array: 
                                        //  don't forget to delete when done
    int big_child_index(int i) const;

private:
    static const int CAPACITY = 1000;
    T _heap[CAPACITY]; //static array
    int _how_many; //num used

    void print_tree(ostream& outs = cout) const;
    void print_tree(int root, int level = 0, ostream& outs = cout) const;

    bool verify(int root) const;

    bool is_root(int i) const {return i==0;}
    bool is_leaf(int i) const;
    int parent_index(int i) const {return (i-1)/2;}
    int left_child_index(int i)const {return 2*i + 1;}
    int right_child_index(int i) const {return 2*i + 2;}
    
    void swap_with_parent(int i);
};


template <typename T>
void Heap<T>::insert(const T& insert_me){

    _heap[_how_many] = insert_me;
    int pos = _how_many;

    //short circuit if parent is out of bound
    //while it is not root
    while((pos-1)/2 > -1 && _heap[pos] > _heap[parent_index(pos)]){

        swap_with_parent(pos);
        pos = parent_index(pos);

    }

    _how_many++;
    
}   //insert into the heap

template <typename T>
T Heap<T>::remove(){

    if(!is_empty()){

        T popped = top();
        _heap[0] = _heap[_how_many-1];
        _how_many--;
        int pos = 0;

        while(big_child_index(pos) != -1 && _heap[pos] <= _heap[big_child_index(pos)]){
            int temp = big_child_index(pos);
            swap_with_parent(big_child_index(pos));
            pos = temp;
        }

        return popped;
    }
}                        //remove and return top value 

template <typename T>
T Heap<T>::top(){

   if(_how_many) return _heap[0];
   
}                           //return the value at the top of heap

template <typename T>
bool Heap<T>::is_empty() const{

    return !_how_many;
}

template <typename T>
int Heap<T>::size() const{

    return _how_many;
}

template <typename T>
int Heap<T>::capacity() const{

    return CAPACITY;
}

template <typename T>
bool Heap<T>::verify() const{

    return verify(0);
}                //true if tree is verified to be a heap

template <typename T>
T* Heap<T>::heap_array(){

    T* copy = new T[_how_many]; // Allocate memory for the copy

    for (int i = 0; i < _how_many; i++) {
        copy[i] = _heap[i];
    }

    return copy;
}                    //returns a copy of underlying array: 


template <typename T>
void Heap<T>::print_tree(int root, int level, ostream& outs) const{

    if(root < _how_many){
        print_tree(right_child_index(root), level + 1);
        outs << setw(4*level) << ""  << "[" << _heap[root] << "]" << endl;
        print_tree(left_child_index(root), level+1);
    }
}

template <typename T>
void Heap<T>::print_tree(ostream& outs) const{
    print_tree(0, 0, outs);
}   


template <typename T>
bool Heap<T>::verify(int root) const{
    if(root >= _how_many) return true;

    if((left_child_index(root) < _how_many &&  _heap[root] < _heap[left_child_index(root)]) || (right_child_index(root) < _how_many&& _heap[root] < _heap[right_child_index(root)])){
        return false;
    }

    return verify(left_child_index(root)) && verify(right_child_index(root));
}


template <typename T>
bool Heap<T>::is_leaf(int i) const{

    return false;
}

template <typename T>
int Heap<T>::big_child_index(int i) const{

    int left = left_child_index(i) < _how_many ? left_child_index(i): -1;
    int right = right_child_index(i) < _how_many ? right_child_index(i): -1;

    if(left < 0 && right < 0) return -1;
    if(right < 0 || (left > -1 && _heap[left] >= _heap[right]) ) return left; //left should be the one arriving first
    if(left < 0 || (right > -1 && _heap[right] >= _heap[left]) ) return right;

    return -1;
}

template <typename T>
void Heap<T>::swap_with_parent(int i){

    T temp = _heap[parent_index(i)];
    _heap[parent_index(i)] = _heap[i];
    _heap[i] = temp;

}


#endif