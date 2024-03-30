#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> DFS(const vector<vector<int>> graph, int start, vector<bool> visited){
    stack<int> st;
    st.push(start);
    visited[start]=true;
    
    while(!st.empty()){
        int current = st.top();//Get the top element of the stack
        st.pop();//Take out the top element of the stack

        for (int neighbor : graph[current]) {//Pass through all the neighbors of the current city
            if (!visited[neighbor]) {//If the current neighbor city was not visited before
                visited[neighbor] = true;//Set as visited
                st.push(neighbor);//Add in the stack
            }
        }
    }
    return visited;
}

int main(){
    int N, M;//Number of nodes and edges
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    for(int i=0;i<M;i++){
        int A, B;//Cities A and B
        cin >> A >> B;
        graph[A].push_back(B);//Add the connection between A and B
        graph[B].push_back(A);//Add the connection between B and A
    }
    int X, Y;
    cin >> X >> Y;
    
    //Disconnect the city X to the Y city
    for(vector<int>::iterator it=graph[X].begin();it != graph[X].end();it++){
        if(*it==Y){//If the current city is equal to the city Y
            graph[X].erase(it);//Delete the connection between X and Y
            break;//Break the loop because we already removed the connection between them
        }
    }
    vector<bool> visited(N+1, false);//Create the visited array
    visited=DFS(graph, X, visited);//Call the function
    for(int i=1;i<=N;i++){//Pass through all the elements of the visisted array
        if(!visited[i]){//if the city wasn't visited...
            cout << i << " ";//print the city
        }
    }
    return 0;
}