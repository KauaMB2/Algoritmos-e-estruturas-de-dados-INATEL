#include <iostream>
#include <limits> 
#include <string>
#include <vector>
using namespace std;

struct Stone {
  string name;
  float volume;
  int weight;
  int price;
};

vector<Stone> findBetterCombination(int W, float V, int n, vector<Stone> stones, vector<vector<vector<int>>> Table) {
  vector<Stone> betterCombination;
  while ((W > 0) && (n > 0) && (V > 0.0)) {
    if ((Table[n][W][int(V*10000)] - Table[n - 1][W][int(V*10000)]) != 0) {
      betterCombination.push_back(stones[n - 1]);
      W -= stones[n - 1].weight;
      V -= stones[n - 1].volume;
    }
    n--;
  }
  return betterCombination;
}
void printCombination(vector<Stone> betterCombination) {
  for (Stone stone : betterCombination) {
    cout << "=========================" << endl;
    cout << "Nome: " << stone.name << endl;
    cout << "Peso: " << stone.weight << endl;
    cout << "Volume: " << stone.volume << endl;
    cout << "Preco: " << stone.price << endl;
  }
}
int dynamicProgramming(int W, int V, vector<vector<vector<int>>> &Table, vector<Stone> &stones, int n) {
  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      for (int v = 0; v <= V; ++v) { 
        if (i == 0 || w == 0 || v == 0) {
          Table[i][w][v] = 0;
        } else if (stones[i - 1].weight <= w && stones[i - 1].volume * 10000 <= v) {
          Table[i][w][v] = max(stones[i - 1].price + Table[i - 1][w - stones[i - 1].weight][v - int(stones[i - 1].volume * 10000)], Table[i - 1][w][v]);
        } else {
          Table[i][w][v] = Table[i - 1][w][v];
        }
      }
    }
  }
  return Table[n][W][V];
}

int main() {
  vector<Stone> stones = {{"Diamond", 0.455, 263, 500},
                          {"Emerald", 0.521, 127, 410},
                          {"Topaz", 0.521, 127, 320},
                          {"Ruby", 0.065, 134, 315},
                          {"Jade", 0.012, 111, 280}};
  int n = stones.size();
  int W = 500;
  float V = 1.0;
  vector<vector<vector<int>>> Table(n + 1, vector<vector<int>>(W + 1, vector<int>(int(V * 10000) + 1, 0)));
  int betterValue = dynamicProgramming(W, int(V * 10000), Table, stones, n);
  cout << "Maximum value: " << betterValue << endl;
  vector<Stone> betterCombination=findBetterCombination(W, V, n, stones, Table);
  printCombination(betterCombination);
  return 0;
}
