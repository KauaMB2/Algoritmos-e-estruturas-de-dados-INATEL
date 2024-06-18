#include <iostream>
#include <stack>
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

// Function to order in the descending order
void reverseInOrderTraversal(Node* tree) {
    stack<Node*> s;//create a stack
    Node* current = tree;//Get the current element
    while (current != nullptr || !s.empty()) {//While the stack isn't empty
        // Go through the node more to the right possible
        while (current != nullptr) {//If the current element doesn't be a null pointer
            s.push(current);//Add it in the stack
            current = (*current).right;//Get the node of the right
        }

        current = s.top();//Get the top node
        s.pop();//Take out the top node
        cout << (*current).data << " "; // Print the value
        current = (*current).left;// Get the node of the left
    }
}
// Function to order in the ascending order
void InOrderTraversal(Node* tree) {
    stack<Node*> s;//create a stack
    Node* current = tree;//Get the current element
    while (current != nullptr || !s.empty()) {//While the stack isn't empty
        // Go through the node more to the right possible
        while (current != nullptr) {//If the current element doesn't be a null pointer
            s.push(current);//Add it in the stack
            current = (*current).left;//Get the node of the right
        }

        current = s.top();//Get the top node
        s.pop();//Take out the top node
        cout << (*current).data << " "; // Print the value
        current = (*current).right;// Get the node of the left
    }
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
    reverseInOrderTraversal(tree); // Order to the descending order
    return 0;
}
