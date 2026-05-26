#include <iostream>
#include <string>
#include <stack>
#include <cctype>//用isdigit / isspace

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

std::string infix_to_postfix(const std::string& expr) {
    std::stack<char> ops;
    std::string result;

    for (std::size_t i = 0; i < expr.size(); ++i) {
        char ch = expr[i];

        if (std::isspace(ch)) {
            continue;
        }

        // 遇到数字，直接加入表达式(while处理多位数)
        if (std::isdigit(ch)) {
            while (i < expr.size() && std::isdigit(expr[i])) {
                result += expr[i];
                ++i;
            }

            result += ' ';
            --i;//!!!!因为原式没有空格，while后停留在第一个非数字，然后下一次for会多一个，需要回退
        }

        else if (ch == '(') {
            ops.push(ch);
        }

        // 遇到右括号，把栈中运算符一直弹出，直到遇到左括号
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                result += ops.top();
                result += ' ';
                ops.pop();
            }

            if (!ops.empty() && ops.top() == '(') {
                ops.pop();
            }
        }

        // 遇到运算符，先弹出优先级更高或相等的栈顶运算符，再把当前符入栈
        else if (is_operator(ch)) {
            while (!ops.empty()
                && is_operator(ops.top())//这里是为了防止栈顶是'('
                && priority(ops.top()) >= priority(ch)) {
                result += ops.top();
                result += ' ';
                ops.pop();
            }

            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        result += ops.top();
        result += ' ';
        ops.pop();
    }

    return result;
}

int main() {
    std::string expr;
    std::getline(std::cin, expr);

    std::cout << infix_to_postfix(expr) << '\n';

    return 0;
}