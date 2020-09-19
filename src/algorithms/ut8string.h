#pragma once

#include "util.h"


namespace alg::utf8
{
    size_t length(const void* str);
    size_t length(std::string_view str);
}
