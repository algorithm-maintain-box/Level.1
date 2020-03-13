#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<string> check{};
    uint64_t res = 0;
    for (auto i = 1; i <= s.size(); i++)
    {
        bool flag = false;
        for (auto k = 0; k < s.size();)
        {
            auto str = s.substr(k, i);
            if (check.top() == str)
            {
                flag = true;
                continue;
            }

            if (flag)
            {
                flag = false;
                res++;
            }

            check.push(s.substr(k, i));
            k = k + i;
        }
    }
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("aabbaccc") << std::endl;
    std::cout << "Out : " << solution("ababcdcdababcdcd") << std::endl;
    std::cout << "Out : " << solution("abcabcdede") << std::endl;
    std::cout << "Out : " << solution("abcabcabcabcdededededede") << std::endl;
    std::cout << "Out : " << solution("xababcdcdababcdcd") << std::endl;
    return 0;
}