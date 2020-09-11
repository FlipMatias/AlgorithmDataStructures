#pragma once

#include <iterator>
#include "util.h"


namespace alg
{
    template <typename T, typename U>
    auto linearSearch(T&& items, U&& item)
    {
        auto a = std::begin(items);
        auto b = std::end(items);

        for (;a != b; ++a) {
            if (*a == item)
                return a;
        }

        return b;
    }


    template <typename T, typename U>
    auto linearSearch(T start, T end, U&& item)
    {
        for (;start != end; ++start) {
            if (*start == item)
                return start;
        }

        return end;
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
