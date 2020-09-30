#pragma once

#include "../algorithms/util.h"
#include "../data_structures/linked_list.h"


namespace ads
{
    template <typename Ty>
    class Queue final
    {
    public:
        Queue() {}

    public:
        void enqueue(const Ty& item);
        auto dequeue() -> Ty;
        auto front() -> Ty;
        auto size() -> size_t;
        auto isEmpty() -> bool;
        void clear();

    private:
        LinkedList<Ty> _items;
    };


    template <typename Ty>
    void Queue<Ty>::enqueue(const Ty& item)
    {
        _items.append(item);
    }


    template <typename Ty>
    auto Queue<Ty>::dequeue() -> Ty
    {
        assert(!isEmpty());

        auto item = front();
        _items.popFront();
        return item;
    }


    template <typename Ty>
    auto Queue<Ty>::front() -> Ty
    {
        assert(!isEmpty());

        return *_items.begin();
    }


    template <typename Ty>
    auto Queue<Ty>::size() -> size_t
    {
        return _items.size();
    }


    template <typename Ty>
    auto Queue<Ty>::isEmpty() -> bool
    {
        return _items.isEmpty();
    }


    template <typename Ty>
    void Queue<Ty>::clear()
    {
        _items.clear();
    }
}
