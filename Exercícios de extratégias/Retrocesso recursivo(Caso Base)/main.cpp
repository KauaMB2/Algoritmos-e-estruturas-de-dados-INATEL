#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printInterationResults(int index, string type, vector<int> numbers, vector<int> subset, int &interationID){
    cout << "============== After " << type << " the current item =============" << endl;
    cout << "index: " << index << " | interationID: " << interationID << endl;
    if(type=="include"){
        cout << "Current number numbers[index] added: " << subset[subset.size()-1] << endl;
    }else{
        cout << "The last item was excluded" << endl;
    }
    cout << "Elements of the current number:" << endl;
    for(int i=0; i<subset.size();i++){
        cout << subset[i] << " ";
    }
    cout << endl;
}

void generateSubsets(vector<int>& numbers, vector<int>& subset, vector<vector<int>>& allCombinations, int index, int &interationID) {
    // Base case: If we have processed all numbers
    if (index == numbers.size()) {
        allCombinations.push_back(subset); // Add the current subset to allCombinations
        return;
    }

    // Include the current item
    subset.push_back(numbers[index]);
    printInterationResults(index, "include", numbers, subset, interationID);
    generateSubsets(numbers, subset, allCombinations, index + 1, interationID);
    //printInterationResults(index, "include", numbers, subset, interationID);

    // Exclude the current item
    subset.pop_back();//Exclude the last element
    printInterationResults(index, "exclude", numbers, subset, interationID);
    generateSubsets(numbers, subset, allCombinations, index + 1, interationID);
    //printInterationResults(index, "exclude", numbers, subset, interationID);
    interationID++;
}

int main(){
    vector<int> subset;
    vector<vector<int>> allCombinations;
    vector<int> numbers={3,5,1};
    int interationID=0;
    generateSubsets(numbers, subset, allCombinations, 0, interationID);
    return 0;
}
