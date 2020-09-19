#pragma once

#include "util.h"


namespace alg::utf8
{
    size_t length(const void* str);
    size_t length(std::string_view str);

    bool isDigit(uint32_t ch);

    size_t size(const char* str);
    bool compare(const char* str1, const char* str2);
}
