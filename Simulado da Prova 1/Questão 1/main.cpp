#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

#define INF INT_MAX

// Estrutura para representar uma aresta
struct Edge {
    int destination;
    int weight;
};

// Função para implementar o algoritmo de Dijkstra
void dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    int V = graph.size(); // Número de vértices

    // Vetor de distâncias mínimas
    vector<int> dist(V, INF);
    dist[start] = 0;

    // Vetor de predecessores para reconstruir o caminho mínimo
    vector<int> pred(V, -1);

    // Fila de prioridade para selecionar o vértice com a menor distância
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Se alcançamos o vértice de destino, podemos parar
        if (u == end) break;

        // Percorre todos os vértices adjacentes de u
        for (auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // Se a distância atual é maior que a nova distância encontrada
            if (dist[v] > dist[u] + weight) {
                // Atualiza a distância mínima e o predecessor
                dist[v] = dist[u] + weight;
                pred[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Imprime o caminho mínimo
    cout << "Caminho mínimo de " << start << " até " << end << ":\n";
    if (pred[end] == -1) {
        cout << "Não há caminho\n";
        return;
    }

    stack<int> path;
    int current = end;
    while (current != -1) {
        path.push(current);
        current = pred[current];
    }

    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << "\n";

    // Imprime a distância mínima até o vértice de destino
    cout << "Distância mínima de " << start << " até " << end << ": ";
    if (dist[end] != INF)
        cout << dist[end] << "\n";
    else
        cout << "Não há caminho\n";
}

int main() {
    // Definição do grafo
    int V = 7; // Número de vértices
    vector<vector<Edge>> graph(V);

    // Adicionando arestas ao grafo
    graph[1].push_back({2, 1});
    graph[2].push_back({3, 5});
    graph[2].push_back({6, 13});
    graph[2].push_back({5, 3});
    graph[2].push_back({4, 2});
    graph[3].push_back({6, 3});
    graph[4].push_back({1, 4});
    graph[4].push_back({5, 3});
    graph[5].push_back({3, 1});
    graph[5].push_back({6, 4});

    // Entrada do usuário para o vértice de origem e destino
    int start=1, end=6;

    // Verifica se as entradas do usuário são válidas
    if (start < 1 || start >= V || end < 1 || end >= V) {
        cout << "Entrada inválida!\n";
        return 1;
    }

    // Executa o algoritmo de Dijkstra
    dijkstra(graph, start, end);

    return 0;
}
