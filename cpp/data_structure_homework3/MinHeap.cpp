#include <iostream>
#include <vector>

class MinHeap
{
private:
    std::vector<int> heap;
    int n;

    void downAdjust(int idx)
    {
        int temp = heap[idx];
        for (int i = idx * 2 + 1; i < n; i = i * 2 + 1)
        {
            if (i + 1 < n && heap[i + 1] < heap[i])
                i++;
            if (temp <= heap[i])
                break;
            heap[idx] = heap[i];
            idx = i;
        }
        heap[idx] = temp;
    }

public:
    void input()
    {
        std::cin >> n;
        heap.resize(n);
        for (int i = 0; i < n; ++i)
            std::cin >> heap[i];
    }

    void buildHeap()
    {
        for (int i = n / 2 - 1; i >= 0; --i) //最后一个非叶子节点开始下沉
            downAdjust(i);
    }

    void print() const
    {
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
                std::cout << " ";
            std::cout << heap[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    MinHeap h;
    h.input();
    h.buildHeap();
    h.print();
    return 0;
}