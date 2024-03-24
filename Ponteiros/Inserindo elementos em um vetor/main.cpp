#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int *p;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        p=&v[i];
        cin >> *p;
    }

    for (int i = 0; i < n; i++) {
        p = &v[i]; // Atribuir o endereço do elemento do vetor para p
        cout << *p << " ";
    }
    delete p;
    return 0;
}
