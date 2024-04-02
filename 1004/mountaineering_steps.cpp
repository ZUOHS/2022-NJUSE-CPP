#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    vector <vector<int>> list (3, vector<int>(100005, 0));
    list[1][0] = 1;
    list[2][0] = 2;
    int count = 1;
    for (int i = 3; i <= n; i++) {
        int up = 0;
        for (int j = 0; j <= count; j++) {
            list[i % 3][j] = (up + list[(i + 2) % 3 ][j] + list[(i + 1) % 3][j]) % 10;
            up = (up + list[(i + 2) % 3][j] + list[(i + 1) % 3][j]) / 10;
        }
        if (list[i % 3][count] > 0) {
            count++;
        }
    }
    for (int i = count - 1; i >= 0; i--) {
        cout << list[n % 3][i];
    }
}