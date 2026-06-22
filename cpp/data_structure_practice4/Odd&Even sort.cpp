#include<iostream>
#include<vector>
#include<algorithm>

void read(std::vector<int>& odd,std::vector<int>& even){
    for(int i=0;i<10;i++){
        int x;
        std::cin>>x;

        if(x%2==1)odd.push_back(x);
        else even.push_back(x);
    }
}

void sortnum(std::vector<int>& odd,std::vector<int>& even){
    std::sort(odd.begin(),odd.end(),std::greater<int>());
    std::sort(even.begin(),even.end());
}

void print(const std::vector<int>& odd,const std::vector<int>& even){
    bool first=true;

    for(int i=0;i<odd.size();i++){
        if(!first)std::cout<<' ';
        std::cout<<odd[i];
        first=false;
    }

    for(int i=0;i<even.size();i++){
        if(!first)std::cout<<' ';
        std::cout<<even[i];
        first=false;
    }
}

int main(){
    std::vector<int> odd;
    std::vector<int> even;

    read(odd,even);
    sortnum(odd,even);
    print(odd,even);

    return 0;
}