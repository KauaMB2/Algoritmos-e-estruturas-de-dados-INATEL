#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product{
    string name;
    int amount;
};

int main(){
    int cols;
    cin >> cols;
    vector<Product> products;
    for(int i=0; i<cols;i++){
        Product product;
        cin >> product.name;
        cin >> product.amount;
        products.push_back(product);
    }
    string selectedProduct;
    cin >> selectedProduct;
    for(int i=0;i<cols;i++){
        if(products[i].name==selectedProduct){
            cout << products[i].name << " em estoque!" << endl;
            break;
        }
        if(i==cols-1){
            cout << "Nao existe " <<  selectedProduct << " em estoque!" << endl;
        }
    }
    return 0;
}