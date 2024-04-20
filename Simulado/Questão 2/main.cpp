#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

void DFS_VISIT(vector<vector<Edge>>& adj, int u, vector<char>& color, vector<int>& f, int& time) {
    color[u] = 'G'; // Marca o vértice como visitado (cinza)
    time++;
    for (const auto& edge : adj[u]) {
        int v = edge.destination;
        if (color[v] == 'W') {
            DFS_VISIT(adj, v, color, f, time);
        }
    }
    color[u] = 'B'; // Marca o vértice como finalizado (preto)
    f[u] = time++;
}

void DFS(vector<vector<Edge>>& adj, vector<char>& color, vector<int>& f) {
    int nVertices = adj.size();
    int time = 0;
    for (int u = 0; u < nVertices; ++u) {
        if (color[u] == 'W') {
            DFS_VISIT(adj, u, color, f, time);
        }
    }
}

void topologicalSort(vector<vector<Edge>>& adj) {
    int nVertices = adj.size();//Get the size of the graph
    vector<char> color(nVertices, 'W'); // Define the color white for non-visited vertices
    vector<int> f(nVertices, 0); // Define a function to storage the time of each vertex
    DFS(adj, color, f);//Apply DFS

    // Ordenando os vértices em ordem decrescente de f
    vector<pair<int, int>> vertices_f;//Define a vector to storage the ordered vertices
    for (int i = 0; i < nVertices; ++i) {//For each vertex in the graph...
        vertices_f.push_back({f[i], i});//Add the vertex in the ordered vector
    }
    sort(vertices_f.rbegin(), vertices_f.rend());//Organize the vertice in the ascending order

    // Exibindo os vértices na ordem correta
    cout << "f={";
    for (int i = 0; i < nVertices; ++i) {
        cout << vertices_f[i].first;
        if (i < nVertices - 1) {
            cout << ",";
        }
    }
    cout << "} ord=";
    for (int i = 0; i < nVertices; ++i) {
        cout << "v" << vertices_f[i].second + 1;
        if (i < nVertices - 1) {
            cout << "-";
        }
    }
    cout << endl;
}

int main() {
    int nVertices = 6; // Defina o número total de vértices
    vector<vector<Edge>> graph(nVertices);

    // Preencha o grafo com as arestas
    graph[0].push_back({1, 1});
    graph[0].push_back({3, 1});
    graph[2].push_back({3, 1});
    graph[3].push_back({4, 1});
    graph[3].push_back({5, 1});
    graph[5].push_back({4, 1});
    graph[3].push_back({1, 1});
    graph[4].push_back({1, 1});
    graph[0].push_back({2, 1});

    topologicalSort(graph);
    return 0;
}
