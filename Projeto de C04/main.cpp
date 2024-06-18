/*
tema: Pokedex

integrantes:
André Dias Balbino
Matheus de Alencar Costa Oliveira
Kauã Moreira Batista

O codigo cadastra em listas distintas pokemon e cidades, 
e mostra as informaçoes armazenadas quando desejado.
*/

#include<iostream>
#include<list>
#include <string.h>
#include <math.h>
using namespace std;
#define INT_MAX 99999

struct caminhos
{
	int destinatario;
	int origem;
	int dist;
};

struct cidade{
	int codigo;//codigo da cidade
	string nome;//nome da cidade
	bool centroPokemon;//se tem centro pokemon ou não
	list <caminhos> rotas;
};

cidade cadastrarCidade(int codigo){
	//cria uma variavel do tipo cidade e cadastra as infomações dela
	cidade novo;
	int destino;
	int dist;
	novo.codigo = codigo;
	cout << "Codigo da Cidade: " << novo.codigo << endl;
	cout << "Digite o nome da cidade: " << endl;
	cin >> novo.nome;
	cout << "Digite se existe centro pokemon (0 para nao / 1 para sim): " << endl;
	cin >> novo.centroPokemon;
	do
	{
		cout << "Entre com o codigo de outra cidade que esta conectada a essa (para sair digite -1):"<<endl;
		cin >> destino;
		
		if(destino != -1)
		{
			cout << "Entre com o tamanho do caminho:" << endl;
			cin >> dist;
			novo.rotas.push_back({destino, novo.codigo, dist});
		}
		
	}while(destino != -1);
	
	//retorna essa struct para a main
	return novo;
}

int shortest_path_dijkstra(list<cidade> city, int vertices, int start, int end, bool achado){
	bool intree[vertices];
	int distance[vertices], parent[vertices];

    if(achado)
        {
            cout <<"caminho: ";
        }
	
	for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
		list<caminhos>::iterator p;
		list<cidade>::iterator PCidade = city.begin();
		advance(PCidade, v);
    	for(p = (*PCidade).rotas.begin(); p != (*PCidade).rotas.end(); p++){
            int dest = p->destinatario;
            int weight = p->dist;
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
			}
		}
        

	}
	if(achado)
        {
            list<int> ListaParentes;
            int parentes = end;
            ListaParentes.push_front(parentes);
            while(parent[parentes] != start)
            {
                ListaParentes.push_front(parent[parentes]);
                parentes = parent[parentes];
            }
            list<int>::iterator mostrarCaminho = ListaParentes.begin();
            while(mostrarCaminho != ListaParentes.end())
    {
                cout<<(*mostrarCaminho)<<" ";
                advance(mostrarCaminho, 1);
            }
        }

	return distance[end];
}
/*
cidades
-----------------------------------------------**--------------------------------------------------------------------
Pokemon
*/

typedef char KeyType;
typedef int ValueType;
typedef char NameType;

typedef struct {
	int x;
	int y;	
} Ponto;

struct Data {
	KeyType key[50];
	ValueType value;
	NameType name[50];
	Ponto ponto;
};

typedef struct Data DataType;

struct Node {
	DataType data;
	Node * right;
	Node * left;
};

typedef Node *Nodeptr;

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));//Calcula o módulo do vetor distância entre o usuário e o pokemon
}

void insertT(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(strcmp(curr->data.key,data.key) <= 0){
			insertT(curr->right, data);
		} else if(strcmp(curr->data.key,data.key) >= 1) {
			insertT(curr->left, data);
		}		
	}
}
void insertN(Node *& nome , DataType data){	
	if(nome == NULL){
		nome = new Node;
		nome->data = data;
		nome->right = NULL;
		nome->left = NULL;
	} else {
		if(strcmp(nome->data.name,data.name) <= 0){
			insertN(nome->right, data);
		} else if(strcmp(nome->data.name,data.name) >= 1) {
			insertN(nome->left, data);
		}		
	}
}

