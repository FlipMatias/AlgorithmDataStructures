#pragma once

#include <algorithm>
#include <type_traits>

#include "../algorithms/search.h"
#include "../algorithms/util.h"


namespace ads
{
    template <class Type, size_t Size>
    class FixedArray
    {
    private:
        Type _data[Size];
        size_t _length;


    public:
        FixedArray() : _length{0}
        {
            if constexpr (std::is_integral<Type>())
                std::fill(_data, _data + Size, 0);
        }


        template <class... Args>
        FixedArray(Args&&... args)
        {
            _length = Size;
            std::for_each(_data, _data + Size, [&](Type& item) {
               item = Type(args...);
            });
        }


        FixedArray(const FixedArray& arr)
        {
            *this = arr;
        }


        auto operator = (const FixedArray& arr) -> FixedArray&
        {
            _length = arr.length();

            if constexpr (std::is_pod<Type>()) {
                std::memcpy(_data, arr._data, Size * sizeof(Type));
                return *this;
            }

            size_t count = 0;
            for (size_t i=0; i<arr.length(); ++i)
                _data[count++] = arr._data[i];

            return *this;
        }


        auto length() const -> size_t {
            return _length;
        }


        auto isEmpty() const -> bool {
            return (_length == 0);
        }


        auto isFull() const -> bool {
            return (_length == Size);
        }


        auto capacity() const -> size_t {
            return Size;
        }


        template <typename... Args>
        auto contains(Args&&... args) -> bool {
            auto i = alg::linearSearch(*this, args...);
            return (i != this->end());
        }


        auto min() -> Type {
            return *alg::min(*this);
        }


        auto max() -> Type {
            return *alg::max(*this);
        }


        auto begin() -> Type* {
            return _data;
        }


        auto end() -> Type* {
            return (_data + Size);
        }


        auto cbegin() -> const Type* {
            return _data;
        }


        auto cend() -> const Type* {
            return (_data + Size);
        }


        auto operator[](size_t index) -> Type& {
            return _data[index];
        }


        auto at(size_t index) -> const Type& {
            return _data[index];
        }
    };
}
