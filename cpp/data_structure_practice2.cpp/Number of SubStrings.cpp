#include <iostream>
#include <string>

int main()
{
    std::string s;
    while (std::cin >> s)
    {
        long long len = s.size();
        long long ans = len * (len + 1) / 2 + 1;   //公式
        std::cout << ans << std::endl;


    }
    return 0;
}