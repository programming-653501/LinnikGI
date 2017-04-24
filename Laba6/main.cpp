#include <iostream>
#include "Tree.cpp"

using namespace std;

int main() {
    string userEnteredString;
    cout << "Enter the string to build the BTS: ";
    cin >> userEnteredString;
    Tree<char> *tree = new Tree<char>();
    for (char character : userEnteredString) {
        tree->insert(character);
    }
    cout << "Maximum level before balancing: " << tree->getMaxLevel(tree->_root, 0) + 1 << endl;
    tree->balance();
    cout << "Maximum level after balancing: " << tree->getMaxLevel(tree->_root, 0) + 1 << endl;
    tree->print();
    return 0;
}