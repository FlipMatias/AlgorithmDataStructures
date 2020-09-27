#pragma once

#include "../algorithms/util.h"


namespace ads
{
    template <typename Type>
    struct LinkedListNode
    {
        Type data;
        LinkedListNode<Type>* next;

        template <typename... Args>
        LinkedListNode(Args&&... args) : data(args...)
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
        LinkedListNode<Type>* _firstNode;
        LinkedListNode<Type>* _lastNode;
        size_t _size;

    public:
        LinkedList() : _size(0), _firstNode(nullptr), _lastNode(nullptr)
        {
        }


        LinkedList(const std::initializer_list<Type>& list)
        {
            if (list.size() == 0) {
                return;
            }

            auto i = list.begin();

            _firstNode = new LinkedListNode<Type>(*i);
            _firstNode->next = nullptr;
            _lastNode = _firstNode;
            ++i;

            for (; i != list.end(); ++i) {
                auto node = new LinkedListNode<Type>(*i);
                node->next = nullptr;
                _lastNode->next = node;
                _lastNode = node;
            }

            _size = list.size();
        }


        ~LinkedList()
        {
            auto node = _firstNode;

            while (node != nullptr) {
                auto temp = node;
                node = node->next;
                delete temp;
            }
        }


        void display()
        {
            auto node = _firstNode;

            while (node != nullptr) {
                std::cout << node->data << "\n";
                node = node->next;
            }
        }
    };
}
