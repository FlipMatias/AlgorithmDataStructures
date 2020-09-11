#pragma once

#include <iterator>


namespace alg
{
    template <typename T, typename U>
    auto binarySearch(T begin, T end, U&& item)
    {
        size_t len = end - begin;
        size_t low = 0;
        size_t high = len - 1;
        size_t mid;
        auto at = [&](size_t i) { return (begin + i); };

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (item == *at(mid))
                return at(mid);
            else if (item < *at(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return end;
    }


    template <typename T, typename U>
    auto binarySearch(T&& items, U&& item)
    {
        return binarySearch(std::begin(items), std::end(items), item);
    }
}
