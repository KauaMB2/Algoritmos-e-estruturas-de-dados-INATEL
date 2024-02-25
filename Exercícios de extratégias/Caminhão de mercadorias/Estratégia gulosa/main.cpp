#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

struct Box {
  string name;
  int amount;
  int volume;
  int price;
};
// Function to partition the array and return the pivot index
int partition(vector<Box> &arr, int low, int high) {
  int pivot =
      arr[high].volume; // Choose pivot as the volume of the last element
  int i = low - 1;      // Index of the smaller element

  for (int j = low; j < high; j++) {
    if (arr[j].volume < pivot) {
      i++; // Increment index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Recursive function to perform QuickSort
void quickSort(vector<Box> &arr, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  int W, L, D, Vmax;
  cin >> W >> L >> D;
  Vmax = W * L * D;
  vector<Box> boxes = {{"Bloco A", 10, 20, 200},
                       {"Bloco B", 20, 3, 150},
                       {"Bloco C", 25, 4, 100}};
  quickSort(boxes, 0, boxes.size() - 1);
  bool full = false;
  vector<Box> selectedBoxes;
  vector<tuple<string, int>> totalBoxes;
  for (int i = 0; (i < boxes.size()) && (full != true); i++) {
    int totalVolume = 0;
    int totalAmount = 0;
    for (int j = 0; j < boxes[i].amount; j++) {
      totalVolume += boxes[i].volume;
      if (totalVolume > Vmax) {
        full = true;
        totalBoxes.push_back(make_tuple(boxes[i].name, totalAmount));
        break;
      }
      totalAmount++;
    }
  }
  for (int i = 0; i < totalBoxes.size(); i++) {
    cout << get<0>(totalBoxes[i]) << ": " << get<1>(totalBoxes[i]) << endl;
  }
  return 0;
}