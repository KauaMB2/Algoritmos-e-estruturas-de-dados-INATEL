#include <algorithm>
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

// Comparison function to compare Stones based on their price
bool compareByPrice(const Stone &a, const Stone &b) { // O(3)
  return a.price < b.price; // Sort in ascending order of price
}

int main() {
  vector<Stone> stones = {{"Diamond", 0.455, 263, 500},
                          {"Emerald", 0.521, 127, 410},
                          {"Topaz", 0.521, 127, 320},
                          {"Ruby", 0.065, 134, 315},
                          {"Jade", 0.012, 111, 280}};
  // Sort the stones vector based on the price feature
  sort(stones.begin(), stones.end(), compareByPrice);
  int totalPrice = 0;
  int totalWeight = 0;
  int totalVolume = 0;

  for (const auto &stone : stones) {
    totalVolume += stone.volume;
    totalWeight += stone.weight;
    if ((totalVolume > 1.0) || (totalWeight > 400)) {
      break;
    }
    totalPrice += stone.price;
    cout << stone.name << " ";
  }
  cout << endl << "Total price: " << totalPrice << endl;
  return 0;
}
