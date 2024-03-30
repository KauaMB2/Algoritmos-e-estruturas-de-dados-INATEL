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

//Function to pass through all the elements of the binary tree
int traverse(Node* tree) {
    if(tree == nullptr){//If the current node is void
       return 0;
    }
    int sum = 0;
    if((*tree).data % 2 != 0){
        sum++; // Increment sum if the current node's data is odd
    }
    // Accumulate the sum of odd numbers in the left and right subtrees
    sum += traverse((*tree).left) + traverse((*tree).right);
    return sum;
}

int main() {
    int N;
    cin >> N;

    // Creating binary tree 
    Node* tree = nullptr;//Create a pointer that point to nothing
    int num;
    // Input numbers until -1 is encountered
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        tree = insert(tree, num); // Insert number into the tree
    }
    int value=traverse(tree);
    cout << value << " numeros primos";
    return 0;
}
