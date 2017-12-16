//
// Created by vivekkimi on 2/6/2016.
//

#include "LinkedList.h"


template <typename T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T> &iLinkedList) {
    LinkedList<T> aLinkedList;

    if (_head == NULL && iLinkedList._head == NULL)
        return aLinkedList;

    int value;
    bool carryValue = false;

    while(_head != NULL && iLinkedList._head != NULL)
    {
        value = _head->_value + iLinkedList._head->_value;
        std::cout << "VIV: value: " << value << std::endl;
        if (carryValue)
        {
            value += 1;
            carryValue = false;
        }
        if (value > 9)
        {
            carryValue = true;
            value = value % 10;
        }
        aLinkedList.addValue(value);

        _head = _head->_next;
        iLinkedList._head = iLinkedList._head->_next;
    }

    if (carryValue)
        aLinkedList.addValue(1);

    return  aLinkedList;
}

template LinkedList<int> LinkedList<int>::operator+(LinkedList<int>& iLinkedList);
