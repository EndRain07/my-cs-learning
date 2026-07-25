#include <iostream>//Kruskal
#include <vector>
#include <algorithm>

const int MAXN = 55;
int fa[MAXN];

struct Edge
{
    int u, v, w;
};

int find(int x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

bool cmp(const Edge& a, const Edge& b)
{
    return a.w < b.w;
}

int main()
{
    int n;
    std::cin >> n;
    int graph[MAXN][MAXN];
    std::vector<Edge> edges;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    std::sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < n; ++i)
    {
        fa[i] = i;
    }

    int sum = 0;
    int cnt = 0;
    int total = n - 1;

    for (const Edge& e : edges)
    {
        int fu = find(e.u);
        int fv = find(e.v);
        if (fu != fv)
        {
            fa[fv] = fu;  // !!!:u起点v终点，如果根不同，则之间无通路，可连，同时终点的根更新为起点的根
            sum += e.w;
            cnt++;
            if (cnt == total)
            {
                break;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}