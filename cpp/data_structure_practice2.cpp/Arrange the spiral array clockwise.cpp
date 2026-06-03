#include <iostream>
#include <vector>

class Spiral
{
private:
    int n;
    std::vector<std::vector<int>> mp;
    // xy标错了，手动记录：0右1下2左3上
    const int dx[4] = {0, 1, 0 ,-1};
    const int dy[4] = {1, 0, -1, 0};
public:
    Spiral(int size):n(size), mp(size, std::vector<int>(size,0)){}

    void create()
    {
        int x=0,y=0;    
        int dir=0;         
        int num=1;        
        int max = n*n;     

        while(num <= max) 
        {
            mp[x][y] = num++; 

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //越界已填换方向
            if(nx<0||nx>=n||ny<0||ny>=n||mp[nx][ny]!=0)
                dir = (dir+1)%4;
            x += dx[dir];
            y += dy[dir];
        }
    }

    void print()
    {
        for(int i=0;i<n;i++)        
        {
            for(int j=0;j<n;j++)    
            {
                if(j>0) std::cout<<" ";
                std::cout<<mp[i][j];
            }
            std::cout<<'\n';        
        }
    }
};

int main()
{
    int N;
    std::cin>>N;
    Spiral obj(N);   
    obj.create();    
    obj.print();     
    return 0;
}