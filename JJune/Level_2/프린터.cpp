#include <string>
#include <vector>
#include <algorithm>

int solution(std::vector<int> priorities, int location)
{
    // uint16_t point = 0;
    // uint16_t num = 1;

    // while (true)
    // {
    //     int max = 0;
    //     uint16_t max_point = 0;

    //     for (auto i = point; i < priorities.size(); i++)
    //     {
    //         if (priorities[i] > max)
    //         {
    //             max = priorities[i];
    //             max_point = i;
    //         }
    //     }

    //     for (auto i = 0; i < point; i++)
    //     {
    //         if (priorities[i] > max)
    //         {
    //             max = priorities[i];
    //             max_point = i;
    //         }
    //     }

    //     if (location == max_point)
    //     {
    //         return num;
    //     }
    //     else
    //     {
    //         point = max_point;
    //         priorities[max_point] = 0;
    //         max = max_point = 0;
    //         num++;
    //     }
    // }

    int max_value = *std::max_element(priorities.begin(), priorities.end());
    uint16_t count = 0;

    while (true)
    {
        for (auto i = 0; i < priorities.size(); i++)
        {
            if (priorities[i] == max_value)
            {
                count++;

                if (location == i)
                {
                    return count;
                }

                priorities[i] = 0;
                max_value = *std::max_element(priorities.begin(), priorities.end());
            }
        }
    }
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({2, 1, 3, 2}, 2) << std::endl;
    std::cout << "Out : " << solution({1, 1, 9, 1, 1, 1}, 0) << std::endl;
    return 0;
}