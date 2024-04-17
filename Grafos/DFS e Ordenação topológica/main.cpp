#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int vertex;
};
//Uma ordenação topológica de um grafo direcionado acíclico (DAG) é uma ordem linear de seus nós em que cada nó vem antes de todos nós para os quais este tenha arestas de saída. Cada DAG tem uma ou mais ordenações topológicas.
//Uma ordenação topológica é uma ordem linear de vértices em um grafo direcionado acíclico (DAG) na qual cada vértice aparece antes de todos os vértices para os quais ele tem uma aresta de saída. Em outras palavras, é uma ordenação dos vértices de forma que se houver uma aresta direcionada do vértice u para o vértice v, então u aparece antes de v na ordenação.
void dfs(list<Node> adj[], int u, vector<bool>& visited, stack<int>& stk) { //Function to apply the DFS
    visited[u] = true;//Define the current vertex as visited
    for (const auto& node : adj[u]) {//For each neighbor node of the "u" node
        if (!visited[node.vertex]) {//If the current neighbor wasn't visited...
            dfs(adj, node.vertex, visited, stk);//Apply a DFS in the 
        }
    }
    stk.push(u);//Add the vertex u in the stack
}

void ordenacao_topologica(list<Node> adj[], int nVertices) {//Function to show the topologic ordenation of the graph
    vector<bool> visited(nVertices, false);//Function to storage which vertex where visited
    stack<int> stk;//Stack to storage the vertices in the topologic order

    for (int i = 0; i < nVertices; i++) {//For each vertex in the graph
        if (!visited[i]) {//If the current vertex were not visited
            dfs(adj, i, visited, stk);//Apply the DFS in the current vertex
        }
    }

    while (!stk.empty()) {//Show the topologic order
        cout << stk.top() << " ";//Show the element in the top of the stack
        stk.pop();//Take out this element
    }
    cout << endl;
}

int main() {
    int nVertices, orientado;
    cin >> nVertices >> orientado;

    list<Node> adj[nVertices];

    int origem, destino;
    cin >> origem >> destino;
    while (origem != -1 && destino != -1) {
        adj[origem].push_back({destino});
        if(orientado==0){
            adj[destino].push_back({origem});
        }
        cin >> origem >> destino;
    }

    ordenacao_topologica(adj, nVertices);

    return 0;
}
