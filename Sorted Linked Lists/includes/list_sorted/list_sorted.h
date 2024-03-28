#ifndef LIST_SIMPLE_H
#define LIST_SIMPLE_H
#include <assert.h>
#include "../node/node.h"
#include "../linked_list_functions/linked_list_functions.h"

#include <iostream>

using namespace std;

template <class ITEM_TYPE>
class List
{
public:
    // NESTED ITERATOR CLASS
    class Iterator
    {
    public:
        friend class List; // give access to list to access _ptr
        Iterator() : _ptr(nullptr)
        {
        }
        // default ctor
        Iterator(node<ITEM_TYPE> *p) : _ptr(p)
        {
        } // Point Iterator to where p is pointing to

        operator bool()
        {
            // leave for now
        } // casting operator: true if _ptr not NULL
          //       this turned out to be a pain!

        ITEM_TYPE &operator*()
        {
            return _ptr->_item;
        } // dereference operator

        ITEM_TYPE *operator->()
        {
            return &(_ptr->_item);
        } // member access operator

        bool is_null()
        {
            return _ptr ? false : true;
        } // true if _ptr is NULL

        friend bool operator!=(const Iterator &left, const Iterator &right)
        {
            return left._ptr != right._ptr;

        } // true if left != right

        friend bool operator==(const Iterator &left, const Iterator &right)
        {
            return !(left != right);
        } // true if left == right

        Iterator &operator++()
        {
            _ptr = _ptr->_next;
        } // member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator &it, int unused)
        {
            Iterator hold = it;
            ++it;
            return hold;
        } // friend operator: it++

    private:
        node<ITEM_TYPE> *_ptr; // pointer being encapsulated
    };

    // SIMPLE LIST FUNCTIONS
    List(bool order = true, bool unique = false);

    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List &operator=(const List &RHS);

    Iterator insert(const ITEM_TYPE &i); // Insert i
    Iterator insert_and_add(const ITEM_TYPE &i);

    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator iMarker);
    void Print() const;                    // print the list
    Iterator search(const ITEM_TYPE &key); // return Iterator to node [key]

    Iterator prev(Iterator iMarker); // previous node to marker

    ITEM_TYPE &operator[](int index); // return the item at index
    Iterator begin() const;           // Iterator to the _head_ptr node
    Iterator end() const;             // Iterator to NULL
    Iterator last_node() const;
    bool empty() const { return _head_ptr == nullptr; }

    template <class U>
    friend ostream &operator<<(ostream &outs, // insertion operator for list
                               const List<U> &l);
    int size() const { return _size; }

private:
    node<ITEM_TYPE> *_head_ptr;
    bool _order;
    bool _unique;
    int _size;
};

// DEFINING THE FUNCTIONS OUTSIDE

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(bool order, bool unique) : _size(0), _head_ptr(nullptr), _order(order), _unique(unique)
{
}

// BIG THREE
template <class ITEM_TYPE>
List<ITEM_TYPE>::~List()
{
    _clear_list(_head_ptr);
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis)
{
    _head_ptr = _copy_list(copyThis._head_ptr);
    _size = copyThis._size;
}

template <class ITEM_TYPE>
List<ITEM_TYPE> &List<ITEM_TYPE>::operator=(const List &RHS)
{
    if (this != &RHS)
    {
        // clear the list first
        _clear_list(_head_ptr);
        _head_ptr = _copy_list(RHS._head_ptr);
        _size = RHS._size;
    }

    return *this;
}

template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const
{
    _print_list(_head_ptr);
} // print the list

template <class ITEM_TYPE>
ITEM_TYPE &List<ITEM_TYPE>::operator[](int index)
{
    assert(_size && index < _size && index >= 0);
    return _at(_head_ptr, index);
} // return the item at index

template <class U>
ostream &operator<<(ostream &outs, // insertion operator for list
                    const List<U> &l)
{
    for (node<U> *walker = l._head_ptr; walker != nullptr; walker = walker->_next)
    {
        outs << *walker;
    }

    outs << "|||\n";
    return outs;
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert(const ITEM_TYPE &i)
{
    // if the list is unique
    if (_unique)
        return insert_and_add(i);

    return _insert_sorted(_head_ptr, i, _order);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_and_add(const ITEM_TYPE &i)
{

    return _insert_sorted_and_add(_head_ptr, i, _order);
}

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(List<ITEM_TYPE>::Iterator iMarker)
{
    _size--;
    return _delete_node(_head_ptr, iMarker._ptr);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::search(const ITEM_TYPE &key)
{
    return _search_list(_head_ptr, key);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::prev(Iterator iMarker)
{
    return _previous_node(_head_ptr, iMarker._ptr);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::begin() const
{
    return _head_ptr;
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::end() const
{
    return nullptr;
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::last_node() const
{
    node<ITEM_TYPE> *walker;
    for (walker = _head_ptr; walker->_next != nullptr; walker = walker->_next)
    {
    }

    return walker;
}

#endif
