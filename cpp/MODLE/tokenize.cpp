#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>



std::vector<std::string> tokenize(const std::string& s)
{
    std::vector<std::string> tokens;
    std::string cur;

    for(char c : s)
    {
        if(c == ' ')
            continue;

        if(isdigit(c))
        {
            cur += c;
        }
        else
        {
            if(!cur.empty())
            {
                tokens.push_back(cur);
                cur.clear();
            }

            tokens.push_back(std::string(1, c));
        }
    }

    if(!cur.empty())
        tokens.push_back(cur);

    return tokens;
}