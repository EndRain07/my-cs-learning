#include<iostream>
#include<string>
#include<sstream>

void integer_num(){
    std::string s;
    getline(std::cin,s);

    std::istringstream ssa(s);
    int a,b;
    ssa>>a>>b;
    std::cout<<s<<a+b;
    
}


int main(){
    integer_num();
}