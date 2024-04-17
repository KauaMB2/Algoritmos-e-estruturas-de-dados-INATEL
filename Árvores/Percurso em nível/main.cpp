#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    (*newNode).data = value;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

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

void BFS(Node* tree) {//BFS - Breadth-First Search - Busca em largura
    if (tree == nullptr) {
        return;
    }
    queue<Node*> q;//Create the queue
    q.push(tree);//Put the tree in the queue
    
    while (!q.empty()) {//While the queue is not void...
        Node* current = q.front();//Ge the front elemento of the queue
        q.pop();//Take out the element of the queue
        cout << (*current).data << " ";//Show the data
        
        if ((*current).left != nullptr) {//If there is node in the left of the current node...
            q.push((*current).left);//Add the node left node in the queue
        }
        if ((*current).right != nullptr) {//If there is node in the right of the current node... 
            q.push((*current).right);//Add the right node in the queue
        }
    }
}

int main() {
    int num;
    Node* tree = nullptr;

    // Read the numbers
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        tree = insert(tree, num);
    }

    // Realize the traversing in level
    BFS(tree);
    cout << endl;

    return 0;
}
