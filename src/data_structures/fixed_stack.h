#pragma once

#include "../algorithms/util.h"


namespace ads
{
    template <typename Type, size_t Capacity = 100>
    class FixedStack final
    {
    private:
        Type _data[Capacity];
        size_t _length { 0 };

    public:
        FixedStack()
        {
            static_assert(Capacity > 0, "Invalid capacity value");

            if constexpr (std::is_arithmetic<Type>()) {
                std::memset(_data, 0x0, sizeof(Type));
            }
        }

        FixedStack(FixedStack&&) = delete;
        FixedStack(const FixedStack&) = delete;
        auto operator = (const FixedStack&) -> FixedStack& = delete;


        template <typename... Args>
        void push(Args&&... args)
        {
            assert(!isFull());

            _data[_length] = Type(args...);
            _length += 1;
        }


        auto pop() -> Type
        {
            assert(!isEmpty());

            return _data[--(_length)];
        }


        auto peak() -> Type
        {
            assert(!isEmpty());

            return _data[(_length - 1)];
        }


        auto capacity() const ->size_t {
            return Capacity;
        }


        auto length() const -> size_t {
            return _length;
        }


        auto isEmpty() const -> bool {
            return (_length == 0);
        }


        auto isFull() const -> bool {
            return (_length == Capacity);
        }
    };
}
