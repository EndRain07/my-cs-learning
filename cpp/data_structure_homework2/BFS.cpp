#include <iostream>
#include <queue>
#include <vector>
#include <string>

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

//BFS
int bfs(int sx, int sy, int n, int m, const std::vector<std::string>& map)
{
    //0未走，1已走
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    // 队列存坐标(行,列)
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    int step = 0; 
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            if (map[x][y] == 'E')
                return step;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m
                    && vis[nx][ny] == 0 && map[nx][ny] != '#')
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        step++; 
    }
    return -1;
}

int main()
{
    int T;
    std::cin >> T;
    for(int i=0;i<T;i++)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> maze(n);
        int start_x, start_y;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> maze[i];//新学：行输入(无空格)
            for (int j = 0; j < m; ++j)
            {
                if (maze[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        int res = bfs(start_x, start_y, n, m, maze);
        std::cout << res << std::endl;
    }
    return 0;
}

//可能还有优化：直接判断E周围是否是死路，是就直接-1