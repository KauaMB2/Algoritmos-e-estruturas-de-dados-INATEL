#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Grades{
    int g1;
    int g2;
    int g3;
    int g4;
    float gTotal;
};
int main(){
    int n;
    float average=0.0;
    cin >> n;
    vector<Grades> *p=new vector<Grades>(n);
    for(int i=0;i<n;i++){
        cin >> (*p)[i].g1;
        cin >> (*p)[i].g2;
        cin >> (*p)[i].g3;
        cin >> (*p)[i].g4;
        (*p)[i].gTotal=(float((*p)[i].g1)+float((*p)[i].g2)+float((*p)[i].g3)+float((*p)[i].g4))/4;
    }
    for(int i=0;i<n;i++){
        average+=(*p)[i].gTotal;
    }
    average/=(*p).size();
    cout << fixed << setprecision(2);
    cout << average << endl;
    delete p;
    return 0;
}
