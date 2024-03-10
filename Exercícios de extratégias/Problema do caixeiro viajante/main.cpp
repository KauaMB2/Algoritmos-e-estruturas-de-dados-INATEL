#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void printPermitation(const vector<int>& permutation, const vector<vector<int>>& distances, int i){
    cout << "Interation: " << i << endl;
    cout << "permutation[i]: " << permutation[i] << endl;
    cout << "permutation[i + 1]: " << permutation[i + 1] << endl;
    cout << "distances[permutation[i]][permutation[i + 1]]: " << distances[permutation[i]][permutation[i + 1]] << endl << endl;
}
void printCurrentPermutation(const vector <int> permutation, int n){
    cout << "Current Permutation: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}
// Função para calcular o custo total de uma permutação das cidades
int calculateCost(const vector<int>& permutation, const vector<vector<int>>& distances) {
    int cost = 0;
    int n = permutation.size();
    //printCurrentPermutation(permutation, n);
    for (int i = 0; i < n - 1; ++i) {
        //Get the distance of the current city to the next and sum it in the cost variable
        cost += distances[permutation[i]][permutation[i + 1]];
        printPermitation(permutation, distances, i);
    }
    // Add the distance to come back to the initial city
    cost += distances[permutation[n - 1]][permutation[0]];
    cout << "currentCost: " << cost << endl << endl;
    return cost;
}

int main() {
    // Defining the distances between the cities
    // É UMA MATRIZ ESPELHADA!!
    /*
    {A-A, A-B, A-C, A-D},
    {B-A, B-B, B-C, B-D},
    {C-A, C-B, C-C, C-D},
    {D-A, D-B, D-C, D-D}
    */
    vector<vector<int>> distances = {
        {0, 2, 8, 5},
        {2, 0, 3, 4},
        {8, 3, 0, 7},
        {5, 4, 7, 0}
    };
    // Number of cities
    int n = distances.size();
    // Initialize the permutation of the cities(0 represents the city A)
    vector<int> permutation(n);
    vector<int> betterWay(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }
    // Initialyze the shortest cost with a big value
    int min_cost = INT_MAX;
    // Initializa the permutation with the number of options
    int num_options = 0;
    // Get all the permutations possible
    do {
        // Calculate the the cost of the current permutation
        int cost = calculateCost(permutation, distances);
        // Update the shortest value
        if(cost<min_cost){
            min_cost=cost;
            betterWay=permutation;
        }
        // Increment the number of options
        num_options++;
    } while (next_permutation(permutation.begin() + 1, permutation.end()));//Update lexicographically to the next permutation possible in ascending order returns false when it already passed through all the combinations possible in the array and true while it doesn't
    // Show the shortest cost and the number of options
    cout << "Menor custo: " << min_cost << " km" << endl;
    cout << "Numero de opcoes: " << num_options << endl;
    // Show the order of the cities
    cout << "Ordem de visita das cidades: ";
    for (int city : betterWay) {
        cout << (char)('A' + city) << " ";
    }
    cout << "A" << endl; // Add the initial city in the beggining
    return 0;
}
