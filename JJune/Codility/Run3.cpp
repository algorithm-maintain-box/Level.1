// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>
#include <vector>
#include <set>

std::vector<std::string> all_case{};

void make_case(std::string &s)
// void MakeCase(std::string &s, int start = 0, std::string pre_case = "")
{
    for (std::size_t i = 0; i < s.size(); i++)
    {
        std::string new_case = std::string(1, s[i]);
        all_case.emplace_back(new_case);

        for (std::size_t j = i + 1; j < s.size(); j++)
        {
            new_case += s[j];
            all_case.emplace_back(new_case);
        }
        // auto new_case = pre_case + s[i];
        // all_case.emplace_back(new_case);
        // MakeCase(s, i + 1, new_case);
    }
}

int solution(std::string &S)
{
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    make_case(S);

    std::multiset<char> st{};
    for (auto iter : all_case)
    {
        for (auto ch : iter)
        {
            if (st.empty())
            {
                st.insert(ch);
            }
            // find
            else if (st.find(ch) != st.end())
            {
                st.erase(ch);
            }
            else
            {
                st.insert(ch);
            }
        }

        result += st.size();
        st.clear();
    }

    return result;
}

#include <iostream>
int main()
{
    std::string str1{"ACAX"};
    std::cout << solution(str1) << " / A : 16" << std::endl;
    all_case.clear();

    std::string str2{"CODILITY"};
    std::cout << solution(str2) << " / A : 96" << std::endl;
}