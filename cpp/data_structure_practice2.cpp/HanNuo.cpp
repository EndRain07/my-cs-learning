#include <iostream>
long long step = 0;

//src起点，dest目标，tmp辅助
void hanoi(int n, char src, char dest, char tmp)
{
    if(n == 0)
        return;
    hanoi(n-1, src, tmp, dest);
    step++;
    std::cout << step << " " << n << " " << src << "->" << dest << '\n';
    hanoi(n-1, tmp, dest, src);
}

int main()
{
    int n;
    std::cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}