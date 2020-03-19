#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
    vector<string> vec{};
    for (auto i = 123; i <= 987; i++)
    {
        auto play_case = to_string(i);

        if (play_case.find("0") != string::npos || (play_case[0] == play_case[1] || play_case[1] == play_case[2] || play_case[0] == play_case[2]))
        {
            continue;
        }

        vec.push_back(play_case);
    }

    for (auto iter : baseball)
    {
        auto test_case = to_string(iter[0]);
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            auto strick = 0;
            auto ball = 0;

            for (auto k = 0; k < 3; k++)
            {
                if (test_case[k] == vec[i][k])
                {
                    strick++;
                }
                else if (test_case[k] == vec[i][(k + 1) % 3] || test_case[k] == vec[i][(k + 2) % 3])
                {
                    ball++;
                }
            }

            if (iter[1] != strick || iter[2] != ball)
            {
                vec.erase(vec.begin() + i);
            }
        }
    }

    return vec.size();
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}}) << " A : 2" << std::endl;
    return 0;
}