#include <iostream>//Dijkstra
const int INF = 1145141919;
const int MAXN = 105;

int graph[MAXN][MAXN];
int dist[MAXN];
bool vis[MAXN];

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        graph[x][y] = z;
    }

    int start, end;
    std::cin >> start >> end;

    for (int i = 1; i <= n; ++i)
    {
        dist[i] = graph[start][i];
        vis[i] = false;
    }
    vis[start] = true;

    for (int k = 1; k < n; ++k)
    {
        int u = -1;
        int minDis = INF;
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && dist[i] < minDis)
            {
                minDis = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        vis[u] = true;

        for (int v = 1; v <= n; ++v)
        {
            if (!vis[v] && graph[u][v] != INF && dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    if (dist[end] == INF)
        std::cout << "STOP" << std::endl;
    else
        std::cout << dist[end] << std::endl;

    return 0;
}