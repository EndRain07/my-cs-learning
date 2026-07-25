#include <iostream>
#include <vector>
#include <algorithm>

class NumSort
{
private:
    std::vector<int> nums;
public:
    void read()
    {
        int n;
        std::cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> nums[i];
        }
    }

    void sortAsc()
    {
        std::sort(nums.begin(), nums.end());
    }

    void print() const
    {
        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            if (i > 0)
                std::cout << " ";
            std::cout << nums[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    NumSort s;
    s.read();
    s.sortAsc();
    s.print();
    return 0;
}