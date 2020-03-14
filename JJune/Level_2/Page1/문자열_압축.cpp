#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<string> check{};
    uint64_t min = s.size();

    for (auto size = 1; size <= s.size(); size++)
    {
        uint64_t res = 0;
        int cnt = 0;

        for (auto i = 0; i < s.size();)
        {
            auto str = s.substr(i, size);
            if (!check.empty() && check.top() == str)
            {
                cnt++;
                i += size;
                continue;
            }

            if (cnt)
            {
                res += check.top().size();
                check.pop();
                res += std::to_string(++cnt).size();
                cnt = 0;
            }

            check.push(str);
            i += size;
        }

        while (!check.empty())
        {
            if (cnt)
            {
                res += std::to_string(++cnt).size();
                cnt = 0;
            }

            res += check.top().size();
            check.pop();
        }

        min = std::min(min, res);
    }

    return min;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
    std::cout << "Out : " << solution("aabbaccc") << std::endl;
    std::cout << "Out : " << solution("ababcdcdababcdcd") << std::endl;
    std::cout << "Out : " << solution("abcabcdede") << std::endl;
    std::cout << "Out : " << solution("abcabcabcabcdededededede") << std::endl;
    std::cout << "Out : " << solution("xababcdcdababcdcd") << std::endl;
    return 0;
}