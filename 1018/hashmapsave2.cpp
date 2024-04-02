#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

struct Entry {
    int number = 0;
    string hashCode;
    int key = 0;
    string value;
    Entry *next = nullptr;
};

int Pos(int key, int length);

void add(Entry *entry, int position, int key, string value);

void rehash(Entry *entry, map<int, string> myMap, int length);

void Delete(Entry *entry, int position, int key);

void search(Entry *entry, int position);

int main() {
    int length = 0;
    //length of the array
    int n = 0;
    int count = 0;
    //count for nodes
    string order;
    cin >> length >> n;
    auto *entry = new Entry[100005];
    //record the single list
    map <int, string> myMap;

    for (int i = 0; i < n; i++) {
        cin >> order;
        if (order == "add") {
            count++;
            int key = 0;
            string value;
            cin >> key >> value;
            myMap.insert(pair<int, string>(key, value));
            int position = Pos(key, length);
            add(entry, position, key, value);
            if (count > length || entry[position].number > 4) {
                length = length * 2 + 1;
                rehash(entry, myMap, length);
                while(true) {
                    int judge = 0;
                    for (int j = 0; j < length; j++) {
                        if (entry[j].number > 4) {
                            judge = 1;
                            break;
                        }
                    }
                    if (judge == 0) {
                        break;
                    } else {
                        length = length * 2 + 1;
                        rehash(entry, myMap, length);
                    }
                }
            }
        } else if (order == "delete") {
            count--;
            int key = 0;
            cin >> key;
            myMap.erase(key);
            int position = Pos(key, length);
            Delete(entry, position, key);
        } else if (order == "search") {
            int position = 0;
            cin >> position;
            search(entry, position);
        }
    }
}

int Pos(int key, int length) {
    key = key % length;
    return ((int)abs(3 * pow(key, 3) + 5 * pow(key, 2) + 7 * key + 11)) % length;
}

void add(Entry *entry, int position, int key, string value) {
    Entry *toAdd = new Entry;
    toAdd->key = key;
    toAdd->value = value;

    if (entry[position].next == nullptr) {
        entry[position].next = toAdd;
        entry[position].number++;
    } else {
        Entry *temp = entry[position].next;
        if (key < temp->key) {
            toAdd->next = temp;
            entry[position].next = toAdd;
            entry[position].number++;
            return;
        }
        for (int i = 1; i < entry[position].number; i++) {
            if (key > temp->key && key < temp->next->key) {
                toAdd->next = temp->next;
                temp->next = toAdd;
                entry[position].number++;
                return;
            }
            temp = temp->next;
        }
        temp->next = toAdd;
        entry[position].number++;
    }
}

void rehash(Entry *entry, map<int, string> myMap, int length){
    for (int i = 0; i < length; i++) {
        entry[i].next = nullptr;
        entry[i].number = 0;
    }
    map<int, string>::iterator itr;
    itr = myMap.begin();
    while(itr != myMap.end()) {
        int position = Pos(itr->first, length);
        add(entry, position, itr->first, itr->second);
        itr++;
    }
}

void Delete(Entry *entry, int position, int key){
    if (entry[position].next->key == key) {
        entry[position].next = entry[position].number == 1 ? nullptr : entry[position].next->next;
    } else {
        Entry *temp = entry[position].next;
        for (int i = 1; i < entry[position].number; i++) {
            if (temp->next->key == key) {
                temp->next = temp->next->next == nullptr ? nullptr : temp->next->next;
            }
        }
    }
    entry[position].number--;
}

void search(Entry *entry, int position){
    if (entry[position].number == 0) {
        cout << "null" << endl;
        return;
    }
    Entry *temp = entry[position].next;
    while(temp->next != nullptr) {
        cout << temp->key << ":" << temp->value << "->";
        temp = temp->next;
    }
    cout << temp->key << ":" << temp->value << endl;
}