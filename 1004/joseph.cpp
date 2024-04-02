#include <iostream>
#include <vector>

using namespace std;

int main () {
    int m = 0;
    int n = 0;
    cin >> n >> m;
    vector <int> list(n, 0);
    for (int i = 0; i < n; i++) {
        list[i] = i;
    }
    int position = 0;
    int size = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (position == size - 1) {
                position = 0;
            } else {
                position++;
            }
        }
        list.erase(list.begin() + position);
        size--;
        if (position == size) {
            position = 0;
        }
    }
    cout << list[0];
}