#include <iostream>
#include <vector>
#include <algorithm>

class GraphDFS
{
private:
    int vertexNum;
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    std::vector<int> dfsSeq;

    void dfs(int u)
    {
        visited[u] = true;
        dfsSeq.push_back(u);
        for (int v : adj[u])//强化遍历
        {
            if (!visited[v])
            {
                dfs(v);
            }
        }
    }

public:
    void init()
    {
        int edgeNum;
        std::cin >> vertexNum >> edgeNum;
        adj.resize(vertexNum);
        visited.assign(vertexNum, false);
        dfsSeq.clear();

        for (int i = 0; i < edgeNum; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 升序
        for (int i = 0; i < vertexNum; ++i)
        {
            std::sort(adj[i].begin(), adj[i].end());
        }
    }

    void startDFS()
    {
        dfs(0);
    }

    void printSeq() const
    {
        for (std::size_t i = 0; i < dfsSeq.size(); ++i)
        {
            if (i > 0)
                std::cout << " ";
            std::cout << dfsSeq[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    GraphDFS g;
    g.init();
    g.startDFS();
    g.printSeq();
    return 0;
}