#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int temp = 0;
    int result = 0;
    while(cin >> temp) {
        result ^= temp;
    }
    cout << result;
}