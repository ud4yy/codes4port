#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

class HashMap {
private:
    static const int TABLE_SIZE = 128;
    vector<list<pair<int, int>>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashMap() : table(TABLE_SIZE) {}

    void insert(int key, int value) {
        int hashValue = hashFunction(key);
        for (auto pair : table[hashValue]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[hashValue].emplace_back(key, value);
    }

    int search(int key) {
        int hashValue = hashFunction(key);
        for (auto pair : table[hashValue]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int hashValue = hashFunction(key);
        auto &cell = table[hashValue];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                return;
            }
        }
        cout << "No element found at key " << key << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": ";
                for (auto pair : table[i]) {
                    cout << "[" << pair.first << ": " << pair.second << "] ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashMap hash;
    int key, value;
    int choice;
    while (1) {
        cout << "\n----------------------" << endl;
        cout << "Operations on Hash Table" << endl;
        cout << "\n----------------------" << endl;
        cout << "1. Insert element into the table" << endl;
        cout << "2. Search element by key" << endl;
        cout << "3. Delete element at a key" << endl;
        cout << "4. Display table" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> value;
                cout << "Enter key at which element to be inserted: ";
                cin >> key;
                hash.insert(key, value);
                break;
            case 2:
                cout << "Enter key of the element to be searched: ";
                cin >> key;
                if (hash.search(key) == -1) {
                    cout << "No element found at key " << key << endl;
                } else {
                    cout << "Element at key " << key << ": " << hash.search(key) << endl;
                }
                break;
            case 3:
                cout << "Enter key of the element to be deleted: ";
                cin >> key;
                hash.remove(key);
                break;
            case 4:
                hash.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "\nEnter correct option\n";
        }
    }
    return 0;
}

