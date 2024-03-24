#include <iostream>
#include <vector>

using namespace std;

// Função para adicionar conexão entre vértices v1 e v2 na matriz de adjacência
void addAdj(vector<vector<int>>& graph, int v1, int v2) {
    graph[v1 - 1][v2 - 1] = 1; // Marca a conexão de v1 para v2
    graph[v2 - 1][v1 - 1] = 1; // Marca a conexão de v2 para v1
}

int main() {
    int N, M;
    cin >> N >> M;

    // Inicializa a matriz de adjacência com zeros
    vector<vector<int>> graph(N, vector<int>(N, 0));

    // Lê os M caminhos e adiciona as conexões na matriz de adjacência
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        addAdj(graph, v1, v2);
    }

    // Imprime a matriz de adjacência
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
