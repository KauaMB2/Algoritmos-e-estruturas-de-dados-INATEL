/*
Tema: Pokedex

Integrantes:
André Dias Balbino
Matheus de Alencar Costa Oliveira
Kauã Moreira Batista

O código cadastra em listas distintas pokemons(pokedex) e cidades(registro), 
e mostra/pesquisa as informaçoes armazenadas quando desejado.
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

#define INF INT_MAX//Define a variável INF como sendo o valor máximo inteiro

struct cidade{
	int codigo;//codigo da cidade
	string nome;//nome da cidade
	bool centroPokemon;//se tem centro pokemon ou não
	vector<caminho> cidadesAdj;//Armazena as cidades adjacentes à cidade em questão
};
struct caminho{
	int dest;//Destino
	int dist;//Distância
};

struct pokemon{
	int numero;//numero do pokemon
	string nome;//nome do pokemon
	string tipo;//tipo do pokemon
};
//função que cadastra uma nova cidade
cidade cadastrarCidade(){
	//cria uma variavel do tipo cidade e cadastra as infomações dela
	cidade novo;
	cout << "Digite o codigo da cidade: " << endl;
	cin >> novo.codigo;
	cin.ignore();
	cout << "Digite o nome da cidade: " << endl;
	getline(cin, novo.nome);
	cout << "Digite se existe centro pokemon (0 para nao / 1 para sim): " << endl;
	cin >> novo.centroPokemon;
	while(true){
		int destino, distancia;
		cin >> destino >> distancia;
		if(destino==-1){
			break;
		}
		novo.cidadesAdj.push_back({ destino, distancia });
	}
	//retorna essa struct para a main
	return novo;
}
//função que entra com uma cidade e mostra as informações dela
void mostrarCidade(cidade registro) {
	cout<<"\nCidade: "<<registro.codigo<<endl;
	cout<<"Nome: "<<registro.nome<<endl; 

	//se centro pokemon for 1(ou verdadeiro) mostra "Centro Pokemon: sim"
	if(registro.centroPokemon){
		cout<<"Centro Pokemon: Sim"<<endl<<endl;
	}
	//se não mostra "Centro Pokemon: não"
	else
	{
		cout<<"Centro Pokemon: Nao"<<endl<<endl;
	}
	
}

//função que cadastra um novo pokemon
pokemon cadastrarPokemon(){
	//cria uma variavel do tipo pokemon e entra com as informações dela
	pokemon novo;
	cout << "Digite o numero do pokemon: " << endl;
	cin >> novo.numero;
	cin.ignore();
	cout << "Digite o nome do pokemon: " << endl;
	getline(cin, novo.nome);
	cout << "Digite o tipo do pokemon: " << endl;
	cin >> novo.tipo;
	//retorna a struct criada para a main
	return novo;
}

//função que entra com um pokemon mostra as informações dele
void mostrarPokemon(pokemon registro) {
	cout<<"\nPokemon: "<<registro.numero<<endl;
	cout<<"Nome: "<<registro.nome<<endl;
	cout << "Tipo: "<< registro.tipo<<endl<<endl;
	
}

int main(){
	
	list<cidade>registro;//lista do tipo cidade
	list<cidade>::iterator ponteiroC;//ponteiro para acessar qualquer informação dentro da lista do tipo cidade
	vector<vector<cidade>> grafoCidade;//Grafo para armazenar as cidades

	list<pokemon>pokedex;//lista do tipo pokemon
	vector<pokemon> vetorPokedex;
	list<pokemon>::iterator ponteiroP;//ponteiro para acessar qualquer informação da lista do tipo pokemon
	
	bool achou;//variavel para a achar um pokemon ou cidade especifica
	int op;//operação escolhida
	int acharCodigo;//entrada do codigo a ser procurado
		do{
			//entra com um numero para selecionar uma operação
			cout<<"\n[+] Sistema de Pesquisa e Cadastro [+]\n\nCIDADE:\n 1 - Cadastrar cidade\n 2 - Procurar cidade\n 3 - Mostrar cidades\n\nPOKEDEX:\n 4 - Cadastrar Pokemon\n 5 - Procurar Pokemon\n 6 - Mostrar Pokemons\n\n 7 - sair"<<endl;
			cout<<"\nOpção: ";
			cin>>op;
			//tratamento para caso entre com um valor invalido
			while(op <= 0 || op >= 7){
		  		cout<<"Digite uma opcao valida: ";
				cin>>op;
			}
			//Variáveis para a pesquisa binária(Caso 5)
			int lowNumero;//Número menor
			int highNumero = vetorPokedex.size() - 1;//Número maior
			pokemon resultado;//Armazena resultado da pesquisa binária

			//Variáveis para inserir um novo pokemon o vetor de forma ordenada(Caso 4)
			pokemon novoPokemon;
			//switch case para tratar o numero selecionado se estiver correto
			switch(op){
				//caso entre com o numero 1 chama a função cadastrarCidade e adiciona uma nova cidade na lista
				case 1:
					registro.push_back(cadastrarCidade());
					break;
				//caso entre com o numero 2 procura por uma cidade em especifico e mostra suas informções
				case 2:
					//entra com o codigo da cidade desejada
			    	cout<<"Qual é o codigo da cidade desejada: "<<endl;
			    	cin >> acharCodigo;
			 	   	break;

				// mostrar todas as cidades cadastradas
				case 3:
					if(registro.empty()){
						cout << "\nNENHUMA CIDADE CADASTRADA!\n" << endl;
						break;
					}

					cout << "Lista de todas as cidades:" << endl;

					// Iterando sobre a lista
					for (ponteiroC = registro.begin(); ponteiroC != registro.end(); ++ponteiroC) {
						mostrarCidade(*ponteiroC);
					}
					
					break;

			    //caso entre com o numero 4 chama a função cadastrarPokemon e adiciona um novo pokemon a lista
				case 4:
					novoPokemon = cadastrarPokemon();
					pokedex.push_back(novoPokemon);
					vetorPokedex.push_back(novoPokemon);

				//caso entre com o numero 5 procura por um pokemon em especifico e mostra suas informções
				case 5:
					//entra com o numero do pokemon desejada
			    	cout<<"Qual é o numero do pokemon desejada: "<<endl;
			    	cin >> acharCodigo;

					lowNumero=0;
					highNumero=vetorPokedex.size() - 1;
					sort(vetorPokedex.begin(), vetorPokedex.end(), [](const pokemon& p1, const pokemon& p2) {
						return p1.numero < p2.numero;
					});
					while (lowNumero <= highNumero) {
						int mid = (lowNumero + highNumero) / 2;
						int mid_val = vetorPokedex[mid].numero;

						if (mid_val == acharCodigo) {
							mostrarPokemon(vetorPokedex[mid_val]);
						} else if (mid_val < acharCodigo) {
							lowNumero = mid + 1;
						} else {
							highNumero = mid - 1;
						}
					}
			 	   	break;

				// mostra todos os pokemons cadastrados
				case 6:
					if(pokedex.empty()){
						cout << "\nNENHUM POKEMON CADASTRADO!\n" << endl;
						break;
					}

					cout << "Lista de todos os Pokemons:" << endl;

					// Iterando sobre a lista
					for (ponteiroP = pokedex.begin(); ponteiroP != pokedex.end(); ++ponteiroP) {
						mostrarPokemon(*ponteiroP);
					}
					
					break;

				//caso entre com o valor 7 fechar o codigo
				case 7:
					return 0;
			}
		}while(op != 7);

	return 0;
}