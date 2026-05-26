#include<iostream>
/*设 ：N = P1 ^ q1 * P2 ^ q2 * … * Pn ^ qn.
则：φ(N) = N * (1-1/P1) * (1-1/P2) * … * (1-1/Pn)*/

// 👆可以记忆的一个求比正整数小的质数个数的方法

int phi(int n){
    int ans=n;
    int x=n;

    for(int p=2;p*p<=x;p++){
        if(x%p==0){//找一个乘一个
            ans=ans/p*(p-1);//先除法以免过大

            while(x%p==0){//和指数无关，找到一个因数就把它构成的因数部分去除掉
                x/=p;
            }
        }
    }

    if(x>1){
        ans=ans/x*(x-1);
    }

    return ans;
}

int main(){
    int N;
    std::cin>>N;

    while(N--){
        int n;
        std::cin>>n;
        std::cout<<phi(n)<<'\n';
    }

    return 0;
}