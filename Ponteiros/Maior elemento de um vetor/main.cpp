#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int *p = new int;
    *p = v[0];

    for (int i = 0; i < n; i++) {
        if (*p < v[i]) {
            *p = v[i];
        }
    }

    cout << fixed << setprecision(2);
    cout << *p << endl;

    delete p;

    return 0;
}
