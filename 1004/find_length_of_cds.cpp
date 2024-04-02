#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int max = 0;
    int count = 1;
    cin >> n;
    int last = 0;
    int temp = 0;
    cin >> last;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (temp < last) {
            count++;
        } else {
            count = 1;
        }
        if (count > max) {
            max = count;
        }
        last = temp;
    }
    cout << max;
}