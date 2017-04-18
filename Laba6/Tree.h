//
// Created by Gleb Linnik on 17.04.17.
//

#ifndef LABA6_TREE_H
#define LABA6_TREE_H

template <class T>
struct TreeNode;

enum TreeNodeType {
    TreeNodeTypeNullPtr,
    TreeNodeTypeLeaf,
    TreeNodeTypeOneKid,
    TreeNodeTypeTwoKids,
};

template <class T>
class Tree {
public:
    Tree();
    ~Tree();

    void destroy();
    void insert(T key);
    void deleteNode(T key);
    TreeNode<T> *search(T key);

    static TreeNodeType getNodeType(TreeNode<T> *node);
private:
    void destroy(TreeNode<T> *leaf);
    void insert(T key, TreeNode<T> *leaf);
    TreeNode<T> *search(T key, TreeNode<T> *leaf);
    TreeNode<T> *_root;
};

template <class T>
struct TreeNode {
    TreeNode *leftBranch;
    TreeNode *rightBranch;
    T key;
};
#endif //LABA6_TREE_H
