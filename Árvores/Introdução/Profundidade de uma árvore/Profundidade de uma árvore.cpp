#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = new Node();
    (*newNode).data = data;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {// Function to insert a new node into a binary search tree
    if (root == nullptr) {//If the current node is pointer null
        return createNode(data);//Create a new node in the current position
    } else {//If the current node is not a null pointer
        if (data <= (*root).data) {//If the data value is lowest than the current data
            (*root).left = insert((*root).left, data);//Call the function again passing the next node of the left
        } else {//If the data value is lowest than the current data
            (*root).right = insert((*root).right, data);//Call the function again passing the next node of the right
        }
        return root;//Return the tree
    }
}

int depthOfTree(Node* root) {// Function to find the height of a binary search tree
    if (root == nullptr) {//If the tree is empty
        return -1; // Height of an empty tree is -1
    } else {//If the tree is not empty
        int leftHeight = depthOfTree((*root).left);//Calculate the height of the tree in the left node
        int rightHeight = depthOfTree((*root).right);//Calculate the height of the tree in the right node
        return max(leftHeight, rightHeight) + 1;//Compare both results and return
    }
}

int main() {
    // Construindo uma árvore binária de busca de exemplo
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 8);
    insert(root, 12);
    insert(root, 18);

    // Calculando a profundidade da árvore
    int treeDepth = depthOfTree(root);
    cout << "Profundidade da arvore: " << treeDepth << endl;

    return 0;
}
