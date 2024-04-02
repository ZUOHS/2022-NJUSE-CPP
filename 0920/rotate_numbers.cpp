#include <iostream>
#include <limits.h>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    int judge = 1;
    if (n < 0) {
        n = - n;
        judge = 0;
    }
    
    long result = 0;
    while (n > 0) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    
    if (!judge) {
        result = -result;
    }
    if (result > INT_MAX || result < INT_MIN) {
        cout << -1;
        return 0;
    }
    cout << result;
    return 0;
}