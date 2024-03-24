#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int n;
    float average=0;
    float *p=&average;
    cin >> n;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        *p+=float(v[i]);
    }
    *p/=n;
    cout << fixed << setprecision(2);
    cout << *p;
    delete p;
    return 0;
}