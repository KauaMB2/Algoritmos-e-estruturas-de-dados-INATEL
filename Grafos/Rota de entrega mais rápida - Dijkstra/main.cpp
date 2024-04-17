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
    // Show the minimun distance between the vertices
    if (distance[end] != INF){
        cout << "\n" << distance[end] << "\n";
    }
    else{
        cout << "Não ha caminho\n";
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> graph(N);
    for(int i=0;i<M;i++){
        int u, v, t;
        cin >> u >> v >> t;
        graph[u-1].push_back({v-1, t});
    }
    int A, B;
    cin >> A >> B;
    pair<vector<int>, vector<int>> result = dijkstra(graph, A-1, B-1);
    vector<int> distance=result.second;
    
    cout << distance[B-1] << endl;
    
    return 0;
}