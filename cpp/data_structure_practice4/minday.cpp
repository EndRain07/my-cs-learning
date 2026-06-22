#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

struct Edge{
    int to;
    int w;
};

class Graph{
private:
    std::vector<Edge> g[26];
    int dp[26];
    bool vis[26];

    int id(char c){
        return c-'A';
    }

    int dfs(int u){
        if(vis[u])return dp[u];

        vis[u]=true;
        dp[u]=0;

        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].to;
            int w=g[u][i].w;

            dp[u]=std::max(dp[u],w+dfs(v));
        }

        return dp[u];
    }

public:
    Graph(){
        std::memset(dp,0,sizeof(dp));
        std::memset(vis,false,sizeof(vis));
    }

    void add(char u,char v,int w){
        g[id(u)].push_back({id(v),w});
    }

    int solve(){
        return dfs(id('A'));
    }
};

int main(){
    int n,m;
    std::cin>>n>>m;

    Graph graph;

    for(int i=0;i<m;i++){
        char u,v;
        int w;
        std::cin>>u>>v>>w;
        graph.add(u,v,w);
    }

    std::cout<<graph.solve();

    return 0;
}