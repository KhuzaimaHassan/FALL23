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
    int hash(int key) {
        return key % capacity;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hash(key);

        while (table[index] != -1) {
            // Linear probing: move to the next slot if the current one is occupied
            index = (index + 1) % capacity;
        }

        // Insert the key into the empty slot
        table[index] = key;
    }

    // Search for key in the hash table
    bool search(int key) {
        int index = hash(key);

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            // Move to the next slot using linear probing
            index = (index + 1) % capacity;
        }

        // Key not found
        return false;
    }

    // Delete key from the hash table
    void remove(int key) {
        int index = hash(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                // Key found, mark the slot as empty
                table[index] = -1;
                std::cout << "Key " << key << " deleted from the hash table." << std::endl;
                return;
            }

            // Move to the next slot using linear probing
            index = (index + 1) % capacity;
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
    hashTable.insert(45);

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
