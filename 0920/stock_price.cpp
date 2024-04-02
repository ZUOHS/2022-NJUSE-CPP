#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int t = 0;
    int rest = 0;
    for (int i = 0; i < n; i++) {
        if ((4 + i) * (i + 1) / 2 > n && (3 + i) * i / 2 <= n) {
            t = i - 1;
            rest = n - (3 + i) * i / 2;
            break;
        }
    }
    int sum = 2 + t * (t + 1) / 2;
    if (rest > 0) {
        sum += rest - 2;
    }
    cout << sum;
}