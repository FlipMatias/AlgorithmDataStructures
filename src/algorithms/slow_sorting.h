#pragma once

#include "../algorithms/util.h"


namespace alg
{
    template <typename It>
    auto bubbleSort(It begin, It end) -> It
    {
        for (It i = begin; i != (end - 1); ++i)
        {
            for (It j = begin; j != (end - 1); ++j)
            {
                if (*j > *(j+1)) {
                    auto next = j + 1;
                    alg::swap_iterators(j, next);
                }
            }
        }

        return begin;
    }


    template <typename T>
    auto bubbleSort(T& items) -> T&
    {
        bubbleSort(std::begin(items), std::end(items));
        return items;
    }


    template <typename T>
    auto selectionSort(T begin, T end) -> T
    {
        for (auto i = begin; i != (end); ++i)
        {
            auto minVal = i;

            for (auto j = (i + 1); j != (end); ++j) //gets iterator with lowest value
            {
                if (*j < *minVal) {
                    minVal = j;
                }
            }

            auto tmp = *minVal; //swap value
            *minVal = *i;
            *i = tmp;
        }

        return begin;
    }


    template <typename T>
    auto selectionSort(T& items) -> T&
    {
        selectionSort(std::begin(items), std::end(items));
        return items;
    }
}
