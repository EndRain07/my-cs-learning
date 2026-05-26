#include<iostream>
/*设 ：N = P1 ^ q1 * P2 ^ q2 * … * Pn ^ qn.
则：φ(N) = N * (1-1/P1) * (1-1/P2) * … * (1-1/Pn)*/

long long phi(long long n){
    long long ans=n;
    long long x=n;

    for(long long p=2;p*p<=x;p++){
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
    long long n;

    while(std::cin>>n){
        if(n==0) break;
        std::cout<<phi(n)<<'\n';
    }

    return 0;
}