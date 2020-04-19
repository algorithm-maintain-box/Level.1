#include <string>
#include <vector>

using namespace std;

int solution(int number, vector<int> firecracker)
{
    int result = 0;

    int affect = firecracker.size();
    for (int i = firecracker.size() - 1; i >= 0; i--)
    {
        auto new_affect = i - firecracker[i];
        if (affect > new_affect)
        {
            if (firecracker[i] == 0 || affect > i)
            {
                result++;
            }
            affect = new_affect;
        }

        if (affect < 0)
        {
            return result;
        }
    }

    return result;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution(4, {0, 1, 0, 5}) << " A : 1" << std::endl;
    std::cout << "MINE : " << solution(2, {0, 0}) << " A : 2" << std::endl;
    std::cout << "MINE : " << solution(10, {1, 1, 3, 0, 0, 0, 2, 1, 0, 3}) << " A : 3" << std::endl;
    return 0;
}