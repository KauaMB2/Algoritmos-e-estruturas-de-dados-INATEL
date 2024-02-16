/*Considere a inserção de elementos em uma pilha e quando um elemento for removido ele deve ser
inserido em uma tabela hash de comprimento M usando endereçamento aberto. Mostre o resultado da
inserção dessas chaves utilizando hash duplo com h1(k) = k mod m e h2(k) = 1 + (k mod (m − 1)).*/
#include <iostream>
#include <vector>

using namespace std;

// Função de hash primária h1(k) = k mod m
int hash1(int key, int M) {
    return key % M;
}

// Função de hash secundária h2(k) = 1 + (k mod (m - 1))
int hash2(int key, int M) {
    return 1 + (key % (M - 1));
}

// Função para inserir uma chave na tabela hash usando endereçamento aberto e hashing duplo
void insertInHashTable(vector<int>& hashTable, int key, int M) {
    int index = hash1(key, M); // Calcular o índice inicial

    // Se a posição estiver ocupada, calcular o próximo índice usando h2(k) até encontrar uma posição vazia
    while (hashTable[index] != -1) {
        index = (index + hash2(key, M)) % M;
    }

    hashTable[index] = key; // Inserir a chave na posição index
}

// Função para imprimir a tabela hash
void printHashTable(const vector<int>& hashTable) {
    int size=hashTable.size()-1;
    for(int i=0;i<size;i++){
        cout << hashTable[i] << " ";
    }
    cout << endl;
}

int main() {
    int M;
    cin >> M;
    vector<int> hashTable(M, -1); // Inicializar a tabela hash com -1 (indicando posição vazia)
    int amount;
    cin >> amount;
    // Chaves a serem inseridas na tabela hash
    vector<int> keys;
    for(int i=0;i<amount;i++){
        int k;
        cin >> k;
        insertInHashTable(hashTable, k, M);
    }
    printHashTable(hashTable);

    return 0;
}
