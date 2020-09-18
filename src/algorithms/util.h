#pragma once

#include <iostream>
#include <iterator>


namespace alg
{
    template <typename T>
    auto length(T&& items) -> size_t {
        return std::end(items) - std::begin(items);
    }


    template <typename T>
    auto isEmpty(T&& items) -> bool {
        return !length(items);
    }


    template <class T>
    void print(T&& items)
    {
        std::cout << "[ ";
        for (const auto& i : items)
            std::cout << i << " ";
        std::cout << "]\n";
    }


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
