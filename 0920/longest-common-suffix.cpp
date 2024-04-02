#include <iostream>
#include <vector>

using namespace std;

int min_length(vector<string>list, int n){
    int min = list[0].size();
    for (int i = 1; i < n; i++) {
        if (list[i].size() < min) {
            min = list[i].size();
        }
    }
    return min;
}

int main() {
    int n = 0;
    cin >> n;
    vector <string> list;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        list.push_back(temp);
    }
    
    int min = min_length(list, n);
    int judege = 1;
    int count = 0;
    for (int i = 1; i <= min; i++) {
        for (int j = 1; j < n; j++) {
            if (list[0][list[0].size() - i] != list[j][list[j].size() - i]) {
                judege = 0;
                break;
            }
        }
        if (judege == 0) {
            count = i - 1;
            break;
        }
        if (i == min) {
            count = i;
        }
    }
    
    if (count > 0) {
        for (int i = count; i > 0; i--) {
            cout << list[0][list[0].size() - i];
        }
    } else {
        cout << "";
    }
}