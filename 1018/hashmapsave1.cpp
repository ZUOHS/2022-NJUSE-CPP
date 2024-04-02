#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct list {
    int key;
    string value;
    list *next = nullptr;
    list *nextInLine = nullptr;
    list *lastInLine = nullptr;
};

struct Entry {
    int number = 0;
    string hashCode;
    int key{};
    string value;
    list *next = nullptr;
};

int Pos(int key, int length);

void add(Entry *entry, list *start, list *rear, int position, int key, string value, int judge);

void rehash(Entry *entry, list *start, list *rear, int length);

void Delete(Entry *entry, list *start, list *rear, int position, int key);

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
    list *start = nullptr;
    list *rear = nullptr;
    //record the single list

    for (int i = 0; i < n; i++) {
        cin >> order;
        if (order == "add") {
            count++;
            int key = 0;
            string value;
            cin >> key >> value;
            int position = Pos(key, length);
            add(entry, start, rear, position, key, value, 0);
            if (count > length || entry[position].number > 4) {
                length = length * 2 - 1;
                rehash(entry, start, rear, length);
            }
        } else if (order == "delete") {
            count--;
            int key = 0;
            cin >> key;
            int position = Pos(key, length);
            Delete(entry, start, rear, position, key);
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

void add(Entry *entry, list *start, list *rear, int position, int key, string value, int judge) {
    list *toAdd = nullptr;
    if (judge == 0) {
        if (start == nullptr) {
            start = new list;
            rear = start;
        } else {
            rear->nextInLine = new list;
            rear->nextInLine->lastInLine = rear;
            rear = rear->nextInLine;
        }
        rear->key = key;
        rear->value = value;
        toAdd = rear;
    } else {
        toAdd = start;
    }

    if (entry[position].next == nullptr) {
        entry[position].next = toAdd;
        entry[position].number++;
    } else {
        list *temp = entry[position].next;
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

void rehash(Entry *entry, list *start, list *rear, int length){
    for (int i = 0; i < length; i++) {
        entry[i].next = nullptr;
        entry[i].number = 0;
    }
    list *temp = start;
    while(temp->nextInLine != nullptr) {
        add(entry, temp, rear, Pos(temp->key, length), temp->key, temp->value, 1);
        temp = temp->nextInLine;
    }
    add(entry, temp, rear, Pos(temp->key, length), temp->key, temp->value, 1);
}

void Delete(Entry *entry, list *start, list *rear, int position, int key){
    if (entry[position].next->key == key) {
        entry[position].next = entry[position].number == 1 ? nullptr : entry[position].next->next;
    } else {
        list *temp = entry[position].next;
        for (int i = 1; i < entry[position].number; i++) {
            if (temp->next->key == key) {
                temp->next = temp->next->next == nullptr ? nullptr : temp->next->next;
            }
        }
    }

    list *temp = start;
    if (temp->key == key) {
        if (temp->nextInLine == nullptr) {
            free(temp);
            start = nullptr;
            rear = nullptr;
        } else {
            start = start->nextInLine;
            free(start->lastInLine);
            start->lastInLine = nullptr;
        }
        entry[position].number--;
        return;
    } else if (rear->key == key) {
        rear = rear->lastInLine;
        free(rear->nextInLine);
        rear->nextInLine = nullptr;
        entry[position].number--;
        return;
    }

    temp = temp->nextInLine;
    while (temp->nextInLine != nullptr) {
        if (temp->key == key) {
            temp->lastInLine->nextInLine = temp->nextInLine;
            temp->nextInLine->lastInLine = temp->lastInLine;
            free(temp);
            entry[position].number--;
            return;
        }
        temp = temp->nextInLine;
    }
}

void search(Entry *entry, int position){
    if (entry[position].number == 0) {
        cout << "null" << endl;
        return;
    }
    list *temp = entry[position].next;
    while(temp->next != nullptr) {
        cout << temp->key << ":" << temp->value << "->";
        temp = temp->next;
    }
    cout << temp->key << ":" << temp->value << endl;
}
