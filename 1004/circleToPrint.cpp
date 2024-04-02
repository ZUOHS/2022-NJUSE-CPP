#include <iostream>
#include <vector>

using namespace std;

int IsLegal(vector<vector<int>> check, int x, int y);

int main() {
    int m = 0;
    int n = 0;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<int>> check(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int direction = 0;
    int move = 1;
    cout << board[0][0] << " ";
    check[0][0] = 0;
    int x = 0;
    int y = 0;
    while (move < m * n) {
        int judge = 0;
        if (direction % 4 == 0) {
            judge = IsLegal(check, x + 1, y);
        } else if (direction % 4 == 1) {
            judge = IsLegal(check, x, y + 1);
        } else if (direction % 4 == 2) {
            judge = IsLegal(check, x - 1, y);
        } else {
            judge = IsLegal(check, x, y - 1);
        }
        if (judge == 0) {
            direction++;
        } else {
            if (direction % 4 == 0) {
                x++;
            } else if (direction % 4 == 1) {
                y++;
            } else if (direction % 4 == 2) {
                x--;
            } else {
                y--;
            }
            move++;
            cout << board[y][x] << " ";
            check[y][x] = 0;
        }
    }
}

int IsLegal(vector<vector<int>> check, int x, int y) {
    if (x < 0 || y < 0 || x >= check[0].size() || y >= check.size()) {
        return 0;
    } else if (check[y][x] == 0) {
        return 0;
    }
    return 1;
}