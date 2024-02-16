#include <iostream>
#include <vector>

using namespace std;

// Hash function using modulo method
int hashFunction(int key, int size) {
    return key % size;
}

// Quadratic probing for collision resolution
int probe(int index, int size, int i, int c1, int c2) {
    return (index + c1 * i + c2 * i * i) % size;
}

// Function to insert a key into the hash table
void insert(int key, vector<int>& table, int size, int c1, int c2) {
    int index = hashFunction(key, size); // Calculate initial index
    int i = 0; // Iteration count

    // Quadratic probing until an empty slot is found
    while (table[index] != -1) {
        index = probe(index, size, i++, c1, c2);
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

    // Constants for quadratic probing
    int c1 = 1;
    int c2 = 3;

    // Insert keys into the hash table
    insert(10, hashTable, size, c1, c2);
    insert(22, hashTable, size, c1, c2);
    insert(31, hashTable, size, c1, c2);
    insert(4, hashTable, size, c1, c2);
    insert(15, hashTable, size, c1, c2);
    insert(28, hashTable, size, c1, c2);
    insert(17, hashTable, size, c1, c2);
    insert(88, hashTable, size, c1, c2);
    insert(59, hashTable, size, c1, c2);

    // Print the resulting hash table
    printTable(hashTable);

    return 0;
}
