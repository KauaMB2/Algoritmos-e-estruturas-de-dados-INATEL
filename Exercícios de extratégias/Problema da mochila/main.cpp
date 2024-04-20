#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stone {
  string name;
  int weight;
  int price;
};

void compareFunction(vector<Stone> &subset, vector<Stone> &betterCombination, int &totalPrice) {
  int provisionalTotalWeight = 0;
  int provisionalTotalPrice = 0;
  for (int i = 0; i < subset.size(); i++) {
    provisionalTotalPrice += subset[i].price;
    provisionalTotalWeight += subset[i].weight;
  }
  if (provisionalTotalWeight > 5) {
    return;
  }
  if (provisionalTotalPrice > totalPrice) {
    totalPrice = provisionalTotalPrice;
    betterCombination = subset;
  }
}

void generateSubsets(vector<Stone> &stones, vector<Stone> &subset, int index, int &totalPrice, vector<Stone> &betterCombination, int &counter) {
  // This "if" is necessary to make sure that all the stones were checked and
  // return the function
  if (index == stones.size()) { // Verify if the current index is the last one
    compareFunction(subset, betterCombination, totalPrice);
    counter++;
    return;
  }
  // Exclude the current stone
  generateSubsets(stones, subset, index + 1, totalPrice, betterCombination, counter); // Generate  subset whitout the current stone
  // Include the current stone
  subset.push_back(stones[index]); // Add the current stone to the subset
  generateSubsets(stones, subset, index + 1, totalPrice, betterCombination, counter); // Generate subset with the current stone included
  subset.pop_back(); // Delete the last element of the list to return the list in the initial state
}

int main() {
  vector<Stone> stones = {{"1", 2, 30},
                          {"2", 3, 70},
                          {"3", 1, 30},
                          {"4", 1, 20},
                          {"5", 2, 40}};
  vector<Stone> subset;
  vector<Stone> betterCombination;
  int counter=0;
  int totalPrice = 0;
  generateSubsets(stones, subset, 0, totalPrice, betterCombination, counter);
  for (const auto &stone : betterCombination) {
    cout << stone.name << " ";
  }
  cout << endl << "Total price: " << totalPrice << endl;
  cout << "Combinations possibles: " << counter << endl;
  return 0;
}
