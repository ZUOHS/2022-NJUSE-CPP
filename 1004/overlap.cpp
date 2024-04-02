#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int IsOverlapped(map<int, string> myMap, int left, int right);

int main () {
    int n = 0;
    cin >> n;
    map<int, string> myMap;
    vector<int> lap(n, 0);
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        myMap.insert(map<int, string>::value_type(i, temp));
    }
    int move = 0;
    while (1) {
        int count = 0;
        int max = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            lap[i] = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    lap[i] += IsOverlapped(myMap, i, j);
                }
            }
            count += lap[i];
            if (lap[i] > max) {
                max = lap[i];
                maxCount = i;
            }
        }
        
        if (count == 0) {
            cout << move;
            return 0;
        }
        myMap[maxCount] = "00:00-00:00";
        move++;
    }
}

int IsOverlapped(map<int, string> myMap, int left, int right) {
    int left_start = stoi(myMap[left].substr(0, 2)) * 60 + stoi(myMap[left].substr(3, 2));
    int left_end = stoi(myMap[left].substr(6, 2)) * 60 + stoi(myMap[left].substr(9, 2));
    int right_start = stoi(myMap[right].substr(0, 2)) * 60 + stoi(myMap[right].substr(3, 2));
    int right_end = stoi(myMap[right].substr(6, 2)) * 60 + stoi(myMap[right].substr(9, 2));
    if (right_start < left_end && right_end > left_start) {
        return 1;
    } 
    return 0;
}