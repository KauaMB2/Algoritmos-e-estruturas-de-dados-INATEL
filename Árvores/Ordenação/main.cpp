#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a node
Node* createNode(int value) {
    Node* newNode = new Node();
    (*newNode).data = value;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

// Function to insert node
Node* insert(Node* tree, int value) {
    if (tree == nullptr) {
        return createNode(value);
    }
    if (value < (*tree).data) {
        (*tree).left = insert((*tree).left, value);
    } else if (value > (*tree).data) {
        (*tree).right = insert((*tree).right, value);
    }
    return tree;
}
//Function to pass through all the elements of the binary tree
int contaFolhas(Node* tree) {
    if(tree==nullptr){
        return 0;
    }
    if ((*tree).left == nullptr && (*tree).right == nullptr) {
        return 1; // Node is a leaf node
    }
    // Recursively count the number of leaf nodes in the left and right subtrees
    int leftLeafCount = contaFolhas(tree->left);
    int rightLeafCount = contaFolhas(tree->right);
    return leftLeafCount+rightLeafCount;
}

int maior(Node* tree) {
    while((*tree).right!=nullptr){//While the next element is not void
        tree=(*tree).right;//Get the element of the right
    }
    return (*tree).data;//Return the data
}
//Function to pass through all the elements of the binary tree
int menor(Node* tree) {
    while((*tree).left!=nullptr){//While the next element is not void
        tree=(*tree).left;//Get the element of the left
    }
    return (*tree).data;//Return the data
}
int main() {
    Node* tree = nullptr;//Create a void tree
    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        tree = insert(tree, value);//Insert the value
    }
    int biggestValue=maior(tree); // Order to the descending order
    int lowestValue=menor(tree); // Order to the descending order
    cout << lowestValue << " e " << biggestValue;
    return 0;
}
