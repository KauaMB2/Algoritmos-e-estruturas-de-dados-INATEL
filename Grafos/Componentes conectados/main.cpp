#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// ALGORITMO DE BUSCA EM LARGURA => (BFS - Breadth-First Search) é um algoritmo utilizado para percorrer ou explorar todos os vértices de um grafo de forma sistemática e ordenada.
// O algoritmo começa selecionando um vértice inicial (no caso do código fornecido, o vértice 0 é escolhido arbitrariamente).

// Ele realiza uma busca em largura a partir deste vértice, visitando todos os vértices alcançáveis a partir dele e marcando-os como visitados.

// Durante a busca, ele adiciona os vértices não visitados à fila para serem visitados posteriormente e os marca como visitados.

// Após a busca, o algoritmo verifica se o número total de vértices visitados é igual ao número total de vértices no grafo. Se forem iguais, isso significa que todos os vértices foram alcançados durante a busca, e o grafo é considerado conexo. Caso contrário, o grafo não é conexo.


struct Graph {
    vector<vector<int>> adj_list;
};

void add_edge(Graph& graph, int u, int v) {//Create a connection between two vertices
    graph.adj_list[u].push_back(v);//Add the vertex v in the list of adjacent vertices of the vertex u
    graph.adj_list[v].push_back(u);//Add the vertex u in the list of adjacent vertices of the vertex v
    cout << "Edge added between " << u << " and " << v << endl; // Debugging output
}

unordered_set<int> BreadthFirstSearch(const Graph& graph, int start) {
    unordered_set<int> visited;//Creates a hash table to storage the visited elements
    queue<int> q;//Create a queue to storage the neightbors during the verification
    q.push(start);//Put the start element in the queue
    visited.insert(start);//Insert the start element in the hash table. "start" is the key and the value at the same time

    while (!q.empty()) {//When "q" be not empty...
        int vertex = q.front();//Get the element in the front of the queue
        q.pop();//Take out the front element
        for (int neighbor : graph.adj_list[vertex]) {//Pass for each neighbor of the current vertex
            if (visited.find(neighbor) == visited.end()) {//If the element was not found... If the current neighbor in the interation never was visited before, it add it in the queue to be visited | visited.find(neighbor) => Try find an elemnt with this key
                q.push(neighbor);//Add in the queue to be visited after
                visited.insert(neighbor);//Add in the hash table to be counted after
                cout << "Visited vertex: " << neighbor << endl;
            }
        }
    }

    return visited;
}

bool is_connected(const Graph& graph, int start) {
    if (graph.adj_list.empty()){//If there aren't elements in the list...
        return false;
    }

    unordered_set<int> visited = BreadthFirstSearch(graph, start);//Verify if the elements are connected between them
    return visited.size() == graph.adj_list.size();//Verify if the algorithm passed through all the vertices
}

int main() {
    Graph g;
    int num_vertices, start;//Number of vertices
    cin >> num_vertices >> start;//Read the total number of vertices
    g.adj_list.resize(num_vertices);//Number of vertices of the graph
    while(true){
        int v1, v2;
        cin >> v1 >> v2;//Read the number that represent the vertices
        if((v1==-1)&&(v2==-1)){
            break;//Leave the loop
        }
        add_edge(g,  v1, v2);
    }

    if (is_connected(g, start)) {
        cout << "Conexo." << endl;
    } else {
        cout << "Nao conexo." << endl;
    }

    return 0;
}
