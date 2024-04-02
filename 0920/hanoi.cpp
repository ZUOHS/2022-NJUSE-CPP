#include <iostream>

using namespace std;

int hanoi(int m);

int main () {
    int n = 0;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum * 2;
        sum += 1;
    }
    cout << sum;
}