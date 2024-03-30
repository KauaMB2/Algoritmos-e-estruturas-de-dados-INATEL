#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {//Function to create the first node
    Node* newNode = new Node();//Create a new node pointer
    (*newNode).data = value;//Add the number of the vertex in it
    (*newNode).left = nullptr;//Add a null value
    (*newNode).right = nullptr;//Add a null value
    return newNode;//Return the first pointer
}

// Função para inserir um valor na árvore binária
Node* insert(Node* tree, int value) {
    if (tree == nullptr) {//if the tree be void...
        return createNode(value);//Create the first node
    }
    if (value < (*tree).data) {//If the value is lowest than the tree.data
        (*tree).left = insert((*tree).left, value);//insert the value in the left branch
    } else if (value > (*tree).data) {//If the value is biggest than the tree.data
        (*tree).right = insert((*tree).right, value);//insert the value in the right branch
    }
    return tree;//Return the tree
}

// Function to search a value in the tree
bool search(Node* tree, int value) {
    if (tree == nullptr) {//if the tree is void...
        return false;
    }
    if ((*tree).data == value) {//if the tree is equal to the value searched...
        return true;
    } else if (value < (*tree).data) {//if the value is lowest than the tree data
        return search((*tree).left, value);// Try search in the left tree
    } else {//if the value is biggest than the tree data
        return search((*tree).right, value);//try search in the right tree
    }
}
//Function to pass through all the elements of the binary tree
void traverse(Node* tree) {
    if (tree != nullptr) {//If the element is not a void element...
        traverse((*tree).left);//Pass to the left branch
        cout << (*tree).data << " ";
        traverse((*tree).right);//Pass to the right branch
    }
}
int main() {
    Node* tree = nullptr;

    // Insert elements into the binary tree
    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 70);
    tree = insert(tree, 60);
    tree = insert(tree, 80);

    // Search for elements in the binary tree
    cout << "Search for 30: " << (search(tree, 30) ? "Found" : "Not found") << endl;
    cout << "Search for 100: " << (search(tree, 100) ? "Found" : "Not found") << endl;

    // Traverse all elements in the binary tree
    cout << "Elements in the binary tree (inorder traversal): ";
    traverse(tree);
    cout << endl;
    
    return 0;
}
