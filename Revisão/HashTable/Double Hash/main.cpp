#include <iostream>
#include <vector>

using namespace std;

// Primary hash function
int hash1(int key, int size) {
    return key % size;
}

// Secondary hash function
int hash2(int key, int size) {
    // Use a prime number smaller than the size of the hash table for better distribution
    return 5 - (key % 5);
}

// Double hashing for collision resolution
int doubleHash(int key, int size, int i) {
    return (hash1(key, size) + i * hash2(key, size)) % size;
}

// Function to insert a key into the hash table
void insert(int key, vector<int>& table, int size) {
    int index = hash1(key, size); // Calculate initial index
    int i = 0; // Iteration count

    // Double hashing until an empty slot is found
    while (table[index] != -1) {
        index = doubleHash(key, size, ++i);
    }

    table[index] = key; // Insert the key at the index position
}

// Function to print the hash table
void printTable(const vector<int>& table) {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < table.size(); i++) {
        if (table[i] != -1) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
}

int main() {
    const int size = 10; // Size of the hash table
    vector<int> hashTable(size, -1); // Initialize all elements to -1 (indicating empty slots)

    // Insert keys into the hash table
    insert(10, hashTable, size);
    insert(22, hashTable, size);
    insert(31, hashTable, size);
    insert(4, hashTable, size);
    insert(15, hashTable, size);
    insert(28, hashTable, size);
    insert(17, hashTable, size);
    insert(88, hashTable, size);
    insert(59, hashTable, size);

    // Print the resulting hash table
    printTable(hashTable);

    return 0;
}
