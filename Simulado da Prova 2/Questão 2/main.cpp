#include <iostream>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct DataType {
	KeyType key;
	ValueType value;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
};


Node* insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
		return curr;
	} else {
		if(data.value >= curr->data.value){
			insert(curr->right, data);
		} else if(data.value < curr->data.value) {
			insert(curr->left, data);
		}
	}
	return curr;
}

void show_ordered(Node * curr, int PFmin, int PFmax){
	if(curr->left != NULL){
		show_ordered(curr->left, PFmin, PFmax);
	}
	if((curr->data.value>=PFmin)&&(curr->data.value<=PFmax)){
	    cout << curr->data.key << ":" << curr->data.value << endl;
	}
	if(curr->right != NULL)
		show_ordered(curr->right, PFmin, PFmax);
}


void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

int main(){
    int T;
    cin >> T;
    Node* tree = nullptr;
    for(int i=0;i<T;i++){
        float EM, P, A, D;
        int PF;
        cin >> EM >> P >> A>> D;
        PF = (EM*P*A+D+A);
        DataType Torta={i, PF};
        tree = insert(tree, Torta);
    }
    int PFmin, PFmax;
    cin >> PFmin >> PFmax;
    show_ordered(tree, PFmin, PFmax);
    destruct(tree);
    return 0;
}

// ----------------------------------------------------------------------------