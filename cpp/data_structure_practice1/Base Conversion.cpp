#include<iostream>
#include<string>

void base_exchange(int N,int R){
    std::string ans="";
    while(N){
        int tmp;
        tmp=N%R;
        N/=R;
        if(tmp<=9) ans+=(char)(tmp+(int)'0');
        else ans+=(char)(tmp-10+(int)'A');
    }//得到的是反序

    for(int i=ans.length()-1;i>=0;i--){
        std::cout<<ans[i];
    }

    
}



int main(){
    int N,R;
    std::cin>>N>>R;

    base_exchange(N,R);
}