void show_ordered(Node * curr){//Percurso em ordem
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout <<"Nome: " <<curr->data.name << " Numero: " << curr->data.value << " Tipo: " << curr->data.key << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

Node * search(Node * curr, NameType name[]){
	if(curr == NULL)
		return NULL;
	if(strcmp(curr->data.name,name) == 0){
		return curr;
	} else {
		if(strcmp(curr->data.name, name) < 0){
			return search(curr->right, name);
		} else if(strcmp(curr->data.name,name) > 0){
			return search(curr->left, name);
		}
	}
	return NULL;
}

int quantidade_tipo(Node * curr, KeyType key[], int numero){//Aplica uma pesquisa em pré-ordem
    int quantidade = numero;
	if(strcmp(key, curr->data.key) == 0){//Compara lexicograficamente, ou seja, em ordem alfabética(na tabela ASCII). Se for igual, soma 1
		quantidade +=1;
	}
	if(curr->right != NULL){
		return quantidade_tipo(curr->right, key, quantidade);//Chama recursivamente o nó da direita
	} 
	if(curr->left != NULL){
		return quantidade_tipo(curr->left, key, quantidade);//Chama recursivamente o nó da esquerda
	}
	
	return quantidade;
}

int quantidade_pokemons(Node * curr, int numero, Ponto ponto){//Aplica uma pesquisa em pré-ordem
    int quantidade = numero;
	if(distancia(ponto,curr->data.ponto) <= 100){//Calcula o módulo da distância entre o ponto do usuário e o pokemon. Se for menor que 100 soma  1
		quantidade +=1;
	}
	if(curr->right != NULL){
		return quantidade_pokemons(curr->right, quantidade, ponto);//Chama recursivamente o nó da direita
	} 
	if(curr->left != NULL){
		return quantidade_pokemons(curr->left, quantidade, ponto);//Chama recursivamente o nó da esquerda
	}
	return quantidade;
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
	
	list<cidade>registro;//lista do tipo cidade
	list<cidade>::iterator ponteiroC1;//ponteiro para acessar qualquer informação dentro da lista do tipo cidade
	list<cidade>::iterator ponteiroC2;
	int origem;
	int temp;
	int saida = INT_MAX;
	int cidadeFinal;

    DataType data;
    Nodeptr arvoreNome = NULL;
    Nodeptr arvoreTipo = NULL;
    NameType nome[50];
    KeyType tipo[50];
    Ponto pokedex;
    
	int op;//operação escolhida
		do{
			//entra com um numero para selecionar uma operação
			cout<<"Sistema de pesquisa\ncidade\n 1 - Cadastrar cidade\n 2 - Buscar Centro Pokemon\nPokedex\n 3 - Cadastrar Pokemon\n Ordenar e mostrar por:\n  4 - Nome\n  5 - tipo\n 6 - Buscar pokemon por nome\n 7 - Pesquisar pokemon por tipo \n 8 - Procurar todos os pokemon na area (100m) \n\n9 - sair"<<endl;
			cin>>op;
			//tratamento para caso entre com um valor invalido
			while(op <= 0 || op >= 10){
		  		cout<<"Digite uma opcao valida: ";
				cin>>op;
			}
			//switch case para tratar o numero selecionado se estiver correto
			switch(op){
				//caso entre com o numero 1 chama a função cadastrarCidade e adiciona uma nova cidade na lista
				case 1:
					registro.push_back(cadastrarCidade(registro.size()));
					break;
				case 2:
                    cout << "Em qual cidade voce esta(Digite pelo codigo):" << endl;
					cin>>origem;
					ponteiroC1 = registro.begin();
					advance(ponteiroC1, origem);
					ponteiroC2 = registro.begin(); 
    				for(int j=0; j < registro.size(); j++){
        			if((*ponteiroC2).centroPokemon){
            			temp = shortest_path_dijkstra(registro, registro.size(),(*ponteiroC1).codigo, (*ponteiroC2).codigo, 0);
            			if(temp < saida)
            			{
                			saida = temp;
                			cidadeFinal = j;
            			}
        			}
					advance(ponteiroC2, 1);
    				}
    				ponteiroC2 = registro.begin();
					advance(ponteiroC2, cidadeFinal);

					cout << "Cidade com Centro Pokemon mais proximo: "<<(*ponteiroC2).nome<< endl;
                    shortest_path_dijkstra(registro, registro.size(),(*ponteiroC1).codigo, (*ponteiroC2).codigo, 1);
					break;
                
                case 3:
                    cout<< "Entre com o nome do pokemon: "<< endl;
                    cin >> data.name;
                    cout<< "Entre com o tipo do pokemon: "<< endl;
                    cin >> data.key;
                    cout<< "Entre com o numero do pokemon: "<< endl;
                    cin >> data.value;
                    cout<< "Entre com a posicao do pokemon (X e Y): "<< endl;
                    cin >> data.ponto.x >>data.ponto.y;
                    insertT(arvoreTipo, data);
                    insertN(arvoreNome, data);
                    break;
                    
                case 4:
                    show_ordered(arvoreNome);
                    break;
                    
                case 5:
                    show_ordered(arvoreTipo);
                    break;
                    
                    
                case 6:
                    cout<< "Qual Pokemon voce deseja buscar: "<<endl;
                    cin >> nome;
                    if(search(arvoreNome, nome)!= NULL)
                    {
                        cout<< "Pokémon encontrado!"<<endl;
                    }
                    else
                    {
                        cout<< "Pokémon não encontrado!"<<endl;
                    }
                    break;
                case 7:
                    cout<< "Qual Tipo voce deseja buscar: "<<endl;
                    cin >> tipo;
                    cout<<"Existem " <<quantidade_tipo(arvoreTipo, tipo, 0)<<" Pokemon desse tipo."<<endl;
                    break;
                case 8:
                    cout<< "Entre com sua localização: "<<endl;
                    cin>>pokedex.x >> pokedex.y;
                    cout<< "Existe(m) " << quantidade_pokemons(arvoreTipo, 0 ,pokedex)<<" Pokemon em um raio de 100m de voce."<<endl;
                    break;
                case 9:
                    destruct(arvoreTipo);
                    destruct(arvoreNome);
                    return 0;
                    break;
			}
		}while(op != 9);

	return 0;
}