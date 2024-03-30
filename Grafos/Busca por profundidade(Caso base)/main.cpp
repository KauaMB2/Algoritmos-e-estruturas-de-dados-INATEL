#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Depth-First Search (DFS) function
void DFS(const vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
    stack<int> stack;//Create the stack to storage the vertex
    stack.push(startVertex);//storage the first vertex

    while (!stack.empty()) {//while the stack is no t empty
        int currentVertex = stack.top();//get the top elmento in the stack
        stack.pop();//Take out the top element of the stack

        // If the vertex is not visited, mark it as visited and process it
        if (!visited[currentVertex]) {//If the current vertex was not visited...
            visited[currentVertex] = true;//Set the current vertex as visited

            //Print the current vertex
            cout << "Current vertex: " << currentVertex << endl;

            // Push unvisited neighbors onto the stack
            for (int neighbor : graph[currentVertex]) {//Pass through all the neighbor vertex of the current vertex
                if (!visited[neighbor]) {//If the neighbor vertex of the current vertex was not visited before
                    stack.push(neighbor);//Put the neighbor vertex in the stack
                }
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Neighbors of vertex 0
        {0, 3, 4},  // Neighbors of vertex 1
        {0, 4},     // Neighbors of vertex 2
        {1},        // Neighbors of vertex 3
        {1, 2}      // Neighbors of vertex 4
    };

    // Number of vertices in the graph
    int numVertices = graph.size();

    // Vector to track visited vertices
    vector<bool> visited(numVertices, false);

    // Start DFS from each vertex (in case the graph is not connected)
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

    return 0;
}
