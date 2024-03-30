#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
// Pré-ordem: Você visita o nó raiz primeiro, depois o filho da esquerda e por fim o filho da direita.
// Em ordem: Você visita o filho da esquerda primeiro, depois o nó raiz e por fim o filho da direita.
// Pós-ordem: Você visita os filhos primeiro (esquerda e direita) e por último o nó raiz.
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

    // Traverse the tree and populate vectors
    preOrder(tree, preOrderResult);
    inOrder(tree, inOrderResult);
    postOrder(tree, postOrderResult);

    // Print vectors
    cout << "Pre-order: ";
    for (int num : preOrderResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "In-order: ";
    for (int num : inOrderResult) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Post-order: ";
    for (int num : postOrderResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
