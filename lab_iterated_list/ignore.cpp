#ifndef list_iterated_h
#define list_iterated_h
using namespace std;
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

template <class T>
class List
{
public:
    class Iterator
    {
    public:
        friend class List;
        Iterator() { _ptr = nullptr; }
        Iterator(node<T> *p) { _ptr = p; }
        operator bool() { return _ptr != nullptr; }
        T &operator*() { return _ptr->_item; }
        T *operator->() { return &_ptr->_item; }
        bool is_null() { return _ptr == nullptr; }

        friend bool operator!=(const Iterator &left, const Iterator &right)
        {
            return left._ptr != right._ptr;
        }

        friend bool operator==(const Iterator &left, const Iterator &right)
        {
            return left._ptr == right._ptr;
        }

        Iterator &operator++()
        {
            if (_ptr)
            {
                _ptr = _ptr->_next;
            }
            return *this;
        }

        friend Iterator operator++(Iterator &it, int unused)
        {
            Iterator temp = it;
            ++it;
            return temp;
        }

    private:
        node<T> *_ptr;
    };

    List()
    {
        _head_ptr = nullptr;
        _size = 0;
    }

    ~List()
    {
        _clear_list(_head_ptr);
    }

    List(const List<T> &copyThis)
    {
        _head_ptr = _copy_list(copyThis._head_ptr);
        _size = copyThis._size;
    }

    List &operator=(const List &RHS)
    {
        _head_ptr = _copy_list(RHS._head_ptr);
        _size = RHS._size;
        return *this;
    }

    Iterator insert_head(T i)
    {
        _insert_head(_head_ptr, i);
        _size++;
        return Iterator(_head_ptr);
    }

    Iterator insert_after(T i, Iterator iMarker)
    {
        _insert_after(_head_ptr, iMarker._ptr, i);
        _size++;
        return Iterator(_head_ptr);
    }

    Iterator insert_before(T i, Iterator iMarker)
    {
        _insert_before(_head_ptr, iMarker._ptr, i);
        _size++;
        return Iterator(_head_ptr);
    }

    Iterator insert_sorted(T i)
    {
    }

    T Delete(Iterator iMarker)
    {
        int deleted = _delete_node(_head_ptr, iMarker._ptr);
        _size--;
        return deleted;
    }

    void Print() const
    {
        _print_list(_head_ptr);
    }

    Iterator search(const T &key)
    {
        return Iterator(_search_list(_head_ptr, key));
    }

    Iterator prev(Iterator iMarker)
    {
        return Iterator(_previous_node(_head_ptr, iMarker._ptr));
    }

    T &operator[](int index)
    {
        return _at(_head_ptr, index);
    }

    Iterator begin() const
    {
        return Iterator(_head_ptr);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

    bool empty() const
    {
        return _head_ptr == nullptr;
    }

    int size() const
    {
        return _size;
    }

    friend ostream &operator<<(ostream &outs, const List<T> &l)
    {
        for (node<T> *walker2 = l._head_ptr; walker2; walker2 = walker2->_next)
        {
            outs << *walker2 << "->";
        }
        outs << "|||";
        outs << endl;
        return outs;
    }

private:
    node<T> *_head_ptr;
    int _size;
};

#endif
