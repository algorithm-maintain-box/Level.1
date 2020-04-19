#include <string>

using namespace std;

bool solution(string s1, string s2)
{
    if (s1.size() > s2.size())
    {
        return false;
    }

    for (auto i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i])
        {
            continue;
        }
        else
        {
            if (s1[i - 1] == s2[i])
            {
                i--;
                s2 = s2.erase(i, 1);
            }
            else
            {
                return false;
            }
        }
    }

    auto pos = s2.find(s1);
    if (pos != s2.npos)
    {
        for (auto i = pos + s1.size(); i < s2.size(); i++)
        {
            if (s1[s1.size() - 1] != s2[i])
            {
                return false;
            }
        }
    }

    return true;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution("cookie", "cooookieee") << " A : 1" << std::endl;
    std::cout << "MINE : " << solution("cookie", "cooookieeea") << " A : 0" << std::endl;
    std::cout << "MINE : " << solution("a", "b") << " A : 0" << std::endl;
    std::cout << "MINE : " << solution("a", "a") << " A : 1" << std::endl;
    std::cout << "MINE : " << solution("aaaab", "aaaaaaaaab") << " A : 1" << std::endl;
    return 0;
}