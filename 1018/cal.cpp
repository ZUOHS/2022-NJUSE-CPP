#include <cmath>
#include <iostream>

using namespace std;

int main () {
    int key = 0;
    int length = 0;
    cin >> key >> length;
    cout << ((int)abs(3 * pow(key, 3) + 5 * pow(key, 2) + 7 * key + 11)) % length;
}