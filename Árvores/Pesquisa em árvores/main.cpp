#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {//Function to create the first node
    Node* newNode = new Node();//Create a new node pointer
    newNode->data = value;//Add the number of the vertex in it
    newNode->left = nullptr;//Add a null value
    newNode->right = nullptr;//Add a null value
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

int main() {
    int N, X;
    cin >> N;

    // Creating binary tree 
    Node* tree = nullptr;//Create a pointer that point to nothing
    for (int i = 0; i < N; i++) {//Loop to add the branches
        int num;//Number of the branche
        cin >> num;
        tree = insert(tree, num);//Loop to insert a new data in the tree
    }

    // Reading the number for search
    cin >> X;

    // Search the number
    if (search(tree, X)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
