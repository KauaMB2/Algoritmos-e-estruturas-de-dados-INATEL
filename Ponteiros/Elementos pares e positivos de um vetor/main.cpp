#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int *p=new int;
    *p=0;
    for(int i=0;i<n;i++){
        if((v[i]%2==0)&&(v[i]>0)){
            (*p)++;
        }
    }
    cout << *p;
    delete p;
    return 0;
}