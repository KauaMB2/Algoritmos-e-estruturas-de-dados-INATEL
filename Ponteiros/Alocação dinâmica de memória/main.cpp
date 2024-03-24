#include <iostream>
using namespace std;

struct Grades{
    int g1;
    int g2;
    int g3;
    int g4;
    float gTotal;
};
int main(){
    Grades *p=new Grades;
    cin >> (*p).g1;
    cin >> (*p).g2;
    cin >> (*p).g3;
    cin >> (*p).g4;
    (*p).gTotal=(float((*p).g1)+float((*p).g2)+float((*p).g3)+float((*p).g4))/4;
    cout << (*p).gTotal;
    delete p;
    return 0;
}
