#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Node{
    int vertex;
    int weight;
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<list<Node>> graph(N);
    while(true){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if(v1==-1 && v2==-1 && w==-1){
            break;
        }
        graph[v1].push_back({v2, w});
        if(M==0){
            graph[v2].push_back({v1, w});
        }
    }
    for(int i=0;i<N;i++){
        for (Node neighbor : graph[i]) {//Get the number of the city
            cout << i << " " << neighbor.vertex << " " << neighbor.weight << endl;//Show the current neighbor
        }
    }
    
    return 0;
}