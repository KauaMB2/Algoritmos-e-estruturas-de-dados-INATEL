#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<list<int>> graph(N + 1);

    // Construindo o graph
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);  // Ajuste aqui, inserir também para o outro vértice
    }

    // Imprimindo as conexões
    for (int i = 1; i <= N; ++i) {
        graph[i].sort(); // Sort the integer elements of the list in the the ascending order
        cout << graph[i].size() << " ";//Show the amount fo cities connected to the current city
        for (int neighbor : graph[i]) {//Get the number of the city
            cout << neighbor << " ";//Show the current neighbor
        }
        cout << endl;
    }
    return 0;
}
