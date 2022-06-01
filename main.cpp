#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement 905, Jimmy (phone book)

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; // List 1, Index 0, List 2, Index 1.....
public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const {
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (sum == 0) {
        return true;
    } else {
        return false;
    }
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;    // Key: 905, in return, this function will spit out 5 (index 6)
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);    // iterator (to know if key exists already or not)
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout<<"[WARNING] Key exists. Value replaced."<<endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);    // iterator (to know if key exists already or not)
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout<<"[INFO] Pair removed."<<endl;
            break;
        }
    }
    if (!keyExists) {
        cout<<"[WARNING] Key not found. Pair not removed."<<endl;
    }
    return;
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0)
            continue;
        else {
            auto bItr = table[i].begin();
            for (; bItr != table[i].end(); bItr++) {
                cout<<"[INFO] Key: "<<bItr->first<<" Value: "<<bItr->second<<endl;
            }
        }
    }
    return;
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout<<"Is empty!"<<endl;
    } else {
        cout<<"Isn't empty..?"<<endl;
    }

    HT.insertItem(905, "Jim");
    HT.insertItem(906, "Tom");
    HT.insertItem(907, "Sally");
    HT.insertItem(908, "Bob");
    HT.insertItem(909, "Sandy");
    HT.insertItem(901, "Barb");
    HT.insertItem(902, "Jan");
    HT.insertItem(902, "Rick");

    HT.printTable();

    HT.removeItem(908);
    HT.removeItem(123);     // random key not in hash table

    if (HT.isEmpty()) {
        cout<<"Is empty..?"<<endl;
    } else {
        cout<<"Isn't empty!"<<endl;
    }

    return 0;
}
