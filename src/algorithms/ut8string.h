#pragma once

#include <vector>
#include <string>

#include "util.h"


namespace alg::utf8
{
    size_t length(const void* str);
    size_t length(std::string_view str);

    bool isDigit(uint32_t ch);

    size_t size(const char* str);
    bool compare(const char* str1, const char* str2);

    auto kmp(std::string_view text, std::string_view pattern) -> std::vector<size_t>;
}
