#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(string &begin, string &target, set<string> &st, int &answer)
{
    if (begin == target)
    {
        return;
    }

    for (auto i = 0; i < begin.size(); i++)
    {
        if (begin[i] == target[i])
        {
            continue;
        }
        else
        {
            string temp = begin;
            temp[i] = target[i];
            if (st.find(temp) != st.end())
            {
                begin[i] = target[i];
                answer++;
                return dfs(begin, target, st, answer);
            }
        }
    }

    answer = begin.size() + 1;
}

int solution(string begin, string target, vector<string> words)
{
    set<string> st{};
    for (auto iter : words)
    {
        st.insert(iter);
    }

    if (st.find(target) == st.end())
    {
        return 0;
    }

    int result = numeric_limits<int>::max();
    for (auto i = 0; i < begin.size(); i++)
    {
        int answer = 0;

        if (begin[i] == target[i])
        {
            continue;
        }
        else
        {
            string temp = begin;
            temp[i] = target[i];
            if (st.find(temp) != st.end())
            {
                answer++;
                dfs(temp, target, st, answer);
                result = min(result, answer);
            }
        }
    }

    return result;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << " / A : 4" << std::endl;
    return 0;
}