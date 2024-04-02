#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int c_count = 0;
    int w_count = 0;
    int l_count = 0;
    string line;
    while (getline(cin, line)) {
        l_count++;
        c_count++;
        c_count += line.size();
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' && i < line.size() - 1 && line[i + 1] == ' ') {
                w_count++;
            }
            if (i == line.size() - 1 && line[i] != ' ') {
                w_count++;
            }
        }
    }
    cout << c_count << " " << w_count << " " << l_count;
}