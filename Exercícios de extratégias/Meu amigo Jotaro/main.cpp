#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
  int rows, colums = 10;
  cin >> rows;
  vector<vector<int>> ways(rows - 1, vector<int>(colums, -1));
  for (int i = 0; i < ways.size(); i++) {
    for (int j = 0; j < colums; j++) {
      int distance;
      cin >> distance;
      ways[i][j] = distance;
      if (cin.peek() == '\n') {
        break;
      }
    }
  }
  vector<int> shortestWaysVector;
  for (int i = 0; i < rows - 1; i++) {
    int shortestWay = INT_MAX;
    for (int j = 0; i < colums; j++) {
      if (ways[i][j] == -1) {
        break;
      }
      if (ways[i][j] < shortestWay) {
        shortestWay = ways[i][j];
      }
    }
    shortestWaysVector.push_back(shortestWay);
  }
  int total = 0;
  for (int i = 0; i < shortestWaysVector.size(); i++) {
    total += shortestWaysVector[i];
    cout << shortestWaysVector[i] << endl;
  }
  cout << "Menor custo: " << total << endl;
  return 0;
}