#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, char delimiter){
    vector<string> elements;
    string item = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            item += s[i];
        }
        if (s[i] != ' ' && i < s.size() - 1 && s[i + 1] == ' ') {
            elements.push_back(item);
            item = "";
        }
        if (i == s.size() - 1 && s[i] != ' ') {
            elements.push_back(item);
        }
    }
    return elements;
}

int main() {
    string input;
    getline(cin, input);
    int n = 0;
    cin >> n;
    vector<string> inputs = split(input, ' ');
    string lucky = *(inputs.end() - n);
    int result = lucky.size();
    cout << result;
}