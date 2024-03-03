#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void printPathtable(int n, vector<vector<int>> path, string pathName) {
    cout << "Path Name: " << pathName << endl;
    for (int i = 0; i < n; i++) {
        for (int w = 0; w < n; w++) {
            cout << path[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl << "=========================" << endl << endl;
}

// Function to find the minimum time required to complete the product
int assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, vector<int>& path) {
    int n = a[0].size();

    // Time taken to reach each station on the first and second lines
    vector<int> f1(n), f2(n);
    // Paths to reach each station on the first and second lines
    vector<vector<int>> p1(n, vector<int>(n)), p2(n, vector<int>(n));

    // Base case: time taken to reach the first station on each line
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];

    // Dynamic programming step: calculate the minimum time and path for each station
    for (int i = 1; i < n; ++i) {//Compares if the time of the processing time of the current station and the transfering time to the next station is shortest than the processing time of the other line plus the time of tranfering to the other line and the processing time of the current station
        if (f1[i - 1] + a[0][i] <= f2[i - 1] + t[1][i] + a[0][i]) {
            f1[i] = f1[i - 1] + a[0][i];//Add more one time to the time array
            //p[i] -> Represents which line(1 or 2) the product came to reach station 'i' | p[i][i] -> Represents which line(1 or 2) the product currently is at station 'i'
            p1[i] = p1[i - 1];
            p1[i][i] = 1; // 1 indicates station on line 1
            //printPathtable(n, p1, "path1");
        } else {//If it isn't
            f1[i] = f2[i - 1] + t[1][i] + a[0][i];//Add more one time to the time array
            p1[i] = p2[i - 1];
            //p[i] -> Represents which line(1 or 2) the product came to reach station 'i' | p[i][i] -> Represents which line(1 or 2) the product currently is at station 'i'
            p1[i][i] = 2; // 2 indicates station on line 2
            //printPathtable(n, p1, "path1");
        }

        if (f2[i - 1] + a[1][i] <= f1[i - 1] + t[0][i] + a[1][i]) {//Compares if the time of the processing time of the current station and the transfering time to the next station is shortest than the processing time of the other line plus the time of tranfering to the other line and the processing time of the current station
            f2[i] = f2[i - 1] + a[1][i];//Add more one time to the time array
            //p[i] -> Represents which line(1 or 2) the product came to reach station 'i' | p[i][i] -> Represents which line(1 or 2) the product currently is at station 'i'
            p2[i] = p2[i - 1];
            p2[i][i] = 2; // 2 indicates station on line 2
            //printPathtable(n, p2, "path2");
        } else {//If it isn't
            f2[i] = f1[i - 1] + t[0][i] + a[1][i];//Add more one time to the time array
            p2[i] = p1[i - 1];
            //p[i] -> Represents which line(1 or 2) the product came to reach station 'i' | p[i][i] -> Represents which line(1 or 2) the product currently is at station 'i'
            p2[i][i] = 1; // 1 indicates station on line 1
            //printPathtable(n, p2, "path2");
        }
    }

    // Determine the line with minimum exit time
    int minTime = min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
    path = (f1[n - 1] + x[0] <= f2[n - 1] + x[1]) ? p1[n - 1] : p2[n - 1];

    return minTime;
}

int main() {
    // Example data
    vector<vector<int>> a = {{4, 5, 3, 2}, {2, 10, 1, 4}}; // Processing times for each station
    vector<vector<int>> t = {{0, 7, 4, 5}, {0, 9, 2, 8}};  // Transfer times between stations
    vector<int> e = {10, 12};                              // Entry times for each line
    vector<int> x = {18, 7};                               // Exit times for each line
    vector<int> path;

    int minTime = assemblyLineScheduling(a, t, e, x, path);
    cout << "Minimum time to complete the product: " << minTime << endl;

    cout << "Path: ";
    for (int station : path) {
        cout << station << " ";
    }
    cout << endl;

    return 0;
}
