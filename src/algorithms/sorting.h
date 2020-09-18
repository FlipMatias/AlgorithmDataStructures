#pragma once

#include "util.h"


namespace alg
{
    template <typename T>
    auto isSorted(T&& items) -> bool
    {
        if (alg::isEmpty(items))
            return false;

        auto beg = std::begin(items);
        auto end = std::end(items) - 1;

        for (; beg != end; ++beg) {
            if (*beg > *(beg + 1))
                return false;
        }
        return true;
    }
}
