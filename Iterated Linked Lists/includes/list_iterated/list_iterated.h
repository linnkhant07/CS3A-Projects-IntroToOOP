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
    List();

    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List &operator=(const List &RHS);

    node<ITEM_TYPE> *simple_insert_head(ITEM_TYPE i); // inset i at the head of list

    node<ITEM_TYPE> *simple_insert_after(ITEM_TYPE i, // insert i after iMarker
                                         node<ITEM_TYPE> *iMarker);

    node<ITEM_TYPE> *simple_insert_before(ITEM_TYPE i, // insert i before iMarker
                                          node<ITEM_TYPE> *iMarker);

    node<ITEM_TYPE> *simple_insert_sorted(ITEM_TYPE i); // insert i. Assume sorted list

    ITEM_TYPE simple_Delete(node<ITEM_TYPE> *iMarker); // delete node pointed to by iMarker

    void Print() const; // print the list

    node<ITEM_TYPE> *simple_search(const ITEM_TYPE &key); // return pointer to node containing
                                                          //   key. NULL if not there

    node<ITEM_TYPE> *simple_prev(node<ITEM_TYPE> *iMarker); // get the previous node to iMarker

    ITEM_TYPE &operator[](int index); // return the item at index

    node<ITEM_TYPE> *simple_begin() const; // return the head of the list

    node<ITEM_TYPE> *simple_end() const;

    bool empty() const { return head == nullptr; }

    int size() const { return _size; }
    template <class U>
    friend ostream &operator<<(ostream &outs, // insertion operator for list
                               const List<U> &l);

    // ITERATED LIST FUNCTIONS
    Iterator insert_head(ITEM_TYPE i); // insert at the head of list
    Iterator insert_after(ITEM_TYPE i,
                          Iterator iMarker); // insert after marker
    Iterator insert_before(ITEM_TYPE i,
                           Iterator iMarker); // insert before marker
    Iterator insert_sorted(ITEM_TYPE i);      // insert in a sorted list

    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator iMarker);

    Iterator search(const ITEM_TYPE &key); // return Iterator to node [key]
    Iterator prev(Iterator iMarker);       // previous node to marker

    Iterator begin() const; // Iterator to the head node
    Iterator end() const;   // Iterator to NULL
    Iterator last_node() const;

private:
    node<ITEM_TYPE> *head;
    int _size;
};

// DEFINING THE FUNCTIONS OUTSIDE

template <class ITEM_TYPE>
List<ITEM_TYPE>::List() : _size(0), head(nullptr)
{
}

// BIG THREE
template <class ITEM_TYPE>
List<ITEM_TYPE>::~List()
{
    _clear_list(head);
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis)
{
    head = _copy_list(copyThis.head);
    _size = copyThis._size;
}

template <class ITEM_TYPE>
List<ITEM_TYPE> &List<ITEM_TYPE>::operator=(const List &RHS)
{
    // clear the list first
    _clear_list(head);
    head = _copy_list(RHS.head);
    _size = RHS._size;

    return *this;
}

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_insert_head(ITEM_TYPE i)
{
    _size++;
    return _insert_head(head, i);
} // inset i at the head of list

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_insert_after(ITEM_TYPE i, // insert i after iMarker
                                                      node<ITEM_TYPE> *iMarker)
{
    _size++;
    return _insert_after(head, iMarker, i);
}

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_insert_before(ITEM_TYPE i, // insert i before iMarker
                                                       node<ITEM_TYPE> *iMarker)
{
    _size++;
    return _insert_before(head, iMarker, i);
}

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_insert_sorted(ITEM_TYPE i)
{
    _size++;
    return _insert_sorted(head, i);
} // insert i. Assume sorted list

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::simple_Delete(node<ITEM_TYPE> *iMarker)
{
    _size--;
    return _delete_node(head, iMarker);
} // delete node pointed to by iMarker

template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const
{
    _print_list(head);
} // print the list

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_search(const ITEM_TYPE &key)
{
    return _search_list(head, key);
} // return pointer to node containing
  //   key. NULL if not there
template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_prev(node<ITEM_TYPE> *iMarker)
{
    return _previous_node(head, iMarker);
} // get the previous node to iMarker

template <class ITEM_TYPE>
ITEM_TYPE &List<ITEM_TYPE>::operator[](int index)
{
    assert(_size && index < _size && index >= 0);
    return _at(head, index);
} // return the item at index

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_begin() const
{
    return head;
} // return the head of the list

template <class ITEM_TYPE>
node<ITEM_TYPE> *List<ITEM_TYPE>::simple_end() const
{
    return nullptr;
}

template <class U>
ostream &operator<<(ostream &outs, // insertion operator for list
                    const List<U> &l)
{
    for (node<U> *walker = l.head; walker != nullptr; walker = walker->_next)
    {
        outs << *walker;
    }

    outs << "|||\n";
    return outs;
}

// defining list_iterated functions outside
template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_head(ITEM_TYPE i)
{
    return simple_insert_head(i);
    // automatically turned into Iterator as a constructor
} // insert at the head of list

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_after(ITEM_TYPE i, List<ITEM_TYPE>::Iterator iMarker)
{
    return simple_insert_after(i, iMarker._ptr);
} // insert after marker

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_before(ITEM_TYPE i, List<ITEM_TYPE>::Iterator iMarker)
{
    return simple_insert_before(i, iMarker._ptr);
} // insert before marker

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_sorted(ITEM_TYPE i)
{
    // leave for now
} // insert in a sorted list

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(List<ITEM_TYPE>::Iterator iMarker)
{
    return simple_Delete(iMarker._ptr);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::search(const ITEM_TYPE &key)
{
    return simple_search(key);
} // return Iterator to node [key]

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::prev(Iterator iMarker)
{
    return simple_prev(iMarker._ptr);
} // previous node to marker

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::begin() const
{
    return simple_begin();
} // Iterator to the head node

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::end() const
{
    return simple_end();
} // Iterator to NULL

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::last_node() const
{
    node<ITEM_TYPE> *walker;
    for (walker = head; walker->_next != nullptr; walker = walker->_next)
    {
    }

    return walker;
}

#endif
