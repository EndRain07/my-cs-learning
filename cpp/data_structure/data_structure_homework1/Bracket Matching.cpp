#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getType(char c) {
    if (c == '(' || c == ')') return 1;
    if (c == '[' || c == ']') return 2;
    if (c == '{' || c == '}') return 3;
    return 0;
}

bool match(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

int check() {
    string s;
    cin>>s;
    stack<char> st;
    for (char c : s) {  //学习：强化遍历
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return getType(c);
            }
            if (!match(st.top(), c)) {
                return getType(st.top());
            }
//自己的优化：右侧多了右不匹配，不相同左不匹配？
            st.pop();
        }
    }

    if (!st.empty()) {
        return getType(st.top());
    }

    return 0;
}

int main() {
    

    int a=check();

    if (a == 0) {
        cout << "YES";
    } else {
        cout << "NO" << a;
    }

    return 0;
}