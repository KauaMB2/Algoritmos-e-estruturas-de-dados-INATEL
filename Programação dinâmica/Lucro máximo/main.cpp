#include <iostream>
#include <vector>
using namespace std;

struct StockTrade {
    int purchase;
    int sale;
};

// Function to print the cost matrix
void printCostMatrix(const vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();

    cout << "        ";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "         ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "      ";
        for (int j = 0; j < n; ++j) {
            cout << costMatrix[i][j] << "      ";
        }
        cout << endl;
    }
}

// Function to calculate the cost matrix
vector<vector<int>> calculateCostMatrix(const vector<StockTrade>& trades) {
    int n = trades.size();
    vector<vector<int>> costMatrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        costMatrix[i][i] = trades[i].sale - trades[i].purchase;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if((j!=i)&&(j>i)){
                costMatrix[i][j]=costMatrix[i][j-1]+costMatrix[i+(j-i)][j];
            }
        }
    }

    return costMatrix;
}

int main() {
    vector<StockTrade> trades = {
        {2000, 1000},
        {2570, 2120},
        {3320, 4425},
        {1250, 6200},
        {3620, 3260},
        {2100, 2800},
        {1685, 2880}
    };

    vector<vector<int>> costMatrix = calculateCostMatrix(trades);

    cout << "Matriz de Custos:" << endl;
    printCostMatrix(costMatrix);

    return 0;
}
