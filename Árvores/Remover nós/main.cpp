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
        //There is tree posibilities to remove
        //1. The node to be deleted does't have a left element
        if ((*tree).left == nullptr) {//If the tree in the left is null
            //It means that the node to be deleted has no left child, so we replace the current node with its right child.
            Node* temp = (*tree).right;//Get the tree of the right
            delete tree;//Delete the node
            return temp;//This line returns the right child of the deleted node, effectively replacing the deleted node with its right child.
        } else if ((*tree).right == nullptr) {//If the tree in the right is null
            //2. The node to be deleted does't have a right element
            //It means that the node to be deleted has no right child, so we replace the current node with its left child.
            Node* temp = (*tree).left;//Get the tree of the left
            delete tree;//delete the node
            return temp;//This line returns the left child of the deleted node, effectively replacing the deleted node with its left child
        }
        //When even not the tree of the right and the tree of the left is void, it is necessary get the biggest chuldren of the current node(right - (*tree).right)
        //And after that get the smaller element possible of the (*tree).right element and say it is the new value that will fill the position of the node that was deleted
        //3. The node to be deleted have the left and the right element
        Node* temp = (*tree).right;//Get the node of the right
        while ((*temp).left != nullptr) {//while the nodes of the left is not null...
            temp = (*temp).left;//Get the left node of the current node
        }
        (*tree).info = (*temp).info;//Update the tree info data
        (*tree).right = remove((*tree).right, (*temp).info);//Call the function again to  delete (*temp).info node in the right subtrees to be sure won't have duplicated values
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

    // Read the number inserting in the tree
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        tree = insert(tree, num);
    }

    int x;
    cin >> x;

    // Remove the nodes that the info is equal to X
    tree = remove(tree, x);

    // Do the traversal in the ascending order
    set<int> values;
    inorderTraversal(tree, values);
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
