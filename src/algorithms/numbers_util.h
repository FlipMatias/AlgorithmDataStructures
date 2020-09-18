#pragma once

#include "util.h"


namespace alg
{
    template <typename T>
    auto arrangeArray(T&& items) -> T&
    {
        size_t beg = 0;
        size_t end = (std::end(items) - std::begin(items)) - 1;

        while (beg < end)
        {
            while (items[beg] < 0) ++beg;
            while (items[end] >= 0) --end;
            if (beg < end) alg::swap(items[beg], items[end]);
        }

        return items;
    }
}
