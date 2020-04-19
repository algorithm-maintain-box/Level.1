#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    auto skill_size = skill.size();

    uint8_t res = 0;
    for (auto iter : skill_trees)
    {
        std::size_t pre_pos = 0;
        std::size_t find_pos = 0;

        for (auto i = 0; i < skill_size; i++)
        {
            find_pos = iter.find(skill.at(i));

            if (pre_pos <= find_pos)
            {
                pre_pos = find_pos;
                continue;
            }
            else
            {
                break;
            }
        }

        if (pre_pos <= find_pos)
        {
            res++;
        }
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << std::endl;
    return 0;
}