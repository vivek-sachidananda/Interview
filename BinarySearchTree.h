//
// Created by vivekkimi on 1/30/2016.
//

#ifndef C_BINARYSEARCHTREE_H
#define C_BINARYSEARCHTREE_H

#include "boost/shared_ptr.hpp"
#include "Node.h"
#include "list"

class BinarySearchTree {

public:
    BinarySearchTree():_root(NULL)
    {
    }
    void add(std::vector<int32_t>& iList)
    {
        std::cout << "VIV: add vector : " << iList.size() << std::endl;
        _root = balancedBinarySearchTree(iList, 0, iList.size() - 1);
    }
    void add(int32_t iValue)
    {
        if (_root)
            this->addNode(_root, iValue);
        else
            _root = new Node(iValue);
    }
    void print()
    {
        std::cout << "VIV: " << "BST: " << std::endl;

        this->preorderPrint(_root);
    }
    void breadthFirstSearch();
    size_t childCount();
    size_t maxDepth();
    bool isBalanced();
    void clearTree()
    {
        delete(_root);
        _root = NULL;
    }
private:
    Node* balancedBinarySearchTree(std::vector<int32_t>& iList, int32_t iStart, int32_t iEnd);
    void breadthFirstSearch(Node* iRoot);
    size_t childCount(Node* iRoot);
    size_t maxDepth(Node* iRoot);
    void preorderPrint(Node* iRoot);
    void addNode(Node*& iRootPtr, int32_t iValue);
    Node* _root;
    int32_t  _level;
    int32_t  _count;
};

#endif //C_BINARYSEARCHTREE_H
