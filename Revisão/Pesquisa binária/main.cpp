#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product{
    string name;
    int code;
    int amount;
};
Product binarySearch(const vector<Product> &arr, int target) {
    int left = 0;//index of the first
    int right = arr.size() - 1;//It is the index of the last object

    while (left <= right) {
        int mid = left + (right - left) / 2;//Get the index of the middle
        if (arr[mid].code == target) {
            return arr[mid]; // Found the target
        } else if (arr[mid].code < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return Product(); // Target not found
}
int main(){
    int cols;
    cin >> cols;
    vector<Product> products;
    for(int i=0; i<cols;i++){
        Product product;
        cin >> product.code;
        cin >> product.name;
        cin >> product.amount;
        products.push_back(product);
    }
    int selectedCode;
    cin >> selectedCode;
    Product result=binarySearch(products, selectedCode);
    if(result.code==0){
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    }else{
        cout << result.name << " em estoque!" << endl;
    }
    return 0;
}
