#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stone {
  string name;
  float volume;
  int weight;
  int price;
};

void compareFunction(vector<Stone> subset, vector<Stone> &betterCombination,
                     int &totalPrice) {
  float provisionalTotalVolume = 0;
  int provisionalTotalWeight = 0;
  int provisionalTotalPrice = 0;
  for (int i = 0; i < subset.size(); i++) {
    provisionalTotalPrice += subset[i].price;
    provisionalTotalWeight += subset[i].weight;
    provisionalTotalVolume += subset[i].volume;
  }
  if ((provisionalTotalVolume > 1.0) || (provisionalTotalWeight > 400)) {
    return;
  }
  if (provisionalTotalPrice > totalPrice) {
    totalPrice = provisionalTotalPrice;
    betterCombination = subset;
  }
}

void generateSubsets(vector<Stone> &stones, vector<Stone> &subset, int index,
                     int &totalPrice, vector<Stone> &betterCombination) {
  // This "if" is necessary to make sure that all the stones were checked and
  // return the function
  if (index == stones.size()) { // Verify if the current index is the last one
    compareFunction(subset, betterCombination, totalPrice);
    return;
  }
  // Exclude the current stone
  generateSubsets(
      stones, subset, index + 1, totalPrice,
      betterCombination); // Generate  subset whitout the current stone
  // Include the current stone
  subset.push_back(stones[index]); // Add the current stone to the subset
  generateSubsets(
      stones, subset, index + 1, totalPrice,
      betterCombination); // Generate subset with the current stone included
  subset.pop_back(); // Delete the last element of the list to return the list
                     // in the initial state
}

int main() {
  vector<Stone> stones = {{"Diamond", 0.455, 263, 500},
                          {"Emerald", 0.521, 127, 410},
                          {"Topaz", 0.521, 127, 320},
                          {"Ruby", 0.065, 134, 315},
                          {"Jade", 0.012, 111, 280}};

  vector<Stone> subset;
  vector<Stone> betterCombination;
  int totalPrice = 0;
  generateSubsets(stones, subset, 0, totalPrice, betterCombination);
  for (const auto &stone : betterCombination) {
    cout << stone.name << " ";
  }
  cout << endl << "Total price: " << totalPrice << endl;
  return 0;
}
