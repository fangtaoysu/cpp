#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H


#include <iostream>
#include <string>

template <typename Type>
class BinaryTree; // 声明类

template <typename valType>
class BTNode {
private:
    int cnt_;
    void DisplayVal(BTNode *pt, std::ostream &os) const {
        if (pt) {
            os << *pt << " ";
        }
    }

public:
    valType val_;
    BTNode *lchild_;
    BTNode *rchild_;
    static void LChildLeaf(BTNode *leaf, BTNode *sub_tree);
    void InsertValue(const valType&);
    void RemoveValue(const valType&, BTNode *&);
    BTNode(const valType&);
    ~BTNode();
    // template <typename elemType>
    // friend class BinaryTree<valType>;
    void PreOrder(BTNode *pt, std::ostream &os) const;
    void InOrder(BTNode *pt, std::ostream &os) const;
    void PostOrder(BTNode *pt, std::ostream &os) const;
};

template <typename valType>
std::ostream& operator<<(std::ostream& os, const BTNode<valType>& node) {
    os << node.val_;
    return os;
}

// 此处将树中的节点对象一律按引用方式处理
template <typename valType>
inline BTNode<valType>::BTNode(const valType &val) 
    : val_(val) {
    cnt_ = 1;
    lchild_ = 0;
    rchild_ = 0;
}

template <typename valType>
void BTNode<valType>::InsertValue(const valType &val) { 
    if (val == val_) {
        cnt_++;
        return;
    }
    if (val < val_) {
        if (!lchild_) {
            lchild_ = new BTNode<valType>(val);
        } else {
            lchild_->InsertValue(val);
        }
    } else {
        if (!rchild_) {
            rchild_ = new BTNode<valType>(val);
        } else {
            rchild_->InsertValue(val);
        }
    }
}

// 定义的时候不用static关键字
template <typename valType>
void BTNode<valType>::LChildLeaf(BTNode *leaf, BTNode *sub_tree) {
    /**
     * 找到子树的最左叶子节点，将leaf设为子树的叶子节点
    */
    while (sub_tree->lchild_) {
        sub_tree = sub_tree->lchild_;
    }
    sub_tree->lchild_ = leaf;
}

template <typename valType>
void BTNode<valType>::RemoveValue(const valType &val, BTNode*& prev) {
    // 与MoveRoot()使用的是相同的策略
    if (val < val_) {
        if (!lchild_) {
            return;
        }
        else {
            lchild_->RemoveValue(val, lchild_);
        }
    } else if (val > val_) {
        if (!rchild_) {
            return;
        } else {
            rchild_->RemoveValue(val, rchild_);
        }
    } else {
        if (rchild_) {
            prev = rchild_;
            if (lchild_) {
                if (!prev->lchild_) {
                    prev->lchild_ = lchild_;
                } else {
                    BTNode<valType>::LChildLeaf(lchild_, prev->lchild_);
                }
            }
        } else {
            prev = lchild_;
        }
        // delete this;
    }
    // if (prev == nullptr) {
    //     std::cout << "prev is null\n";
    // } else {
    //     std::cout << "prev:" << prev->val_ << "\n";
    // }
}

template <typename valType>
void BTNode<valType>::PreOrder(BTNode *pt, std::ostream &os) const {
    // std::cout << *pt << std::endl;
    if (pt) {
        DisplayVal(pt, os);
        if (pt->lchild_) {
            PreOrder(pt->lchild_, os);
        }
        if (pt->rchild_) {
            PreOrder(pt->rchild_, os);
        }
    }
}

template <typename valType>
void BTNode<valType>::InOrder(BTNode *pt, std::ostream &os) const {
    if (pt) {
        if (pt->lchild_) {
            InOrder(pt->lchild_, os);
        }
        DisplayVal(pt, os);
        if (pt->rchild_) {
            InOrder(pt->rchild_, os);
        }
    }
}

template <typename valType>
void BTNode<valType>::PostOrder(BTNode *pt, std::ostream &os) const {
    if (pt) {
        if (pt->lchild_) {
            PostOrder(pt->lchild_, os);
        }
        if (pt->rchild_) {
            PostOrder(pt->rchild_, os);
        }
        DisplayVal(pt, os);
    }
}

template <typename valType>
BTNode<valType>::~BTNode() {
    // Delete the left child
    if (lchild_) {
        delete lchild_;
        lchild_ = nullptr;
    }

    // Delete the right child
    if (rchild_) {
        delete rchild_;
        rchild_ = nullptr;
    }
}

#endif
