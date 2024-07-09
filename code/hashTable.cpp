#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

const int TABLE_SIZE = 128;

class HashEntry {
public:
    int key;
    int value;
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashMap {
private:
    HashEntry **table;
public:
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void Insert(int key, int value) {
        int hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }

    int Search(int key) {
        int hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key) {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->value;
    }

    void Remove(int key) {
        int hash = HashFunc(key);
        while (table[hash] != NULL) {
            if (table[hash]->key == key)
                break;
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL) {
            cout << "No Element found at key " << key << endl;
            return;
        } else {
            delete table[hash];
        }
        cout << "Element Deleted" << endl;
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL)
                delete table[i];
        }
        delete[] table;
    }
};

int main() {
    HashMap hash;
    int key, value;

    cout << "Insert element into the table\n";
    cout << "Enter element to be inserted: ";
    cin >> value;
    cout << "Enter key at which element to be inserted: ";
    cin >> key;
    hash.Insert(key, value);

    cout << "Search element from the key\n";
    cout << "Enter key of the element to be searched: ";
    cin >> key;
    int result = hash.Search(key);
    if (result == -1) {
        cout << "No element found at key " << key << endl;
    } else {
        cout << "Element at key " << key << ": " << result << endl;
    }

    cout << "Delete element at a key\n";
    cout << "Enter key of the element to be deleted: ";
    cin >> key;
    hash.Remove(key);

    return 0;
}

