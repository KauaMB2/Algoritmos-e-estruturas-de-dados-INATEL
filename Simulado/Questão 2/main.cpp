#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

#define INF INT_MAX

struct Edge {
    int destination;
    int weight;
};

int dijkstra(vector<vector<Edge>>& graph, int start, int end) {
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
            return distance[u];
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
    return INF;
}

int main(){
    vector<vector<Edge>> graph(7);
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 1});
    graph[3].push_back({4, 1});
    graph[4].push_back({5, 1});
    graph[4].push_back({6, 1});
    graph[6].push_back({5, 1});
    graph[4].push_back({2, 1});
    graph[5].push_back({2, 1});
    graph[1].push_back({3, 1});

    int S, D;
    cin >> S >> D;
    int result = dijkstra(graph, S - 1, D - 1);
    if (result != INF) {
        cout << result + 1 << endl;
    } else {
        cout << "IMPOSSIVEL" << endl;
    }
    return 0;
}