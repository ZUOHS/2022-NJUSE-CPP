#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main () {
    int n = 0; 
    cin >> n;
    vector<vector<vector<int>>> board(n);
    vector<int> height(n, 0);
    vector<int> width(n, 0);
    for (int i = 0; i < n; i++) {
        board[i].resize(10);
        for (int j = 0; j < 10; j++) {
            board[i][j].resize(10);
        }
    }

    for (int i = 0; i < n; i++) {
        int h = 0;
        int w = 0;
        cin >> h >> w;
        height[i] = h;
        width[i] = w;
        int temp = 0;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cin >> temp;
                board[i][j][k] = temp;
            }
        }
    }
    
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        string order = "";
        int left = 0; 
        int right = 0;
        cin >> order >> left >> right;
        
        if (order != "conv") {
            if (height[left] != height[right] || width[left] != width[right]) {
                cout << "error";
            } else {
                for (int j = 0; j < height[left]; j++) {
                    for (int k = 0; k < width[left]; k++) {
                        if (order == "add") {
                            cout << board[left][j][k] + board[right][j][k];
                        } else if (order == "sub") {
                            cout << board[left][j][k] - board[right][j][k];
                        } else {
                            cout << board[left][j][k] * board[right][j][k];
                        }
                        if (k != width[left] - 1) {
                            cout << " ";
                        }
                    }
                    if (i != count - 1 || j != height[left] - 1) {
                        cout << "\n";
                    }
                }
            }
        }
        
        if (order == "conv") {
            if (height[left] < height[right] || width[left] < width[right]) {
                cout << "error";
            } else {
                int h = height[left] - height[right] + 1;
                int w = width[left] - width[right] + 1;
                
                for (int j = 0; j < h; j++) {
                    for (int k = 0; k < w; k++) {
                        int temp = 0;
                        for (int l = 0; l < height[right]; l++) {
                            for (int m = 0; m < width[right]; m++) {
                                temp += board[left][l + j][m + k] * board[right][l][m];
                            }
                        }
                        
                        cout << temp;
                        if (k != w - 1) {
                            cout << " ";
                        }
                    }
                    if (i != count - 1 || j != h - 1) {
                        cout << "\n";
                    }
                }
            }
        }
    }
}