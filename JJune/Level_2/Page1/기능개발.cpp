#include <string>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> res{};

    int day = 0;
    int max_day = 0;
    for (auto i = 0; i < progresses.size(); i++)
    {
        day = (100 - progresses[i]) / speeds[i];

        if (res.empty() || max_day < day)
        {
            res.emplace_back(1);
        }
        else
        {
            ++res.back();
        }

        if (max_day < day)
        {
            max_day = day;
        }
    }

    return res;
}

#include <iostream>
int main()
{
    for (auto iter : solution({93, 30, 55}, {1, 30, 5}))
    {
        std::cout << "Out : " << iter << std::endl;
    }
    return 0;
}