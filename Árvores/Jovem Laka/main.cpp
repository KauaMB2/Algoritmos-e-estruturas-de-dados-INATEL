#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    (*newNode).data = value;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

// Function to insert a new node into the tree
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

// Function to traverse the tree in pre-order and populate a vector
void preOrder(Node* tree, vector<int>& result) {
    if (tree != nullptr) {
        result.push_back((*tree).data); // Add data of the current tree
        preOrder((*tree).left, result); // Traverse the left subtree
        preOrder((*tree).right, result); // Traverse the right subtre
    }
}

// Function to traverse the tree in in-order and populate a vector
void inOrder(Node* tree, vector<int>& result) {
    if (tree != nullptr) {
        inOrder((*tree).left, result); // Traverse the left subtree
        result.push_back((*tree).data); // Add data of the current tree
        inOrder((*tree).right, result); // Traverse the right subtre
    }
}

// Function to traverse the tree in post-order and populate a vector
void postOrder(Node* tree, vector<int>& result) {
    if (tree != nullptr) {
        postOrder((*tree).left, result); // Traverse the left subtree
        postOrder((*tree).right, result); // Traverse the right subtre
        result.push_back((*tree).data); // Add data of the current tree
    }
}

int main() {
    Node* tree = nullptr;
    vector<int> preOrderResult, inOrderResult, postOrderResult;
    int num;
    // Input numbers until -1 is encountered
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        tree = insert(tree, num); // Insert number into the tree
    }
    int X;
    cin >> X;

    // Traverse the tree and populate vectors
    preOrder(tree, preOrderResult);
    inOrder(tree, inOrderResult);
    postOrder(tree, postOrderResult);

    string result="";
    for(int i=0;i<preOrderResult.size();i++){
        if(preOrderResult[i]==X){
            result="Pre";
            break;
        }
        if(inOrderResult[i]==X){
            result="Em";
            break;
        }
        if(postOrderResult[i]==X){
            result="Pos";
            break;
        }
    }
    cout << result;
    return 0;
}
