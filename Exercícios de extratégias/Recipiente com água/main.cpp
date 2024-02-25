#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int maxArea(vector<int> heights){
    int biggestArea=0;
    for(int i=0;i<heights.size();i++){
        for(int j=0;j<heights.size();j++){
            if(j==i){
                continue;
            }
            int height, width=abs(j-i);
            if(heights[i]<heights[j]){
                height=heights[i];
            }else{
                height=heights[j];
            }
            if((width*height)>biggestArea){
                biggestArea=height*width;
            }
        }
    }
    return biggestArea;
}

int main(){
    vector<int> heights;
    while(true){
        int height;
        cin >> height;
        if(cin.peek()=='\n'){
            break;
        }
        heights.push_back(height);
    }
    int result=maxArea(heights);
    cout << result << endl;
    return 0;
}