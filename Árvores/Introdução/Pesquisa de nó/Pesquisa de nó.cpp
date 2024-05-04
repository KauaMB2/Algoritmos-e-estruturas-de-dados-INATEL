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

// Função para inserir um novo nó em uma árvore binária de busca
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

int findNodeLevel(Node* root, int target, int level) {//Function to find a specific node in the tree
    if (root == nullptr) {//If the tree is empty
        return -1; // Return -1(Node not found)
    } else if ((*root).data == target) {//When we find the node
        return level; // Return the level of the node
    } else {
        // Recursively search the subtrees in the right and in the left
        int leftLevel = findNodeLevel((*root).left, target, level + 1);//Find the levels in the left of the current node
        int rightLevel = findNodeLevel((*root).right, target, level + 1);//Find the levels in the right of the current node
        if (leftLevel != -1){//If the node of the right is empry
            return leftLevel;// Return -1(Node doesn't exist)
        }
        if (rightLevel != -1){
            return rightLevel;// Return -1(Node doesn't exist)
        }
        // If the node don't be found in a tree
        return -1;// Return -1(Node not found)
    }
}

int main() {
    // Construindo uma árvore binária de busca de exemplo
    Node* root = nullptr;
    root = insert(root, 7);
    insert(root, 4);
    insert(root, 10);
    insert(root, 8);
    insert(root, 8); // Vamos assumir que permitimos duplicatas na árvore
    insert(root, 15);

    int targetNode = 15;// Valor do nó cujo nível queremos encontrar

    int level = findNodeLevel(root, targetNode, 0);// Encontrar o nível do nó alvo na árvore

    // Exibir o nível do nó alvo
    if (level != -1) {
        cout << "O nivel do no com valor " << targetNode << " eh: " << level << endl;
    } else {
        cout << "O no com valor " << targetNode << " nao foi encontrado na arvore." << endl;
    }

    return 0;
}
