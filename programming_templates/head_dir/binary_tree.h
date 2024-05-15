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
    friend ostrream& operator<<(ostream&, const BinaryTree<elemType>&);
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
inline ostream& operator<<(ostream &os, const BinaryTree<elemType> &bt) {
    os << "Tree: " << std::endl;
    bt.print(os);
    return os;
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
    std::cout << elem << std::endl;
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
    if (!root_) {
        return;        
    }
    BTNode<elemType> *tmp = root_;
    if (root_->rchild_) {
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
    delete tmp;
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
