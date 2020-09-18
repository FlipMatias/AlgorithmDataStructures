#pragma once

#include "util.h"


namespace alg
{
    template <typename T>
    auto reverse(T&& items) -> T&
    {
        size_t len = std::end(items) - std::begin(items);
        if (len  <= 1) return items;

        size_t i = 0;
        size_t j = len - 1;

        auto beg = std::begin(items);
        auto end = std::end(items) - 1;

        for (; i < j; ++i, --j) {
            swap_iterators(beg, end);
            ++beg; --end;
        }

        return items;
    }


    template <typename T>
    auto rotate(T&& items) -> T&
    {
        auto beg = std::begin(items);
        auto end = std::end(items) - 1;
        size_t len = end - beg;
        if (len  <= 1) return items;
        alg::swap_iterators(beg, end);
        return items;
    }
}
