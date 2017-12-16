//
// Created by vivekkimi on 1/30/2016.
//

#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

void BinarySearchTree::addNode(Node*& iRootPtr, int32_t iValue)
{
    std::cout << "add the node : " << iValue << std::endl;
    if (iRootPtr != NULL)
    {
        std::cout << "Root value : " << iRootPtr->getValue() << std::endl;
        if (iRootPtr->getValue() > iValue)
                addNode(iRootPtr->_left, iValue);
        else
                addNode(iRootPtr->_right, iValue);
    }
    else
        iRootPtr = new Node(iValue);
}

size_t BinarySearchTree::childCount() {
    return childCount(_root);
}

size_t BinarySearchTree::childCount(Node* iRoot) {
    if (iRoot != NULL)
    {
        return childCount(iRoot->_left) + 1 + childCount(iRoot->_right);
    }
    else
        return 0;
}

size_t BinarySearchTree::maxDepth() {
    return maxDepth(_root);
}

Node* BinarySearchTree::balancedBinarySearchTree(std::vector<int32_t>& iList, int32_t iStart, int32_t iEnd) {

    std::cout << "VIV: iStart: " << iStart << " end: " << iEnd << std::endl;


    if (iStart > iEnd)
        return NULL;

    size_t  aValueMid = (iStart + iEnd) / 2;
    Node *node =  new Node(iList[aValueMid]);
    std::cout << "VIV: Node created: " << node->getValue() << std::endl;
    node->_left = balancedBinarySearchTree(iList, 0, aValueMid - 1);
    node->_right = balancedBinarySearchTree(iList, aValueMid + 1, iEnd);

    return node;
}

size_t BinarySearchTree::maxDepth(Node *iRoot) {
size_t aLeftHeight = 0, aRightHeight = 0;

    if (iRoot != NULL)
    {
        aLeftHeight = maxDepth(iRoot->_left);
        aRightHeight = maxDepth(iRoot->_right);
        return (aLeftHeight > aLeftHeight ? aRightHeight : aRightHeight) + 1 ;
    }
    else
        return 0;
}

bool BinarySearchTree::isBalanced() {
return maxDepth(_root->_left) == maxDepth(_root->_right);
}

void BinarySearchTree::breadthFirstSearch() {
    breadthFirstSearch(_root);
}

void BinarySearchTree::breadthFirstSearch(Node *iRoot) {
    std::list<Node*> aQueue;
    Node* aVisited;

    if (iRoot)
    {
        aQueue.push_back(iRoot);

        while (!aQueue.empty())
        {
            aVisited = aQueue.front();

            std::cout << aVisited->getValue() << std::endl;

            aQueue.pop_front();

            if (aVisited->_left)
                aQueue.push_back(aVisited->_left);

            if (aVisited->_right)
                aQueue.push_back(aVisited->_right);
        }
    }
}

void BinarySearchTree::preorderPrint(Node* iRoot)
{
    if (iRoot != NULL)
    {
        preorderPrint(iRoot->_left);
        std::cout << iRoot->getValue() << std::endl;
        preorderPrint(iRoot->_right);
    }
}
