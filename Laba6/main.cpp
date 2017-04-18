#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int> *tree = new Tree<int>();
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(50);
    tree->insert(90);
    tree->insert(100);
    tree->insert(150);
    tree->insert(160);
    tree->insert(200);
    tree->insert(210);
    tree->balance();
    TreeNode<int> *a = tree->search(10);
    tree->deleteNode(50);
    std::cout << a->key << std::endl;
    std::cout << Tree<int>::getNodeType(a) << std::endl;
    return 0;
}