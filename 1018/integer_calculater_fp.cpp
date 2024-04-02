#include <iostream>
#include <string>

using namespace std;

typedef int (*fp) (int left, int right);

int gcd(int left, int right) {
    while(right != 0) {
        int temp = left % right;
        left = right;
        right = temp;
    }
    return left;
}

int add(int left, int right) {
    return left + right;
}

int sub(int left, int right) {
    return left - right;
}

int mul(int left, int right) {
    return left * right;
}

int quo(int left, int right) {
    return left / right;
}

int res(int left, int right) {
    return left % right;
}

int lcm(int left, int right) {
    return left * right / gcd(left, right);
}

int main() {
    int n = 0;
    cin >> n;
    fp function = nullptr;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = 0;
        string op = "";
        cin >> left >> right >> op;
        if (op == "add") {
            function = add;
        } else if (op == "sub") {
            function = sub;
        } else if (op == "mul") {
            function = mul;
        } else if (op == "quo") {
            function = quo;
        } else if (op == "res") {
            function = res;
        } else if (op == "lcm") {
            function = lcm;
        } else if (op == "gcd") {
            function = gcd;
        } else {
            continue;
        }
        cout << function(left, right) << endl;
    }
}