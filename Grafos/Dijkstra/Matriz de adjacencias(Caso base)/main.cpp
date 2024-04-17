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
pair<vector<int>, vector<int>> dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    int V = graph.size(); // Get the number of vertices
    vector<int> distance(V, INF);// Vector of minimun distances
    distance[start] = 0;//Define the distance to the start vertice to itself as 0
    vector<int> parent(V, -1);//Parent vector
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//Create the priority queue
    pq.push({0, start});//Add the first element in the queue and define the weight to itselft as beeing 0
    
    while (!pq.empty()) {//While the queue is not empty
        int u = pq.top().second;//Get the value of the current vertex
        pq.pop();//Delete the current vertex of the queue

        if (u == end){// If the destiny vertex was found...
            break;//Stop the loop
        }
        for (auto& edge : graph[u]) {//For each edge of the current vertex
            int v = edge.destination;//Get the destiny vertex
            int weight = edge.weight;//Get the weight

            if (distance[v] > distance[u] + weight) {//If the destiny between the current element and its destiny vertex is biggest than the distance between the current vertex to itself s+ the weight...
                distance[v] = distance[u] + weight;//Define the new distance as the shortest
                parent[v] = u;//Define the parent of the "v" vertex as beeing "u"
                pq.push({distance[v], v});//Add the v vertex in the queue
            }
        }
    }
    return make_pair(parent, distance);
}
void printResult(vector<int> parent, vector<int> distance, int start, int end){
    cout << "Caminho minimo de " << start << " ate " << end << ":\n";
    if (parent[end] == -1) {
        cout << "Não ha caminho\n";
        return;
    }
    stack<int> path;
    int current = end;
    while (current != -1) {
        path.push(current);
        current = parent[current];
    }
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()){
            cout << " -> ";
        }
    }
    cout << "\n";


    // Show the minimun distance between the vertices
    cout << "Distancia minima de " << start << " ate " << end << ":\n";
    if (distance[end] != INF){
        int size=distance.size();
        for(int i=1;i<size;i++){
            cout << distance[i];
            if(i!=size-1){
                cout << " -> ";
            }
        }
        cout << "\n" << distance[end] << "\n";
    }
    else{
        cout << "Não ha caminho\n";
    }
}
int main() {
    int V = 7; // Number of vertices
    vector<vector<Edge>> graph(V);//Create graph

    // Add the edges
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

    int start=1, end=6;//vertex of the start and the end

    pair<vector<int>, vector<int>> result = dijkstra(graph, start, end);//Apply the Dijkstra algorithm
    vector<int> parent=result.first, distance=result.second;
    printResult(parent, distance, start, end);
    return 0;
}
