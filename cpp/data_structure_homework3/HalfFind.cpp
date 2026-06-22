#include <iostream>
#include <vector>

class BinarySearch
{
private:
    std::vector<int> arr;
    int target;
    int count;

public:
    void readData()
    {
        int n;
        std::cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> arr[i];
        }
        std::cin >> target;
        count = 0;
    }

    void search()
    {
        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            count++;
            if (arr[mid] == target)
            {
                return;
            }
            else if (arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        count = -1;
    }

    void print() const
    {
        if (count == -1)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << count << "\n";
        }
    }
};

int main()
{
    BinarySearch bs;
    bs.readData();
    bs.search();
    bs.print();
    return 0;
}