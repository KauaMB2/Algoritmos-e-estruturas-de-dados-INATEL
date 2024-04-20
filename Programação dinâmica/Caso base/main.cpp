#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Object {
    string name;
    int weight;
    int value;
};

vector<Object> findBetterCombination(int W, int n, vector<Object> objects, vector<vector<int>> Table) {
    vector<Object> betterCombination;
    while ((W > 0) && (n > 0)) {//while we don't reset the W and the number 'n' of elements to 0... 
        if ((Table[n][W] - Table[n - 1][W]) != 0) {//If the current element there is some difference between the current element and the element of the same column, but last row
            betterCombination.push_back(objects[n - 1]);//Add the element of the current row in the table
            W -= objects[n - 1].weight;//Subtract the weight of the current element in the weight "W" value
        }
        n--;//Go to the row of other object
    }
    return betterCombination;
}

void printCombination(vector<Object> betterCombination) {
    for (Object object : betterCombination) {
        cout << "=========================" << endl;
        cout << "Nome: " << object.name << endl;
        cout << "Valor: " << object.value << endl;
        cout << "Peso: " << object.weight << endl;
    }
}

void printTable(int W, int n, vector<vector<int>> Table) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << Table[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl << "=========================" << endl << endl;
}

// Function to calculate the max value to be got with max capacity "W" and with the itens gave
int dynamicProgramming(int W, vector<vector<int>> &Table, vector<Object> objects, int n) {
    for (int i = 0; i <= n; i++) {//For each row in the matrix
        for (int w = 0; w <= W; w++) {//For each column in the matrix
            if (i == 0 || w == 0) {//If the row or the column is 0.. 
                Table[i][w] = 0;//Define the current cell as beeing 0
            } else if (objects[i - 1].weight <= w) {//If the weight of the current objet is lowest than the current weight "w"
                Table[i][w] = max(objects[i - 1].value + Table[i - 1][w - objects[i - 1].weight], Table[i - 1][w]);//Finds the highest value between the price of the element in the current row plus the element in the previous row with the weight of the element in the current row discounted and the weight of the element in the same column as the current cell, but one row earlier
                printTable(W, n, Table);//print the updated table
            } else {//If the weight of the current objet is biggest than the current weight "w"
                Table[i][w] = Table[i - 1][w];//Set the value of the last row in the table
                printTable(W, n, Table);//print the updated table
            }
        }
    }
    return Table[n][W];//Return the price in the better case
}

int main() {
    vector<Object> objects = 
        {{"1", 2, 30},
                          {"2", 3, 70},
                          {"3", 1, 30},
                          {"4", 1, 20},
                          {"5", 2, 40}};
    int W = 5; // Capacidade máxima da mochila
    int n = objects.size();
    vector<vector<int>> Table(n + 1, vector<int>(W + 1, 0));
    int betterValue = dynamicProgramming(W, Table, objects, n);
    cout << "Valor maximo obtido: " << betterValue << endl;
    vector<Object> betterCombination =
        findBetterCombination(W, n, objects, Table);
    printCombination(betterCombination);
    return 0;
}
