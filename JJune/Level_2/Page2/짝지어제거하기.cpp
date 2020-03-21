#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st {};
    for (auto i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.emplace(s[i]);
        }
        else
        {
            if (st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.emplace(s[i]);
            }
        }
    }

    return st.empty();

    // while (!s.empty())
    // {
    //     for (auto i = 1; i < s.size(); i++)
    //     {
    //         if (s[i - 1] == s[i])
    //         {
    //             s.erase(s.begin() + i - 1, s.begin() + i + 1);
    //         }

    //         if (s.size() - 1 == i)
    //         {
    //             return 0;
    //         }
    //     }
    // }

    // return 1;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("baabaa") << " / A : 1" << std::endl;
    std::cout << "Out : " << solution("cdcd") << " / A : 0" << std::endl;
    return 0;
}