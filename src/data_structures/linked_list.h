#pragma once

#include "../algorithms/util.h"


namespace ads
{
    template <typename Type>
    class LinkedList;

    template <typename Type>
    struct LinkedListNode;
}


namespace ads
{
    template <typename Type>
    class LinkedListIterator
    {
    private:
        LinkedListNode<Type>* _node { nullptr };

    public:
        LinkedListIterator(LinkedListNode<Type>* node) : _node{node}
        {
        }


        auto operator * () -> Type& {
            return _node->data;
        }


        auto operator -> () -> LinkedListNode<Type>* {
            return _node;
        }


        bool operator != (const LinkedListIterator& other) const {
            return _node != other._node;
        }


        bool operator == (const LinkedListIterator& other) const {
            return _node == other._node;
        }


        auto operator ++ () -> LinkedListIterator {
             this->_node = _node->next;
             return *this;
        }
    };
}


namespace ads
{
    template <typename Type>
    struct LinkedListNode
    {
        Type data;
        LinkedListNode<Type>* next { nullptr };
        LinkedListNode<Type>* prev { nullptr };

        LinkedListNode(const Type& data) : data{data}
        {
        }

        LinkedListNode(const Type& data,
                       LinkedListNode<Type>* next = nullptr,
                       LinkedListNode<Type>* prev = nullptr)
            : data{data}, next{next}, prev{prev}
        {
        }
    };
}


namespace ads
{
    template <typename Type>
    class LinkedList
    {
    private:
        LinkedListNode<Type>* _tail;
        LinkedListNode<Type>* _head;
        size_t _size;

    public:
        LinkedList() : _size(0), _tail(nullptr), _head(nullptr)
        {
        }


        LinkedList(const std::initializer_list<Type>& list)
        {

        }


        ~LinkedList()
        {
            auto node = _tail;

            while (node != nullptr) {
                auto temp = node;
                node = node->next;
                delete temp;
            }
        }


        template <typename... Args>
        void append(Args&&... args)
        {
            if (_head != nullptr){
                _head = new LinkedListNode<Type>(args..., nullptr, _head);
                _head->prev->next = _head;
            } else {
                _head = _tail = new LinkedListNode<Type>(args..., nullptr, nullptr);
            }

            _size += 1;
        }


        template <typename... Args>
        void prepend(Args&&... args)
        {
            if (_tail != nullptr){
                _tail = new LinkedListNode<Type>(args..., nullptr, _tail);
                _tail->prev->next = _tail;
            } else {
                _head = _tail = new LinkedListNode<Type>(args...);
            }

            _size += 1;
        }


        auto popFront() -> Type
        {
            auto data = _tail->data;

            if (_tail == _head)
            {
                delete _head;
                _tail = _head = nullptr;
            }
            else
            {
                _tail = _tail->prev;
                delete _tail->next;
                _tail->next = nullptr;
            }

            _size -= 1;
            return data;
        }


        auto popBack() -> Type
        {
            auto data = _head->data;

            if (_tail == _head)
            {
                delete _head;
                _tail = _head = nullptr;
            }
            else
            {
                _head = _head->prev;
                delete _head->next;
                _head->next = nullptr;
            }

            _size -= 1;
            return data;
        }


        void display(bool reverse = false)
        {
            auto node = _tail;

            if (!reverse) {
                while (node != nullptr) {
                    std::cout << node->data << "\n";
                    node = node->next;
                }

                return;
            }

            displayReverse(node);
        }


        auto size() const -> size_t {
            return _size;
        }


        bool isEmpty() const {
            return (_size == 0);
        }

        template <typename Func>
        void traverse(Func func) {
            for (const auto& item : *this) {
                func(item);
            }
        }


        auto begin() {
            return LinkedListIterator<Type>(_tail);
        }


        auto end() {
            return LinkedListIterator<Type>(_head->next);
        }


    private:
        void displayReverse(LinkedListNode<Type>* node)
        {
            if (node != nullptr) {
                displayReverse(node->next);
                std::cout << node->data << "\n";
            }
        }
    };
}
