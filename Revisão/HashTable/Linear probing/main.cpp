#include <iostream>
#include <vector>

using namespace std;

// Hash function using modulo method
int hashFunction(int key, int size) {
    return key % size;
}

// Linear probing for collision resolution
int probe(int index, int size) {
    return (index + 1) % size; // Move to the next index (circular)
}

// Function to insert a key into the hash table
void insert(int key, vector<int>& table, int size) {
    int index = hashFunction(key, size); // Calculate initial index

    // Linear probing until an empty slot is found
    while (table[index] != -1) {//While we don't find a void space
        index = probe(index, size);
    }

    table[index] = key; // Insert the key at the index position
}

// Function to print the hash table
void printTable(const vector<int>& table) {
    cout << "Hash Table:" << endl;
    for (size_t i = 0; i < table.size(); i++) {
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