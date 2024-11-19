#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkBrackets(const string& str) {
    stack<char> brackets;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty() || !isMatchingPair(brackets.top(), ch)) {
                cout << "Помилка в рядку: " << str.substr(0, i + 1) << endl;
                return;
            }
            brackets.pop();
        }
    }
    cout << (brackets.empty() ? "Рядок коректний!" : "Помилка: залишилися незакриті дужки.") << endl;
}

int main() {
    string str1 = "({x-y-z} * [x + 2y] - (z + 4x));";
    string str2 = "([x-y-z} * [x + 2y) - {z + 4x)];";

    checkBrackets(str1);
    checkBrackets(str2);

    return 0;
}
