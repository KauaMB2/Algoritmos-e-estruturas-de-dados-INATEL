#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Estrutura para armazenar as dimensões das matrizes
struct Matrix {
    int rows;
    int cols;
};

// Função para calcular o menor custo de multiplicação de matrizes
int minMatrixChainOrder(const vector<Matrix>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L len subcadeias de matrizes
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1].rows * arr[k].cols * arr[j].cols;
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            };
        }
    }
    return dp[1][n - 1];
}

int main() {
    // Exemplo de entrada: Dimensões de 3 matrizes: 10x30, 30x5 e 5x60
    vector<Matrix> arr = { {20, 35}, {35, 15}, {15, 10}, {10, 55} };

    cout << "O menor custo de multiplicacao de matrizes e: " << minMatrixChainOrder(arr) << endl;

    return 0;
}
