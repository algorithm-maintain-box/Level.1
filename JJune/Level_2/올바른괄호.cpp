#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<string> st{};

    if (s[0] == ')')
    {
        return false;
    }

    for (auto iter : s)
    {
        if (iter == '(')
        {
            st.emplace("(");
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}