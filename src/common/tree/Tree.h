#pragma once

#include <vector>

template <typename T>

class TreeNode
{
public:
    T leaf;
    TreeNode<T> *lChild;
    TreeNode<T> *rChild;

    TreeNode(T leaf)
        : leaf(leaf), lChild(nullptr), rChild(nullptr) {}

    ~TreeNode()
    {
        if (lChild != nullptr)
        {
            delete lChild;
        }

        if (rChild != nullptr)
        {
            delete rChild;
        }
    }

    void getTree(std::vector<T> *v) 
    {
        if (lChild != nullptr)
        {
            v->push_back(lChild->leaf);
            lChild->getTree(v);
        }

        if (rChild != nullptr)
        {
            v->push_back(rChild->leaf);
            rChild->getTree(v);
        }
    }
};