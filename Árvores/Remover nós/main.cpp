#include <iostream>
#include <set>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    (*newNode).info = value;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

Node* insert(Node* tree, int value) {
    if (tree == nullptr) {
        return createNode(value);
    }
    if (value < (*tree).info) {
        (*tree).left = insert((*tree).left, value);
    } else if (value > (*tree).info) {
        (*tree).right = insert((*tree).right, value);
    }
    return tree;
}

Node* remove(Node* tree, int value) {
    if (tree == nullptr) {//if the tree is void...
        return nullptr;//Return a null pointer
    }
    if (value < (*tree).info) {//If the value is lowest than the current tree value
        (*tree).left = remove((*tree).left, value);
    } else if (value > (*tree).info) {//If the value is lowest than the current tree value
        (*tree).right = remove((*tree).right, value);
    } else {//If the value and the current tree value are equal
        if ((*tree).left == nullptr) {//If the tree in the left is null
            Node* temp = (*tree).right;//Get the tree of the right
            delete tree;//Delete the node
            return temp;//Return the right node of the node that was deleted
        } else if ((*tree).right == nullptr) {//If the tree in the right is null
            Node* temp = (*tree).left;//Get the tree of the left
            delete tree;//delete the node
            return temp;//Return the left node of the node that was deleted
        }
        Node* temp = (*tree).right;//Get the node of the right
        while ((*temp).left != nullptr) {//while the nodes of the left is not null...
            temp = (*temp).left;//Get the left node of the current node
        }
        (*tree).info = (*temp).info;//Update the tree info data
        (*tree).right = remove((*tree).right, (*temp).info);
    }
    return tree;
}

void inorderTraversal(Node* tree, set<int>& values) {
    if (tree != nullptr) {
        inorderTraversal((*tree).left, values);
        values.insert((*tree).info);
        inorderTraversal((*tree).right, values);
    }
}

int main() {
    int num;
    Node* tree = nullptr;

    // Ler os números e inseri-los na árvore
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        tree = insert(tree, num);
    }

    int x;
    cin >> x;

    // Remover os nós cujo campo info é igual a x
    tree = remove(tree, x);

    // Realizar o percurso em ordem crescente e mostrar os nós restantes
    set<int> values;
    inorderTraversal(tree, values);
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
