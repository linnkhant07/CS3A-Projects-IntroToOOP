#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    ITEM_TYPE _item;
    node *_next;
    node *_prev;

    node(const ITEM_TYPE &item = ITEM_TYPE(), node *next = nullptr, node *prev = nullptr);

    template <typename T>
    friend std::ostream &operator<<(std::ostream &outs,
                                    const node<T> &printMe);
};

template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(const ITEM_TYPE &item, node *next, node *prev) : _item(item), _next(next), _prev(prev)
{
}

template <typename T>
std::ostream &operator<<(std::ostream &outs, const node<T> &printMe)
{
    outs << "[" << printMe._item << "]->";
    return outs;
}

#endif