#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<int> table;
    int capacity;

public:
    HashTable(int size) {
        capacity = size;
        table.resize(capacity, -1);  // Initialize table with -1 (indicating empty slot)
    }

    // Hash function (simple modulo hash)
    int hash1(int key) {
        return key % capacity;
    }
    int hash2(int key){
        return 7-(key%7);
    }

    // Quadratic probing function
    int double_hash(int key, int attempt) {
        return (hash1(key)+attempt*hash2(key))%capacity;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hash1(key);
        int attempt = 0;

        while (table[index] != -1) {
            // Quadratic probing: move to the next slot using quadratic function
            attempt++;
            index = double_hash(key, attempt);
        }

        // Insert the key into the empty slot
        table[index] = key;
    }

    // Search for key in the hash table
    bool search(int key) {
        int index = hash1(key);
        int attempt = 0;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            // Quadratic probing: move to the next slot using quadratic function
            attempt++;
            index = double_hash(index, attempt);
        }

        // Key not found
        return false;
    }

    // Delete key from the hash table
    void remove(int key) {
        int index = hash1(key);
        int attempt = 0;

        while (table[index] != -1) {
            if (table[index] == key) {
                // Key found, mark the slot as empty
                table[index] = -1;
                std::cout << "Key " << key << " deleted from the hash table." << std::endl;
                return;
            }

            // Quadratic probing: move to the next slot using quadratic function
            attempt++;
            index = double_hash(index, attempt);
        }

        // Key not found
        std::cout << "Key " << key << " not found in the hash table. Cannot delete." << std::endl;
    }

    // Display the contents of the hash table
    void display() {
        std::cout << "Hash Table: ";
        for (int i : table) {
            if (i == -1)
                std::cout << "Empty ";
            else
                std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(5);
    hashTable.insert(25);
    hashTable.insert(15);
    hashTable.insert(35);
    hashTable.insert(47);

    hashTable.display();

    int keyToSearch = 15;
    if (hashTable.search(keyToSearch))
        std::cout << "Key " << keyToSearch << " found in the hash table." << std::endl;
    else
        std::cout << "Key " << keyToSearch << " not found in the hash table." << std::endl;

    int keyToDelete = 25;
    hashTable.remove(keyToDelete);

    hashTable.display();

    return 0;
}