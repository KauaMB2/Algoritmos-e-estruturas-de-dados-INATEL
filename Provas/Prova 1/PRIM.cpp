#include <iostream>
#include <vector>
#include <climits>
#include <list>

using namespace std;

struct Node {
    int dest;
    int weight;
};

struct Upgrade{
	int dest;
	int custo;
};

struct Habilidade {
	string nome;
	int codigo;
	float poder; 
	list<Upgrade> upgrades;
};
pair<vector<int>, vector<int>> MST_PRIM(vector<vector<Upgrade>>& graph, int vertices, int start) {

    // Initialize arrays to keep track of visited vertices, distances, and parents
    vector<bool> intree(vertices, false); // Keep track of vertices included in MST
    vector<int> distance(vertices, INT_MAX); // Initialize distances with infinity
    vector<int> parent(vertices, -1); // Initialize parent array

    distance[start] = 0; // Set the distance of the starting vertex to 0
    int v = start; // Set the starting vertex

    while (!intree[v]) { // While there are vertices not included in the MST
        intree[v] = true; // Mark the current vertex as visited (included in MST)
        
        // Update distances to neighboring vertices and their parents
        for (const Upgrade& currentNode : graph[v]) { // Iterate over neighboring vertices of current vertex
            int dest = currentNode.dest; // Destination vertex of the edge
            int weight = currentNode.custo; // Weight of the edge
            if (!intree[dest] && distance[dest] > weight) {//If the destination vertex was not added in the MST and the its distance to the start vertex is biggest than the weight
                distance[dest] = weight; // Update distance to destination vertex
                parent[dest] = v; // Set parent of destination vertex to current vertex(It means the vertex "dest" has as parent the vertex "v")
            }
        }

        v = 0; // Reset v to 0 for finding the next vertex to add to MST
        int dist = INT_MAX; // Initialize minimum distance to infinity
        
        // Find the vertex with the minimum distance among unvisited vertices
        for (int u = 0; u < vertices; ++u) { // Iterate over all vertices
            if (!intree[u] && dist > distance[u]) { // If vertex u is not in MST and distance is smaller
                dist = distance[u]; // Update minimum distance
                v = u; // Update the next vertex to visit
            }
        }
    }
    return make_pair(parent, distance);
}

int main() {
    int num_habilidades;
	cin >> num_habilidades;
	
	Habilidade habilidades[num_habilidades];
	for(int i=0; i< num_habilidades; i++){
		habilidades[i].codigo = i;
		cin >> habilidades[i].nome;
		cin >> habilidades[i].poder;
	}
	
	int num_upgrades, origem, destino, custo;
	cin >> num_upgrades;
	vector<vector<Upgrade>> graph(num_upgrades);
	for(int j=0; j < num_upgrades; j++){
		cin >> origem;
		cin >> destino;
		cin >> custo;
		graph[origem].push_back({destino, custo});
	}
    pair<vector<int>, vector<int>> result=MST_PRIM(graph, num_habilidades, 0);
    vector<int> distance=result.second;//Get the weights7
    int totalDistance=0;
    for (int i = 1; i < num_habilidades; ++i) { // Skip the starting vertex (0)
        totalDistance+=distance[i];
    }
    cout << totalDistance;
    return 0;
}
