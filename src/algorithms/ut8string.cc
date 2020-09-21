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


    auto isDigit(uint32_t ch) -> bool
    {
        uint8_t byte = ch & 0xff;
        return (byte >= 0x30 && byte <= 0x39);
    }


    auto size(const char* str) -> size_t
    {
        assert(str != nullptr);

        size_t size = 0;
        uint8_t* c = (uint8_t*)str;
        for (; *c != 0x0; ++c) {
            ++size; }

        return size;
    }


    auto compare(const char* str1, const char* str2) -> bool
    {
        assert(str1 != nullptr);
        assert(str2 != nullptr);

        size_t s1 = size(str1);
        size_t s2 = size(str2);

        if (s1 != s2) return false;
        if (memcmp(str1, str2, s1+1) != 0) return false;

        return true;
    }


    auto kmp(std::string_view text, std::string_view pattern) -> std::vector<size_t>
    {
        std::vector<size_t> next { 0 };
        std::size_t j = 0;

        for (size_t i = 1; i < pattern.length(); ++i)
        {
            while (j > 0 && pattern[j] != pattern[i]) { j = next[j - 1]; }

            if (pattern[j] == pattern[i]) { j += 1; }

            next.push_back(j);
        }

        std::vector<size_t> ans;
        j = 0;

        for (size_t i = 0; i < text.length(); ++i)
        {
            while (j > 0 && text[i] != pattern[j]) { j = next[j - 1]; }

            if (text[i] == pattern[j]) { j += 1; }

            if (j == pattern.length()) {
                ans.push_back(i - (j - 1));
                j = next[j - 1];
            }
        }

        return ans;
    }
}
