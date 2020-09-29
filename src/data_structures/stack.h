#pragma once

#include "../algorithms/util.h"
#include "../data_structures/array.h"
#include <optional>


namespace ads
{
    template <typename Ty>
    class Stack final
    {
    public:
        Stack() {}
        Stack(Stack&& other) { _items = std::move(others); }

    public:
        void push(const Ty& item);
        auto pop() -> std::optional<Ty>;
        auto peak() -> std::optional<Ty>;
        auto length() const -> size_t;
        auto isEmpty() const -> bool;
        void clear();

    private:
        ads::Array<Ty> _items;
        std::size_t _count { 0 };
    };


    template <typename Ty>
    void Stack<Ty>::push(const Ty& item)
    {
        _items.append(item);
        _count += 1;
    }


    template <typename Ty>
    auto Stack<Ty>::pop() -> std::optional<Ty>
    {
        if (isEmpty())
            return std::nullopt;

        auto item = _items[_count-1];
        _items.remove(_items.length()-1);
        _count -= 1;
        return {item};
    }


    template <typename Ty>
    auto Stack<Ty>::peak() -> std::optional<Ty>
    {
        if (isEmpty())
            return std::nullopt;

        return { _items[_count] };
    }


    template <typename Ty>
    auto Stack<Ty>::length() const -> size_t
    {
        return _count;
    }


    template <typename Ty>
    auto Stack<Ty>::isEmpty() const -> bool
    {
        return (_count == 0);
    }


    template <typename Ty>
    void Stack<Ty>::clear()
    {
        this->_count = 0;
        this->_items.clear();
    }
}
