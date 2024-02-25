#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Boa sorte pro computador de quem está corrigindo ter memória RAM o suficiente pra armazenar tanta variável temporária da função generateSubsets() HAAHAHAHAHAHAHA

struct Box {
  string name;
  int volume;
  int price;
};

void comparationFunction(vector<Box> &biggestPriceCombination,
                         vector<Box> subset, int Vmax, int &biggestPrice) {
  int currentBiggestVolume = 0;
  int currentBiggestPrice = 0;
  for (int i = 0; i < subset.size(); i++) {
    currentBiggestVolume += subset[i].volume;
  }
  if (currentBiggestVolume > Vmax) {
    return;
  }
  for (int i = 0; i < subset.size(); i++) {
    currentBiggestPrice += subset[i].price;
  }
  if (currentBiggestPrice > biggestPrice) {
    biggestPriceCombination = subset;
    biggestPrice = currentBiggestPrice;
  }
}

void generateSubsets(vector<Box> &boxes, vector<Box> &subset,
                     vector<vector<Box>> &allCombinations, int index,
                     vector<Box> &biggestPriceCombination, int Vmax,
                     int &biggestPrice) {
  // Base case: If we have processed all boxes
  if (index == boxes.size()) {
    comparationFunction(biggestPriceCombination, subset, Vmax, biggestPrice);
    allCombinations.push_back(
        subset); // Add the current subset to allCombinations
    return;
  }
  // Include the current box
  subset.push_back(boxes[index]);
  generateSubsets(boxes, subset, allCombinations, index + 1,
                  biggestPriceCombination, Vmax, biggestPrice);

  // Exclude the current box
  subset.pop_back();
  generateSubsets(boxes, subset, allCombinations, index + 1,
                  biggestPriceCombination, Vmax, biggestPrice);
}

int main() {
  int W, L, D, Vmax;
  cin >> W >> L >> D;
  Vmax = W * L * D;
  vector<Box> subset;
  vector<vector<Box>> allCombinations;
  vector<Box> boxes;
  vector<Box> biggestPriceCombination;
  int biggestPrice;
  for (int i = 0; i < 10; i++) {
    boxes.push_back({"Bloco A", 20, 200});
  }
  for (int i = 0; i < 20; i++) {
    boxes.push_back({"Blaca B", 3, 150});
  }
  for (int i = 0; i < 25; i++) {
    boxes.push_back({"Blaca C", 4, 100});
  }
  generateSubsets(boxes, subset, allCombinations, 0, biggestPriceCombination,
                  Vmax, biggestPrice);
  int amountBlockA = 0, amountBlockB = 0, amountBlockC = 0;
  for (Box box : biggestPriceCombination) {
    if (box.name == "Bloco A") {
      amountBlockA++;
    }
    if (box.name == "Bloco B") {
      amountBlockB++;
    }
    if (box.name == "Bloco C") {
      amountBlockC++;
    }
  }
  cout << "Bloco A: " << amountBlockA << endl;
  cout << "Bloco B: " << amountBlockB << endl;
  cout << "Bloco C: " << amountBlockC << endl;
  return 0;
}
