#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;//最小堆
        int val;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> val;
            minHeap.push(val);
        }

        long long wpl = 0;
        while (minHeap.size() > 1)
        {
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();

            int sum = a + b;
            wpl += sum;
            minHeap.push(sum);
        }
        std::cout << wpl << std::endl;
    }
    return 0;
}