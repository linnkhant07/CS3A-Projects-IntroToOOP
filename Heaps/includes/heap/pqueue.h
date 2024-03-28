#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include "heap.h"
#include <assert.h>

using namespace std;


template <typename T>
struct info{
    T item;
    int priority;
    int timestamp;

    //default ctor
    info():item(T()), priority(0){

    }

    //ctor
    info(T i, int p, int tp):item(i), priority(p), timestamp(tp){

    }

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        const bool tldr = true;
        outs << print_me.priority << ":" << print_me.item << "]" << endl;
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority < rhs.priority;
    }
    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority > rhs.priority;
    }

    friend bool operator <=(const info<T>& lhs, const info<T>& rhs){

        //to work around duplicates
        if(lhs.priority != rhs.priority){   
            return lhs.priority < rhs.priority;
        }
        
        //if priorities are equal
        else{
            assert(lhs.timestamp != rhs.timestamp);
            return lhs.timestamp > rhs.timestamp;
            //larger timestapm means arrived later
        }
    }
    friend bool operator >=(const info<T>& lhs, const info<T>& rhs){
        
        //to work around duplicates
        if(lhs.priority != rhs.priority){   
            return lhs.priority > rhs.priority;
        }
        
        //if priorities are equal
        else{
            assert(lhs.timestamp != rhs.timestamp);
            return rhs.timestamp > lhs.timestamp;
            //larger timestapm means arrived later
        }
    }

};

template <typename T>
class PQueue
{
public:
    PQueue():_timestamp(0){

    }

    bool push(const T& value, int p);
    T pop();
    info<T> Pop_debug();
    bool is_empty() const {return _heap.is_empty();}
    int size() const {return _heap.size();}
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me._heap;
        return outs;
    }
    bool verify() const;
private:
    Heap<info<T>> _heap;
    int _timestamp;

};

template<typename T>
bool PQueue<T>::push(const T& value, int p){

    //how many is there to track timestamp
    _heap.insert(info<T>(value, p, _timestamp));
    _timestamp++;
    return true;
}

template<typename T>
T PQueue<T>::pop(){

    info<T> popped = _heap.remove();
    //cout << "priority is " << popped.priority << endl;
    return popped.item;
}

template<typename T>
info<T>  PQueue<T>::Pop_debug(){

    return _heap.remove();
}

template<typename T>
void PQueue<T>::print_tree() const{
    cout << _heap << endl;
}

template<typename T>
bool PQueue<T>::verify() const{

    return _heap.verify();
}

#endif