#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int GoLeft(string code, int position);
int GoRight(string code, int position);

int main() {
    int count = 0;
    string code = "";
    int position = 0;
    getline(cin, code);
    vector<int> list(1003, 0);
    int pointer = 0;
    char c1 = ' ';
    char c2 = ' ';
    while (position != code.size()) {
        string order = code.substr(position, 1);
        if (order == ">") {
            pointer++;
        } else if (order == "<") {
            pointer--;
        } else if (order == "+") {
            list[pointer]++;
        } else if (order == "-") {
            list[pointer]--;
        } else if (order == ",") {
            if (scanf("%c", &c1) != EOF) {
                int temp = c1;
                list[pointer] = temp;
            } else {
                list[pointer] = 0;
            }
        } else if (order == ".") {
            c2 = list[pointer];
            cout << c2;
        } else if (order == "[" && list[pointer] == 0) {
            position = GoRight(code, position);
        } else if (order == "]" && list[pointer] != 0) {
            position = GoLeft(code, position);
        }
        position++;
    }
}

int GoLeft(string code, int position) {
    int count = 1;
    for (int i = position - 1; i >= 0; i--) {
        if (code.substr(i, 1) == "]") {
            count++;
        } else if (code.substr(i, 1) == "[") {
            count--;
        }
        if (count == 0) {
            return i;
        }
    }
}

int GoRight(string code, int position) {
    int count = 1;
    for (int i = position + 1; i < code.size() - 1; i++) {
        if (code.substr(i, 1) == "[") {
            count++;
        } else if (code.substr(i, 1) == "]") {
            count--;
        }
        if (count == 0) {
            return i;
        }
    }
}