#include<iostream>
#include<vector>
#include<algorithm>

struct Num{
    int val;
    int sum;
};

int digitsum(int x){
    int sum=0;

    while(x){
        sum+=x%10;
        x/=10;
    }

    return sum;
}

bool cmp(Num a,Num b){
    if(a.sum!=b.sum)return a.sum>b.sum;
    return a.val>b.val;
}

void solve(){
    int n;
    std::cin>>n;

    std::vector<Num> a(n);

    for(int i=0;i<n;i++){
        std::cin>>a[i].val;
        a[i].sum=digitsum(a[i].val);
    }

    std::sort(a.begin(),a.end(),cmp);

    for(int i=0;i<n;i++){
        if(i!=0)std::cout<<' ';
        std::cout<<a[i].val;
    }
}

int main(){
    solve();
    return 0;
}