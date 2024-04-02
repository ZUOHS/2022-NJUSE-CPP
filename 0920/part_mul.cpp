#include <iostream>
#include <string>
#include <vector>
#include<limits.h>

using namespace std;

int main () {
    long result = 1;
    int temp = 0;
    int judge = 0;
    cin >> temp;
    while (cin >> temp) {
        result *= temp;
        if (judge) {
            cout << " ";
        }
        if (result > INT_MAX) {
            cout << -1;
            return 0;
        } else {
            cout << result;
        }
        judge = 1;
    }
}