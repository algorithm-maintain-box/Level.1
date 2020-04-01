#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> res{};
    res.emplace_back(0);

    for (auto i = 1; i < heights.size(); i++)
    {
        int point = 0;

        for (auto k = i - 1; k != -1; k--)
        {
            if (heights[i] < heights[k])
            {
                point = k + 1;
                break;
            }
        }

        res.emplace_back(point);
    }

    return res;
}

#include <iostream>
int main()
{
    for (auto iter : solution({6, 9, 5, 7, 4}))
    {
        std::cout << iter;
    }
    std::cout << std::endl;

    for (auto iter : solution({3, 9, 9, 3, 5, 7, 2}))
    {
        std::cout << iter;
    }
    std::cout << std::endl;

    for (auto iter : solution({1, 5, 3, 6, 7, 6, 5}))
    {
        std::cout << iter;
    }
    std::cout << std::endl;

    std::cout << "A : [0,0,2,2,4,4]" << std::endl;
    for (auto iter : solution({3, 6, 3, 3, 1, 2}))
    {
        std::cout << iter;
    }
    std::cout << std::endl;

    std::cout << "A : [0,1,2,0,4]" << std::endl;
    for (auto iter : solution({10, 4, 3, 11, 1}))
    {
        std::cout << iter;
    }
    std::cout << std::endl;
    return 0;
}