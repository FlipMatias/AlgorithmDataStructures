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
}
