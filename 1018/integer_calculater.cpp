#include <iostream>
#include <string>

using namespace std;

int GCD(int left, int right) {
    while(right != 0) {
        int temp = left % right;
        left = right;
        right = temp;
    }
    return left;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = 0;
        string op = "";
        cin >> left >> right >> op;
        if (op == "add") {
            cout << left + right << endl;
        } else if (op == "sub") {
            cout << left - right << endl;
        } else if (op == "mul") {
            cout << left * right << endl;
        } else if (op == "quo") {
            cout << left / right << endl;
        } else if (op == "res") {
            cout << left % right << endl;
        } else if (op == "lcm") {
            cout << left * right / GCD(left, right) << endl;
        } else if (op == "gcd") {
            cout << GCD(left, right) << endl;
        }
    }
}