#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Node{
    int dest;
    int weight;
};

pair<vector<int>, vector<int>> MST_PRIM(vector<vector<Node>>& graph, int start) {
    int numVertices = graph.size(); // Get the number of vertices in the graph

    // Initialize arrays to keep track of visited vertices, distances, and parents
    vector<bool> intree(numVertices, false); // Keep track of vertices included in MST
    vector<int> distance(numVertices, INT_MAX); // Initialize distances with infinity
    vector<int> parent(numVertices, -1); // Initialize parent array

    distance[start] = 0; // Set the distance of the starting vertex to 0
    int v = start; // Set the starting vertex

    while (!intree[v]) { // While there are vertices not included in the MST
        intree[v] = true; // Mark the current vertex as visited (included in MST)
        
        // Update distances to neighboring vertices and their parents
        for (const Node& currentNode : graph[v]) { // Iterate over neighboring vertices of current vertex
            int dest = currentNode.dest; // Destination vertex of the edge
            int weight = currentNode.weight; // Weight of the edge
            if (!intree[dest] && distance[dest] > weight) {//If the destination vertex was not added in the MST and the its distance to the start vertex is biggest than the weight
                distance[dest] = weight; // Update distance to destination vertex
                parent[dest] = v; // Set parent of destination vertex to current vertex(It means the vertex "dest" has as parent the vertex "v")
            }
        }

        v = 0; // Reset v to 0 for finding the next vertex to add to MST
        int dist = INT_MAX; // Initialize minimum distance to infinity
        
        // Find the vertex with the minimum distance among unvisited vertices
        for (int u = 0; u < numVertices; ++u) { // Iterate over all vertices
            if (!intree[u] && dist > distance[u]) { // If vertex u is not in MST and distance is smaller
                dist = distance[u]; // Update minimum distance
                v = u; // Update the next vertex to visit
            }
        }
    }
    return make_pair(parent, distance);
}

int main(){
    int N, oriented, start;// number of vertex, oriented or not and the starting vertex
    cin >> N >> oriented >> start;
    vector<vector<Node>> graph(N);//Create the graph
    while(true){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if(v1==-1&&v2==-1&&w==-1){
            break;
        }
        graph[v1].push_back({v2, w});
        if(oriented==0){
            graph[v2].push_back({v1, w});
        }
    }
    // Starting vertex for Prim's algorithm
    pair<vector<int>, vector<int>> result = MST_PRIM(graph, start);
    vector<int> parent=result.first;//Get the MST vector parent vector
    vector<int> distance=result.second;//Get the weights
    // Print the edges of the Minimum Spanning Tree (MST)
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 1; i < graph.size(); i++) { // Skip the starting vertex (0)
        cout << parent[i] << " " << i << endl;
    }
    int totalCost=0;
    for(int i=0;i<graph.size();i++){
        totalCost+=distance[i];
    }
    cout << "Custo: " << totalCost;
    
    return 0;
}