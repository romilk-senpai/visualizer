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
        if (this->lChild != nullptr)
        {
            delete lChild;
        }

        if (this->rChild != nullptr)
        {
            delete rChild;
        }
    }

    void getTree(std::vector<T> *v)
    {
        if (this->lChild != nullptr && this->rChild)
        {
            v->push_back(this->leaf);
        }
        else
        {
            lChild->getTree(v);
            rChild->getTree(v);
        }
    }
};