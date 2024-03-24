#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node {
    int vertex;
    bool visited;
};

void bfs(list<Node> adj[], int nVertices, int s) {
    // Inicializar todos os vértices como não visitados
    for (int i = 0; i < nVertices; ++i) {
        for (auto& node : adj[i]) {
            node.visited = false;
        }
    }

    // Marcar o vértice de origem como visitado e adicioná-lo à fila
    adj[s].front().visited = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        // Obter o vértice da frente da fila
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        // Percorrer todos os vértices adjacentes ao vértice atual
        for (auto& node : adj[currentVertex]) {
            if (!node.visited) {
                // Marcar o vértice como visitado e adicioná-lo à fila
                node.visited = true;
                q.push(node.vertex);
            }
        }
    }
}

int main() {
    // Exemplo de utilização
    const int nVertices = 5;
    list<Node> adj[nVertices];

    // Adicionando arestas ao grafo
    adj[0].push_back({1, false});
    adj[0].push_back({2, false});
    adj[1].push_back({2, false});
    adj[1].push_back({3, false});
    adj[2].push_back({0, false});
    adj[2].push_back({1, false});
    adj[3].push_back({3, false});
    adj[4].push_back({4, false});

    cout << "BFS comecando do vertice 2: ";
    bfs(adj, nVertices, 2);

    return 0;
}
