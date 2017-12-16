//
// Created by vivekkimi on 2/9/2016.
//

#include <stddef.h>
#include "iostream"
#include "TreeClassBST.h"

template <typename T>
TreeNode<T>* TreeClassBST<T>::add(TreeNode<T>* ioRoot, T& iValue) {

    TreeNode<T> *temp = ioRoot;

    if(temp != NULL)
    {
        std::cout << "VIV: Root: value: " << ioRoot->value << std::endl;

        if (ioRoot->value > iValue)
        {
            ioRoot->left = add(ioRoot->left, iValue);
        }
        else
        {
            ioRoot->right = add(ioRoot->right, iValue);
        }
    }
    else
    {
        std::cout << "VIV: add: " << iValue << std::endl;
        temp = new TreeNode<T>();
        temp->value = iValue;
    }

    return temp;
}

template <typename T>
void TreeClassBST<T>::add(T& iValue) {
    _root = add(_root, iValue);
}

template <typename T>
void TreeClassBST<T>::dfs(TreeNode<T> *root, T& iValue) {
 if (root != NULL)
 {
     dfs(root->left, iValue);
     std::cout << "VIV: TreeNode: " << root->value << std::endl;
     dfs(root->right, iValue);
 }
}

template <typename T>
void TreeClassBST<T>::print() {
    T a;
  dfs(_root, a);
}

template <>
void TreeClassBST<int>::print() {
    int a = 10;
    dfs(_root, a);
}

template void TreeClassBST<int>::print();
template void TreeClassBST<int>::add(int&);
template TreeNode<int>* TreeClassBST<int>::add(TreeNode<int>*, int&);
template void TreeClassBST<int>::dfs(TreeNode<int>*, int&);