#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<string>
#include<iomanip>

bool isOperator(const std::string& s){
    return s=="+"||s=="-"||s=="*"||s=="/";
}

double calculate(double a,double b,const std::string& op){
    if(op=="+")return a+b;
    if(op=="-")return a-b;
    if(op=="*")return a*b;
    if(op=="/")return a/b;
    return 0;
}

std::vector<std::string> scan(const std::string& line){//有空格，用stringstream分割
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string temp;

    while(ss>>temp){
        tokens.push_back(temp);
    }

    return tokens;
}

double evaluatePrefix(const std::vector<std::string>& tokens){
    std::stack<double> st;

    for(int i=(int)tokens.size()-1;i>=0;i--){ //前缀表达式要从后往前
        if(isOperator(tokens[i])){//波兰表达式很方便：有符号，其右（后）必定有两个数了(即一定有两个在栈里)
            double a=st.top();
            st.pop();

            double b=st.top();
            st.pop();

            st.push(calculate(a,b,tokens[i]));
        }
        else{
            st.push(std::stod(tokens[i]));
        }
    }

    return st.top();
}

int main(){
    std::string line;
    getline(std::cin,line);

    std::vector<std::string> tokens=scan(line);

    double ans=evaluatePrefix(tokens);

    std::cout<<std::fixed<<std::setprecision(6)<<ans;

    return 0;
}