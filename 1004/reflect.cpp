#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<vector<int>> board(10, vector<int>(10, 0));
    int m = 0;
    int n = 0;
    int result = 0;
    cin >> m >> n;
    double botton = 10 * m / (1.0 * n);
    double right = 10 - (10 - botton) * n / (m * 1.0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if ((i + 1) * m > n * j && i * m < n * (j + 1)) {
                result += board[i][j];
            } else if (j - botton >= 0 && (10 - i) * m > (j - botton) * n && (9 - i) * m < (j - botton + 1) * n) {
                result += board[i][j];
            }  if (right - i - 1 >= 0 && (right - i - 1) * m < n * (10 - j) && (right - i) * m > (9 - j) * n) {
                result += board[i][j];
            }
        }
    }
    cout << result;
}