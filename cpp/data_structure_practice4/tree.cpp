#include<iostream>
#include<string>
#include<unordered_map>

struct Edge{
    std::string fa;
    int len;
};

class Kingdom{
private:
    std::unordered_map<std::string,Edge> mp;

    int cnt(int n){
        return (1<<(n+1))-2;
    }

public:
    void read(int n){
        int m=cnt(n);

        for(int i=0;i<m;i++){
            std::string fa,son;
            int len;

            std::cin>>fa>>son>>len;

            mp[son]={fa,len};
        }
    }

    int getdistance(std::string city){
        int ans=0;

        while(mp.find(city)!=mp.end()){
            ans+=mp[city].len;
            city=mp[city].fa;
        }

        return ans;
    }
};

int main(){
    int n;
    std::cin>>n;

    Kingdom kingdom;
    kingdom.read(n);

    std::string target;
    std::cin>>target;

    std::cout<<kingdom.getdistance(target);

    return 0;
}