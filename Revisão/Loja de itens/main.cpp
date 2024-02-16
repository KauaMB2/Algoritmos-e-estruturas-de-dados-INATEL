/*Poles está organizando os itens disponíveis para venda em sua loja online. Ele quer criar um
sistema de compra e venda de itens.
Para isso ele tem uma lista com diversos itens e suas informações (código, nome e preço). Ele
precisa cadastrar essa lista em uma tabela hash de tamanho M = 43 para facilitar as buscas. A
função hash usada para a inserção deve ser pelo método do módulo, considerando o código do
item e o valor M, com tratamento de colisão por sondagem linear.
Em seguida ele quer que, dada uma lista de itens sejam inseridos em uma fila de de vendas e uma
lista de itens sejam inseridos em uma pilha de compras.
Por fim, ele vai entrar com dois números inteiros V e C, indicando respectivamente a quantidade
de vendas e compras ele quer realizar. As vendas e compras devem ser processadas das
respectivas listas. Ele quer saber o lucro total das operações. Sabe-se que o lucro L é o valor total
VT das vendas realizadas subtraído do valor total VC das compras realizadas ( L = VT - VC )*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
struct Product{
    int code;
    int price;
    string name;

    Product():code(-1){}
};

//Define where de data will be storage using the modulo method
int hashFunction(int key, int size){
    return key % size;
}

//Apply a linear probing to collision resolution
int probe(int index, int size){
    return (index + 1) % size;
}

void insert(Product product, vector<Product>& table, int size){
    int key=product.code;
    int index=hashFunction(key, size);//Calculate the initial index

    //Apply the linear probing
    while(table[index].code != -1){//While the position isn't void...
        index=probe(index,size);//Calculate other index
    }

    table[index]=product;//Insert the key at the index position
}
void printTable(const vector<Product>& table) {
    cout << "Hash Table:" << endl;
    for (size_t i = 0; i < table.size(); i++) {
        if (table[i].code != -1) {
            cout << "Index " << i << ": " << table[i].price << endl;
        }
    }
}
int main(){
    const int M=43;//Inform the hash table size
    vector<Product> hashTable(M, Product());//Create a Hashtable filled with -1
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        Product product;
        cin >> product.code;
        cin >> product.name;
        cin >> product.price;
        insert(product, hashTable, M);
    }
    queue<int> vi;
    int v;
    while (cin >> v && v != -1) {
        vi.push(v);
    }
    stack<int> ci;
    int c;
    while (cin >> c && c != -1) {
        ci.push(c);
    }
    int V, C, VT=0, VC=0;
    cin >> V;
    cin >> C;
    while (!vi.empty() && V!=0) {
        int code = vi.front();
        vi.pop();
        V--;
        for (const Product& product : hashTable) {
            if (product.code == code) {
                VT = VT + product.price;
                break;
            }
        }
    }

    while (!ci.empty() && C!=0) {
        int code = ci.top();
        ci.pop();
        C--;
        for (const Product& product : hashTable) {
            if (product.code == code) {
                VC = VC + product.price;
                break;
            }
        }
    }
    int L = VT - VC;
    cout << L << " moedas(s)." << endl;
    return 0;
}