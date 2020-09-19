#include <assert.h>
#include "ut8string.h"


namespace alg::utf8
{
    auto length(const void* str) -> size_t
    {
        assert(str != nullptr);

        uint8_t* p = (uint8_t*)str;
        size_t size = 0;

        while (*p != 0x0)
        {
            if ((*p >> 7) == 0x0)
            {
                size += 1;
                p += 1;
            }
            else if ((*p >> 5) == 0x6)
            {
                size += 1;
                p += 2;
            }
            else if ((*p >> 4) == 0xE)
            {
                size += 1;
                p += 3;
            }
            else if ((*p >> 3) == 0x1E)
            {
                size += 1;
                p += 4;
            }
            else p += 1;
        }

        return size;
    }


    auto length(std::string_view str) -> size_t
    {
        return alg::utf8::length(str.data());
    }
}
