#include <iostream>
#include <queue>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct Data {
	KeyType key;
	ValueType value;
};

typedef struct Data DataType;

typedef struct Node {
	DataType data;
	Node * right;
	Node * left;
} Node;


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

void show_ordered(Node * curr, int Tmin, int Tmax){
	if(curr->left != NULL)
		show_ordered(curr->left, Tmin, Tmax);
	if((curr->data.value>=Tmin)&&(curr->data.value<=Tmax)){
	    cout << curr->data.key << ":" << curr->data.value << endl;
	}
	if(curr->right != NULL)
		show_ordered(curr->right, Tmin, Tmax);
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
    int P;
    cin >> P;
    Node* tree = nullptr;
    int N=7;
    for(int i=0;i<P;i++){
        float V, E, O;
        int T;
        cin >> V >> E >> O;
        T = int(V*E*N*E*N*O);
        DataType Veneno={i, T};
        tree = insert(tree, Veneno);
    }
    int Tmin, Tmax;
    cin >> Tmin >> Tmax;
    show_ordered(tree, Tmin, Tmax);
    destruct(tree);
    return 0;
}