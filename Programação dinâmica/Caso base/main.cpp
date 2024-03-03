#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Object {
  string name;
  int weight;
  int value;
};
vector<Object> findBetterCombination(int W, int n, vector<Object> objects, vector<vector<int>> Table) {
  vector<Object> betterCombination;
  while ((W > 0) && (n > 0)) {
    if ((Table[n][W] - Table[n - 1][W]) != 0) {
      betterCombination.push_back(objects[n - 1]);
      W -= objects[n - 1].weight;
    }
    n--;
  }
  return betterCombination;
}
void printCombination(vector<Object> betterCombination) {
  for (Object object : betterCombination) {
    cout << "=========================" << endl;
    cout << "Nome: " << object.name << endl;
    cout << "Valor: " << object.value << endl;
    cout << "Peso: " << object.weight << endl;
  }
}
void printTable(int W, int n, vector<vector<int>> Table) {
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      cout << Table[i][w] << " ";
    }
    cout << endl;
  }
  cout << endl << "=========================" << endl << endl;
}
// Função para calcular o valor máximo que pode ser obtido
// com capacidade máxima W e com os itens dados
int dynamicProgramming(int W, vector<vector<int>> &Table, vector<Object> objects, int n) {
  // Construção da tabela K[][] de baixo para cima
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        Table[i][w] = 0;
      } else if (objects[i - 1].weight <= w) {
        Table[i][w] =
            max(objects[i - 1].value + Table[i - 1][w - objects[i - 1].weight],
                Table[i - 1][w]);
        printTable(W, n, Table);
      } else {
        Table[i][w] = Table[i - 1][w];
        printTable(W, n, Table);
      }
    }
  }
  return Table[n][W];
}
int main() {
  vector<Object> objects = {
      {"Faca", 1, 1}, {"Radio", 3, 5}, {"TV", 5, 8}, {"Playstation", 8, 10}};
  int W = 11; // Capacidade máxima da mochila
  int n = objects.size();
  vector<vector<int>> Table(n + 1, vector<int>(W + 1, 0));
  int betterValue = dynamicProgramming(W, Table, objects, n);
  cout << "Valor maximo obtido: " << betterValue << endl;
  vector<Object> betterCombination =
      findBetterCombination(W, n, objects, Table);
  printCombination(betterCombination);
  return 0;
}
