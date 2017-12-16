//
// Created by vivekkimi on 2/9/2016.
//

#ifndef C_TREECLASSBST_H
#define C_TREECLASSBST_H

template <typename T>
struct TreeNode
{
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode()
    {
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class TreeClassBST {
public:
    TreeClassBST():_root(NULL)
    {
    }
    void add(T& iValue);
    void dfs(TreeNode<T> *root, T& iValue);
    void print();
private:
    TreeNode<T>* add(TreeNode<T>* ioRoot, T& iValue);
    TreeNode<T> *_root;
};


#endif //C_TREECLASSBST_H
