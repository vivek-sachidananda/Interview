//
// Created by vivekkimi on 2/6/2016.
//

#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H

#include <stddef.h>
#include "iostream"

template <typename T>
class LLNode
{
public:
    T    _value;
    LLNode<T>* _next;
};

template <typename T>
class LinkedList {
    typedef LLNode<T> NodeInt;
public:
    LinkedList():_head(NULL){}

    LinkedList<T> operator+(LinkedList<T>& iLinkedList);

    void addValue(T iValue)
    {
        NodeInt *aNewNode;

        aNewNode = new NodeInt();
        aNewNode->_value = iValue;

        if (_head == NULL)
            aNewNode ->_next = NULL;
        else
            aNewNode->_next = _head;

        _head = aNewNode;
    }

    void print()
    {
        std::cout << "Contents for List: " << std::endl;
        NodeInt *temp = _head;

        while(temp != NULL)
        {
            std::cout << temp->_value << " ";
            temp = temp->_next;
        }
        std::cout << std::endl << "------------" << std::endl;
    }
private:
    NodeInt *_head;
};

#endif //C_LINKEDLIST_H
