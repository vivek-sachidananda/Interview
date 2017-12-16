//
// Created by vivekkimi on 1/30/2016.
//

#ifndef C_NODE_H
#define C_NODE_H

#include "boost/shared_ptr.hpp"
#include "boost/lexical_cast.hpp"

class Node
{
public:
    Node(int32_t iValue, std::string iName = "Node"):
            _value(iValue), _name(iName + boost::lexical_cast<std::string>(iValue)), _left(NULL), _right(NULL)
    {
    }
    virtual ~Node(){}
    const std::string& getName() const;
    const int32_t  getValue() const;
    Node* _left;
    Node* _right;
private:
    int32_t  _value;
    std::string _name;
};

#endif //C_NODE_H
