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
}
