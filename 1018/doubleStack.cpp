#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node *next;
    Node *prev;
    int value;
};

struct Deque{
    int size;
    Node *front;
    Node *rear;
};

void push_front (Deque* self, int val);
void push_back (Deque* self, int val);
void pop_front (Deque* self);
void pop_back (Deque* self);

int main () {
    int n = 0;
    cin >> n;
    string order;
    int val;
    auto *self = new Deque;
    self->front = nullptr;
    self->rear = nullptr;
    self->size = 0;
    for (int i = 0; i < n; i++) {
        cin >> order;
        if (order == "getSize") {
            cout << self->size << endl;
        } else if (order == "pushFront") {
            cin >> val;
            push_front(self, val);
        } else if (order == "pushBack") {
            cin >> val;
            push_back(self, val);
        } else if (order == "popFront") {
            pop_front(self);
        } else if (order == "popBack") {
            pop_back(self);
        }
    }
}

void push_front (Deque* self, int val) {
    Node *first = new Node;
    first->prev = nullptr;
    if (self->size == 0) {
        first->next = nullptr;
        self->rear = first;
    } else {
        first->next = self->front;
        self->front->prev = first;
    }
    first->value = val;
    self->front = first;
    self->size++;
}

void push_back (Deque* self, int val) {
    Node *back = new Node;
    back->next = nullptr;
    if (self->size == 0) {
        back->prev = nullptr;
        self->front = nullptr;
    } else {
        back->prev = self->rear;
        self->rear->next = back;
    }
    back->value = val;
    self->rear = back;
    self->size++;
}

void pop_front (Deque* self) {
    if (self->size == 0) {
        cout << "-1" << endl;
        return;
    }
    cout << self->front->value << endl;
    if (self->size == 1) {
        free(self->front);
        self->rear = nullptr;
        self->front = nullptr;
    } else {
        self->front = self->front->next;
        free(self->front->prev);
        self->front->prev = nullptr;
    }
    self->size--;
}

void pop_back (Deque* self) {
    if (self->size == 0) {
        cout << "-1" << endl;
        return;
    }
    cout << self->rear->value << endl;
    if (self->size == 1) {
        free(self->rear);
        self->rear = nullptr;
        self->front = nullptr;
    } else {
        self->rear = self->rear->prev;
        free(self->rear->next);
        self->rear->next = nullptr;
    }
    self->size--;
}