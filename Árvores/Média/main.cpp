#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    float data;
    Node* left;
    Node* right;
};
//Function to pass through all the elements of the binary tree
float media(Node* tree) {
   if(tree==nullptr){
       return 0.0;
   }
   float sum = (*tree).data + media((*tree).left) + media((*tree).right);
   return sum;
}
Node* createNode(float value) {//Function to create the first node
    Node* newNode = new Node();//Create a new node pointer
    newNode->data = value;//Add the number of the vertex in it
    newNode->left = nullptr;//Add a null value
    newNode->right = nullptr;//Add a null value
    return newNode;//Return the first pointer
}

Node* insert(Node* tree, int value){
    if (tree == nullptr) {//if the tree be void...
        return createNode(value);//Create the first node
    }
    if (value < (*tree).data) {//If the value is lowest than the tree.data
        (*tree).left = insert((*tree).left, value);//insert the value in the left branch
    } else if (value >= (*tree).data) {//If the value is biggest than the tree.data
        (*tree).right = insert((*tree).right, value);//insert the value in the right branch
    }
    return tree;//Return the tree
}
int main(){
    Node* tree=nullptr;//Create a void pointer
    int counter=0;//Create a counter
    while(true){
        int N;
        cin >> N;
        if(N ==-1){
            break;
        }
        tree=insert(tree, N);//Insert the data in the tree
        counter++;
    }
    float value=media(tree);//Calculate the media
    cout << fixed << setprecision(2);
    cout << "Media: " << value/counter;//Show the media
    
    return 0;
}