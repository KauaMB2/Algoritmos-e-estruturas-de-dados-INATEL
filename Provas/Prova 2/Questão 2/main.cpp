#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef float ValueType;

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

void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
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

// Funções para Algoritmos Geométricos ----------------------------------------

typedef struct {
	int x;
	int y;	
} Ponto;

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}
// ----------------------------------------------------------------------------

int main(){
    int P;
    cin >> P;
    int espessura, diametro, altura;
    Node* tree = nullptr;
    for(int i=0;i<P;i++){
        Ponto p1, p2, p3;
        // Leitura das coordenadas dos pontos
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        cin >> p3.x >> p3.y;
        float comprimento12=distancia(p1, p2);
        float comprimento13=distancia(p1, p3);
        float comprimento=comprimento13;
        if(comprimento12>comprimento13){
            comprimento=comprimento12;
        }
        DataType Peixe={i, comprimento};
        tree = insert(tree, Peixe);
    }
    show_ordered(tree);
    destruct(tree);
    return 0;
}