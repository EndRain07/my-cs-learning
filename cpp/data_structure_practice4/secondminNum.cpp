#include<iostream>
#include<vector>
#include<algorithm>

void solve_one(){
    int n;
    std::cin>>n;

    std::vector<int> a(n);

    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }

    std::sort(a.begin(),a.end());

    int first=a[0];

    for(int i=1;i<n;i++){
        if(a[i]!=first){
            std::cout<<a[i]<<'\n';
            return;
        }
    }

    std::cout<<"NO"<<'\n';
}

int main(){
    int C;
    std::cin>>C;

    while(C--){
        solve_one();
    }

    return 0;
}