//
// Created by Gleb Linnik on 17.04.17.
//

#include <cstdlib>
#include "Tree.h"

template <class T>
Tree<T>::Tree() {
    _root = NULL;
}

template <class T>
Tree<T>::~Tree() {
    destroy();
}

template <class T>
void Tree<T>::destroy(TreeNode<T> *leaf) {
    if (leaf) {
        destroy(leaf->leftBranch);
        destroy(leaf->rightBranch);
        delete leaf;
    }
}

template <class T>
void Tree<T>::insert(T key, TreeNode<T> *leaf) {
    if (key < leaf->key) {
        if (leaf->leftBranch) {
            insert(key, leaf->leftBranch);
        } else {
            leaf->leftBranch = new TreeNode<T>(key);
        }
    } else if (key > leaf->key) {
        if (leaf->rightBranch) {
            insert(key, leaf->rightBranch);
        } else {
            leaf->rightBranch = new TreeNode<T>(key);
        }
    }
}

template <class T>
TreeNode<T> *Tree<T>::search(T key, TreeNode<T> *leaf) {
    if (key == leaf->key) {
        return leaf;
    } else if (key > leaf->key) {
        if (leaf->rightBranch)
            return search(key, leaf->rightBranch);
    } else if (key < leaf->key) {
        if (leaf->leftBranch)
            return search(key, leaf->leftBranch);
    }
    return NULL;
}

//Public methods definition
template <class T>
void Tree<T>::destroy() {
    destroy(_root);
}

template <class T>
void Tree<T>::insert(T key) {
    if (_root) {
        insert(key, _root);
    }else {
        _root = new TreeNode<T>(key);
    }
}

template <class T>
void Tree<T>::deleteNode(T key) {
    if (!search(key))
        return;
    TreeNode<T> *parent = _root;
    TreeNode<T> *current = NULL;

    if (key > _root->key) {
        current = _root->rightBranch;
    } else if (key > _root->key) {
        current = _root->leftBranch;
    }

    if (current) {
        while (current->key != key) {
            parent = current;
            if (key > current->key) {
                if (current->rightBranch)
                    current = current->rightBranch;
                else
                    break;
            } else if (key < current->key) {
                if (current->leftBranch)
                    current = current->leftBranch;
                else
                    break;
            } else {
                break;
            }
        }
    } else {
        current = parent;
    }

    switch (getNodeType(current)) {
        case TreeNodeTypeLeaf:
        case TreeNodeTypeOneKid:
            if (parent->leftBranch) {
                if (parent->leftBranch->key == current->key)
                    parent->leftBranch = current->leftBranch ?
                                           current->leftBranch :
                                           current->rightBranch;
            }
            if (parent->rightBranch) {
                if (parent->rightBranch->key == current->key)
                    parent->rightBranch = current->leftBranch ?
                                            current->leftBranch :
                                            current->rightBranch;
            }
            delete current;
            break;
        case TreeNodeTypeTwoKids:
            parent = current->rightBranch;
            if (parent->leftBranch) {
                while (parent->leftBranch->leftBranch) {
                    parent = parent->leftBranch;
                }
                current->key = parent->leftBranch->key;
                TreeNode<T> *nodeToDelete = parent->leftBranch;
                parent->leftBranch = parent->leftBranch->rightBranch;
                delete nodeToDelete;
            } else {
                current->key = parent->key;
                current->rightBranch = parent->rightBranch;
                delete parent;
            }
            break;
        default:
            break;
    }

}

template <class T>
TreeNode<T> *Tree<T>::search(T key) {
    return search(key, _root);
}

template <class T>
TreeNodeType Tree<T>::getNodeType(TreeNode<T> *node) {
    if (node) {
        if (node->leftBranch && node->rightBranch)
            return TreeNodeTypeTwoKids;
        else if (node->leftBranch || node->rightBranch)
            return TreeNodeTypeOneKid;
        else
            return TreeNodeTypeLeaf;
    } else {
        return TreeNodeTypeNullPtr;
    }
}





