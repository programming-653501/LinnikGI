//
// Created by Gleb Linnik on 17.04.17.
//

#include <cstdlib>
#include <cmath>
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
void compress(TreeNode<T> *root, int count) {
    TreeNode<T> *scanner = root;
    for (int i = 1; i <= count; i++) {
        TreeNode<T> *child = scanner->rightBranch;
        scanner->rightBranch = child->rightBranch;
        scanner = scanner->rightBranch;
        child->rightBranch = scanner->leftBranch;
        scanner->leftBranch = child;
    }
}

template <class T>
void tree_to_vine(TreeNode<T> *root) {
    // Convert tree to a "vine", i.e., a sorted linked list,
    // using the right pointers to point to the next node in the list
    TreeNode<T> *tail = root;
    TreeNode<T> *rest = tail->rightBranch;
    while (rest) {
        if (!rest->leftBranch) {
            tail = rest;
            rest = rest->rightBranch;
        } else {
            TreeNode<T> *temp = rest->leftBranch;
            rest->leftBranch = temp->rightBranch;
            temp->rightBranch = rest;
            rest = temp;
            tail->rightBranch = temp;
        }
    }
}

template <class T>
void vine_to_tree(TreeNode<T> *root, int size) {
    int leaves = (int) (size + 1 - floor(pow(2, log2(size + 1))));
    compress(root, leaves);
    size -= leaves;
    while (size > 1) {
        compress(root, (int)floor(size / 2.0));
        size = (int)floor(size / 2.0);
    }
}

//Private methods definition
template <class T>
void Tree<T>::balance() {
    TreeNode<T> *pseudoRoot = new TreeNode<T>();
    pseudoRoot->rightBranch = _root;
    tree_to_vine(pseudoRoot);
    int count = 0;
    for (TreeNode<T> *node = pseudoRoot; node; node = node->rightBranch, count++);
    vine_to_tree(pseudoRoot, --count);
    _root = pseudoRoot->rightBranch;
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






