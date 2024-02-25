#include "limits.h"
#include <iostream>
using namespace std;

int main() {
  int M, m = 0, biggestValue = INT_MIN;
  int width = 0, length = 0;
  cin >> M;
  for (int i = M; i > 0; i--) {
    m++;
    M--;
    M--;
    if ((M * m) > biggestValue) {
      biggestValue = M * m;
      width = m;
      length = M;
    }
  }
  cout << width << "x" << length << endl;
}