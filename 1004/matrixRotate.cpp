#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n = 0;
    int degree = 0;
    cin >> n >> degree;
    degree = degree / 90;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < degree; i++) {
        vector<vector<int>> temp(n, vector<int>(n, 0));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                temp[x][y] = board[n - 1 - y][x];
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                board[x][y] = temp[x][y];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}