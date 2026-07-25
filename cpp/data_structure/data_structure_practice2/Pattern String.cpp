#include <iostream>
#include <string>

int findPos(const std::string& s, const std::string& t)
{
    int lenS = s.size();
    int lenT = t.size();
    if(lenT > lenS)
        return 0;

    for(int i = 0; i <= lenS - lenT; ++i) //只用找到lenS-lenT
    {
        if(s[i]==t[0]){
        int flag = 1;     
        for(int j = 0; j < lenT; ++j)
        {
            if(s[i+j] != t[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    std::string str, pat;
    std::cin >> str >> pat;
    std::cout << findPos(str, pat);
    return 0;
}