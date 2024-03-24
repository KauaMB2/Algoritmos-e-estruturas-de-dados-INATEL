#include <iostream>
#include <vector>
using namespace std;
// ALGORITMO DE BUSCA EM LARGURA => (BFS - Breadth-First Search) é um algoritmo utilizado para percorrer ou explorar todos os vértices de um grafo de forma sistemática e ordenada.
// O algoritmo começa selecionando um vértice inicial (no caso do código fornecido, o vértice 0 é escolhido arbitrariamente).

// Ele realiza uma busca em largura a partir deste vértice, visitando todos os vértices alcançáveis a partir dele e marcando-os como visitados.

// Durante a busca, ele adiciona os vértices não visitados à fila para serem visitados posteriormente e os marca como visitados.

// Após a busca, o algoritmo verifica se o número total de vértices visitados é igual ao número total de vértices no grafo. Se forem iguais, isso significa que todos os vértices foram alcançados durante a busca, e o grafo é considerado conexo. Caso contrário, o grafo não é conexo.


struct Node{
    int v; // vertice adjacente
    int weight; // peso da aresta
};

void add_edge(Node& graph, int v1, int weight, int v2, int directed) {//Create a connection between two vertices
    if(directed==1){
        graph.v=v2;
        graph.weight=weight;
    }else{
        
    }
    cout << "Edge added between " << v1 << " and " << v2 << " with wight equal to: " << weight << endl; // Debugging output
}


int main() {
    Node g;
    int num_vertices, directed;//Number of vertices
    cin >> num_vertices >> directed;//Read the total number of vertices
    vector<Node> Graph(num_vertices);
    for(Node node : Graph){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;//Read the number that represent the vertices
        if((v1==-1)&&(v2==-1)&&(weight==-1)){
            break;//Leave the loop
        }
        add_edge(node,  v1, weight, v2, directed);
    }

    return 0;
}
