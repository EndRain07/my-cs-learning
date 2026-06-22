#include<iostream>//dijkstra
#include<vector>
#include<queue>
#include<climits>

struct Edge{
    int to;
    int w;
};

class Graph{
private:
    int n;
    std::vector<Edge> g[105];

public:
    Graph(int n){
        this->n=n;
    }

    void add(int u,int v,int w){
        g[u].push_back({v,w});
    }

    int dijkstra(int s,int target){
        std::vector<int> dis(n+1,INT_MAX);
        std::vector<bool> vis(n+1,false);

        std::priority_queue<
            std::pair<int,int>,
            std::vector<std::pair<int,int>>,
            std::greater<std::pair<int,int>>
        > q;

        dis[s]=0;
        q.push({0,s});

        while(!q.empty()){
            int u=q.top().second;
            q.pop();

            if(vis[u])continue;
            vis[u]=true;

            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].to;
                int w=g[u][i].w;

                if(dis[u]!=INT_MAX&&dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    q.push({dis[v],v});
                }
            }
        }

        return dis[target];
    }
};

int main(){
    int n,m;
    std::cin>>n>>m;

    Graph graph(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        graph.add(u,v,w);
    }

    int target;
    std::cin>>target;

    std::cout<<graph.dijkstra(1,target);

    return 0;
}