#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<int>> arr;
    int n;
public:
    Matrix(int size) : n(size)     {arr.resize(n, std::vector<int>(n));}

    void input()
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cin >> arr[i][j];
            }
        }
    }

    int getSum()
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += arr[i][i];
        }
        return sum;
    }
};

int main()
{
    int N;
    std::cin >> N;
    Matrix mat(N);
    mat.input();
    std::cout << mat.getSum();
    return 0;
}