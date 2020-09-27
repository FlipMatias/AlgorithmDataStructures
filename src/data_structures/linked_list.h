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


        void display(bool reverse = false)
        {
            auto node = _firstNode;

            if (!reverse) {
                while (node != nullptr) {
                    std::cout << node->data << "\n";
                    node = node->next;
                }

                return;
            }

            displayReverse(node);
        }


        auto begin() {
            return LinkedListIterator<Type>(_firstNode);
        }


        auto end() {
            return LinkedListIterator<Type>(_lastNode->next);
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
