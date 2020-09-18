#pragma once

#include <iterator>

namespace alg
{
    template <int Ret = 0, typename Type>
    auto swap(Type& a, Type& b)
    {
        Type temp = a;
        a = b;
        b = temp;

        if constexpr (Ret == 0)
            return;
        else if constexpr (Ret == 1)
            return a;
        else
            return b;
    }


    template <typename T>
    void swap_iterators(T beg, T end)
    {
        auto temp = *beg;
        *beg = *end;
        *end = temp;
    }


    template <typename T>
    auto min(T&& a,T&& b) -> T {
        return (a <= b) ? a : b;
    }


    template <typename T>
    auto min(T&& items)
    {
        auto smallest = std::begin(items);

        auto i = std::begin(items);
        for (; i != std::end(items); ++i) {
            if (*i < *smallest)
                smallest = i;
        }

        return smallest;
    }


    template <typename T>
    auto max(T&& a,T&& b) -> T {
        return (a >= b) ? a : b;
    }


    template <typename T>
    auto max(T&& items)
    {
        auto biggest = std::begin(items);

        auto i = std::begin(items);
        for (; i != std::end(items); ++i) {
            if (*i > *biggest)
                biggest = i;
        }

        return biggest;
    }
}
