#include <iostream>
#include <list>
#include <queue>
#include <climits>

using namespace std;

// Estrutura para representar uma aresta
struct Edge {
    int dest;
    int weight;
};
void debug(vector<bool> intree, vector<int> distance, vector<int> parent, int numVertices, int v){
    cout << "Current vertex \"v\": " << v << endl;
    cout << "Intree: " << endl;
    for(int i=0;i<numVertices;i++){
       cout << intree[i] << " "; 
    }
    cout << endl;
    cout << "Distance: " << endl;
    for(int i=0;i<numVertices;i++){
       cout << distance[i] << " "; 
    }
    cout << endl;
    cout << "Parent: " << endl;
    for(int i=0;i<numVertices;i++){
       cout << parent[i] << " "; 
    }
    cout << endl << endl;
}

void shortestPathDijkstra(list<Edge>* adj, int numVertices, int start, int end) {
    vector<bool> intree(numVertices, false);//Vector to storage of the vertex is on tree or not
    vector<int> distance(numVertices, INT_MAX);//Vector to storage the distance between the start vertex and the other vertex
    vector<int> parent(numVertices, -1);//Vector to storage the parent of the destiny vertex
    
    distance[start] = 0;//Define the distance of the start element to itself
    int v = start;//Define the start vertex
    
    while (!intree[v]) {
        intree[v] = true;//Define the current vertex as true
        for (const Edge& edge : adj[v]) {//For each vertex connected to the vertex current "v"
            int dest = edge.dest;//Get the destiny vertex of the current vertex
            int weight = edge.weight;//Get the weight of the current vertex
            if (distance[dest] > distance[v] + weight) {//If the destiny between the current element and its destiny vertex is biggest than the distance between the current vertex to itself s+ the weight... 
                distance[dest] = distance[v] + weight;//Define the new distance as the shortest
                parent[dest] = v;//Define the father of the destiny vertex as beeing v
            }
        }
        debug(intree, distance, parent, numVertices, v);
        v = 0;//Define v as beeing 0
        int dist = INT_MAX;//Define a max integer
        for (int u = 0; u < numVertices; u++) {//for each vertex in the graph
            if (!intree[u] && dist > distance[u]) {//If the vertex is not on the tree and the shortest distance is biggest than the current distance
                dist = distance[u];//Define the new shortest distance
                v = u;//define the new "v"
            }
        }
    }

    // OUTPUT OF THE SHORTEST PATH
    cout << "Caminho mais curto de " << start << " para " << end << ": ";
    int current = end;
    vector<int> path;//Vector to storage the shortest distance
    while (current != -1) {//while the current vertex doesn't have a father
        path.push_back(current);//Add the current element in the path vector
        current = parent[current];//Define the current vertex as beeing the father of the current vertex
    }
    for (int i = path.size() - 1; i >= 0; i--) {//Pass in each element in the path
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << "\nDistância: " << distance[end] << endl;

}

int main() {
    int numVertices = 5;
    list<Edge>* adj = new list<Edge>[numVertices];

    // Exemplo de grafo direcionado ponderado usando listas de adjacências
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 5});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 9});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 4});
    adj[4].push_back({3, 6});

    int start = 0;
    int end = 4;
    shortestPathDijkstra(adj, numVertices, start, end);

    // Liberando memória alocada dinamicamente
    delete[] adj;

    return 0;
}
