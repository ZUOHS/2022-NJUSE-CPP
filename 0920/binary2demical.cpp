#include <iostream>

using namespace std;

int main () {
    char ch;
    int sum = 0;
    while (cin.get(ch)) {
        sum *= 2;
        if (ch == '1') {
            sum += 1;
        }
    }
    cout << sum;
}