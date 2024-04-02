#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int size = 0;
    int capacity = 0;
    int a[102];
    for (int i = 0; i < 102; i++) {
        a[i] = 0;
    }
    for (int l = 0; l < n; l++) {
        char order[15];
        cin >> order;
        if (order[3] == 'S') {
            cout << size << endl;
            continue;
        } else if (order[3] == 'C') {
            cout << capacity << endl;
            continue;
        }
        int value = 0;
        cin >> value;
        if (order[0] == 'a') {
            a[size] = value;
            size++;
            if (capacity == 0) {
                capacity = 10;
            }
            if (size > capacity) {
                capacity += capacity / 2;
            }
        } else if (order[0] == 'g') {
            if (value < 0 || value >= size) {
                cout << -1 << endl;
            } else {
                cout << a[value] << endl;
            } 
        } else {
            int position = 0;
            for (int i = 0; i < size; i++) {
                if (a[i] == value) {
                    size--;
                    for (int j = i; j < size; j++) {
                        a[j] = a[j + 1];
                    }
                    break;
                }
            }
            
        }
    }
}