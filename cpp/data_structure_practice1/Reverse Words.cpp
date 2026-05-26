#include <iostream>
#include <string>
#include <stack>

std::string reverse_words(const std::string& line) {
    std::stack<char> st;
    std::string result;

    for (char ch : line) {
        if (ch == ' ') {
            // 遇到空格：先把前面的单词弹栈输出
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }

            // 原样保留这个空格
            result += ' ';
        } else {
            // 非空格字符入栈
            st.push(ch);
        }
    }

    // 处理行末最后一个单词
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore(); // 清掉 T 后面的换行符

    while (T--) {
        std::string line;
        std::getline(std::cin, line);

        std::cout << reverse_words(line) << '\n';
    }

    return 0;
}








// 下面错误，因为istringstream会忽略空格

/*#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string reverse_one_word(const std::string& word) {
    std::stack<char> st;

    for (char ch : word) {//强化遍历
        st.push(ch);
    }

    std::string result;

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

std::string reverse_words(const std::string& line) {
    std::istringstream iss(line);
    std::string word;
    std::string result;

    bool first = true;

    while (iss >> word) {
        if (!first) {
            result += ' ';
        }

        result += reverse_one_word(word);

        first = false;
    }

    return result;
}

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();//！！！不ignore会残留换行符导致getline到空行

    while (T--) {
        std::string line;
        std::getline(std::cin, line); 
        std::cout << reverse_words(line) <<'\n' ;
    }

    return 0;
}*/