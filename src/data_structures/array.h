#pragma once

#include <algorithm>
#include <type_traits>
#include <initializer_list>
#include <cassert>

#include "../algorithms/search.h"


namespace ads
{
    template <typename Type>
    class Array
    {
    private:
        static constexpr size_t Default_Cap { 128 };
        Type* _data;
        size_t _length;
        size_t _capacity;

    public:
        Array()
        {
            this->init();
        }


        Array(const std::initializer_list<Type>& list)
        {
            this->init();

            for (const auto& item : list)
                this->append(item);
        }


        Array(Array&& arr)
        {
            delete[] this->_data;
            this->_data = arr._data;
            this->_length = arr.length();
            this->_capacity = arr.capacity();
            arr.init();
        }


        Array(const Array& arr)
        {
            this->init();
            *this = arr;
        }


        auto operator = (const Array& arr) -> Array&
        {
            auto* carr = const_cast<Array<Type>*>(&arr);
            for (const auto& item : *carr) {
                this->append(item);
            }
            return *this;
        }


        template <class... Args>
        Array(const size_t num, Args&&... args)
        {
            assert(num != 0);

            this->init();
            this->_length = num;

            for (Type& item : *this)
                item = Type(args...);
        }


        ~Array()
        {
            if (_data != nullptr) {
                delete[] _data;
                _data = nullptr;
            }
        }


    public:
        template <typename... Args>
        void append(Args&&... args)
        {
            if (_length == _capacity)
                resize(_capacity + 1);

            _data[_length] = Type(args...);
            _length += 1;
        }


        template <typename... Args>
        void insert(size_t index, Args&&... args)
        {
            assert(index <= _length);

            if (_length == _capacity)
                resize(_capacity + 1);

            size_t len = _length;
            for (; len > index; --len) {
                _data[len] = _data[len-1];
            }

            _data[index] = Type(args...);
            _length += 1;
        }


        void remove(size_t index)
        {
            assert(index >= 0 && index < _length);

            if (this->isEmpty()) {
                //do some debugging...
                return;
            }

            for (size_t i = index; i < _length; ++i)
                _data[i] = _data[i + 1];

            _length -= 1;
        }


        void clear()
        {
            _length = 0;
            _capacity = Default_Cap;
            delete[] _data;
            _data = new Type[_capacity];
        }


        auto operator += (const Array& arr) -> Array&
        {
            auto* tarr = const_cast<Array<Type>*>(&arr);
            for (const auto& item : *tarr)
                this->append(item);
            return *this;
        }


        auto operator [](size_t index) -> Type& {
            return _data[index];
        }


        auto at(size_t index) -> const Type& {
            return _data[index];
        }


        auto length() -> const size_t {
            return _length;
        }


        auto capacity() -> const size_t {
            return _capacity;
        }


        auto isEmpty() -> const bool {
            return (_length == 0);
        }


        template <typename... Args>
        auto contains(Args&&... args) -> bool {
            auto i = alg::linearSearch(*this, args...);
            return (i != this->end());
        }


        auto begin() -> Type* {
            return _data;
        }


        auto end() -> Type* {
            return (_data + _length);
        }


        auto cbegin() const -> const Type* {
            return _data;
        }


        auto cend() const -> const Type* {
            return (_data + _length);
        }


    private:
        void init()
        {
            _capacity = Default_Cap;
            _length = 0;
            _data = new Type[_capacity];
        }


        void resize(size_t size)
        {
            size_t count = 0;
            _capacity = nextDivisible(size);
            auto tempMem = new Type[_capacity];
            for (Type& i : *this)
                tempMem[count++] = std::move(i);
            delete[] _data;
            _data = tempMem;
        }


        auto nextDivisible(size_t val) -> size_t
        {
            while (true) {
                if (val % Default_Cap == 0)
                    return val;
                val += 1;
            }
        }
    };
}
