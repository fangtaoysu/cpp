#ifndef BINARY_TREE_H
#define BINARY_TREE_H
 

#include <string>
#include "binary_tree_node.h"
#include <iostream>

template <typename elemType>
class BinaryTree {
private:
    BTNode<elemType> *root_;
    // 将src所指子树复制到tar所指子树
    void copy(BTNode<elemType>*&, BTNode<elemType>*&);
    void RemoveRoot();
    void clear(BTNode<elemType>*);

public:
    template <typename valType>
    friend class BTNode;
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BTNode<elemType>& operator=(const BinaryTree&);
    void Insert(const elemType&);
    void Remove(const elemType&);
    void PreOrder(std::ostream &os=std::cout) const {
        root_->PreOrder(root_, os);
    };
    void InOrder(std::ostream &os=std::cout) const {
        root_->InOrder(root_, os);
    };
    void PostOrder(std::ostream &os=std::cout) const {
        root_->PostOrder(root_, os);
    };

    bool empty() {
        return root_ == 0;
    }
    void clear() {
        if (root_) {
            // clear(root_);
            root_ = 0;
        }
    };
};

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree()
    : root_(0) {
}

template <typename elemType>
inline  BinaryTree<elemType>::BinaryTree(const BinaryTree& rhs)
    : root_(nullptr) {
    std::cout << "BinaryTree(const BinaryTree& rhs)" << std::endl;
    copy(root_, rhs.root_);
}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() {
    clear();
}

template <typename elemType>
inline BTNode<elemType>& BinaryTree<elemType>::operator=(const BinaryTree& rhs) {
    if (this != &rhs) {
        clear();
        root_ = nullptr;
        copy(root_, rhs.root_);
    }
    return *this;
}

template <typename elemType>
void BinaryTree<elemType>::copy(BTNode<elemType>*& tar, BTNode<elemType>*& src) {
    if (!src) {
        tar =  nullptr;
    } else {
        tar = new BTNode<elemType>(src->val_);
        copy(tar->lchild_, src->lchild_);
        copy(tar->rchild_, src->rchild_);
    }
}

template <typename elemType>
inline void BinaryTree<elemType>::Insert(const elemType &elem) {
    // std::cout << elem << std::endl;
    if (!root_) {
        root_ = new BTNode<elemType>(elem);
    } else {
        root_->InsertValue(elem);
    }
}

template <typename elemType>
inline void BinaryTree<elemType>::Remove(const elemType &elem) {
    if (root_) {
        if (root_-> val_ == elem) {
            RemoveRoot();
        } else {
            root_->RemoveValue(elem, root_);
        }
    }
}

template <typename elemType>
void BinaryTree<elemType>::RemoveRoot() {
    /**
     * 移除根节点的策略：
     *  1. 如果根的右孩子：
     *      1.1 为空：根设为左孩子
     *      1.2 不为空：根设为右孩子r
     *          1.2.1 如果根的左孩子l
     *              - 为空：不操作
     *              - 不为空，如果右孩子r的左孩子
     *                  为空：此位置留给左孩子l
     *                  不为空：找到右孩子最左的叶子节点，留个左孩子l
    */
    if (!root_) {
        return;        
    }
    BTNode<elemType> *tmp = root_;
    if (root_->rchild_) {
        root_ = root_->rchild_;
        if (tmp->lchild_) {
            BTNode<elemType> *lc = tmp->lchild_;
            BTNode<elemType> *newlc = root_->lchild_;
            if (!newlc) {
                root_->lchild_ = lc;
            } else {
                BTNode<elemType>::LChildLeaf(lc, newlc);
            }
        }
    } else {
        root_ = root_->lchild_;
    }
    // delete tmp;
}

template <typename elemType>
void BinaryTree<elemType>::clear(BTNode<elemType> *pt) {
    if (pt) {
        clear(pt->lchild_);
        clear(pt->rchild_);
        delete pt;
    }
}


#endif
