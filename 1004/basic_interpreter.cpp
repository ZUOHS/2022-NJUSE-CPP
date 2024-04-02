#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, char delimiter){
    vector<string> elements;
    string item = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != delimiter) {
            item += s[i];
        }
        if (s[i] != delimiter && i < s.size() - 1 && s[i + 1] == delimiter) {
            elements.push_back(item);
            item = "";
        }
        if (i == s.size() - 1 && s[i] != delimiter) {
            elements.push_back(item);
        }
    }
    return elements;
}

int find_it(vector<string> variables, string key, int count) {
    for (int i = 0; i < count; i++) {
        string temp = variables[i] + "\r";
        if (variables[i].compare(key) == 0 || temp.compare(key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int number = 0;
    cin >> number;
    string useless;
    getline(cin, useless);

    vector<string> variables(number, "0");
    vector<int> value(number, 0);
    int count = 0;
    for (int i = 0; i < number; i++) {
        string input;
        getline(cin, input);
        vector<string> inputs = split(input, ' ');
        int length = inputs.size();
        int size = inputs[length - 1].size() - 1;
        if (length == 2) {
            int position = find_it(variables, inputs[1], count);
            if (position != -1) {
                cout << value[position] << endl;
            } else {
                cout << "error" << endl;
                exit(0);
            }
        } else if (length == 3) {
            int right = find_it(variables, inputs[2], count);
            int left = find_it(variables, inputs[0], count);
            if (left == -1) {
                variables[count] = inputs[0];
                if (right == -1) {
                    if (inputs[2].at(0) < '0' || inputs[2].at(0) > '9') {
                        cout << "error";
                        exit(0);
                    }
                    value[count] = stoi(inputs[2]);
                } else {
                    value[count] = value[right];
                }
                count++;
            } else {
                if (right == -1) {
                    if (inputs[2].at(0) < '0' || inputs[2].at(0) > '9') {
                        cout << "error";
                        exit(0);
                    }
                    value[left] = stoi(inputs[2]);
                } else {
                    value[left] = value[right];
                }
            }
        } else {
            int target = find_it(variables, inputs[0], count);
            int left = 0;
            if (find_it(variables, inputs[2], count) == -1) {
                if (inputs[2].at(0) < '0' || inputs[2].at(0) > '9') {
                        cout << "error";
                        exit(0);
                    }
                left = stoi(inputs[2]);
            } else {
                left = value[find_it(variables, inputs[2], count)];
            }
            int right = 0;
            if (find_it(variables, inputs[4], count) == -1) {
                if (inputs[4].at(0) < '0' || inputs[4].at(0) > '9') {
                        cout << "error";
                        exit(0);
                    }
                right = stoi(inputs[4]);
            } else {
                right = value[find_it(variables, inputs[4], count)];
            }
            
            int result = 0;
            if (inputs[3] == "+") {
                result = left + right;
            } else if (inputs[3] == "-") {
                result = left - right;
            } else if (inputs[3] == "*") {
                result = left * right;
            } else {
                if (right == 0) {
                    cout << "error";
                    exit(0);
                }
                result = left / right;
            }
            if (target == -1) {
                variables[count] = inputs[0];
                value[count] = result;
                count++;
            } else {
                variables[target] = inputs[0];
                value[target] = result;
            }
        }
    }
}