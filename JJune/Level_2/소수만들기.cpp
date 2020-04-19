#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    uint16_t res = 0;

    for (auto x = 0; x < nums.size(); x++)
    {
        for (auto y = x + 1; y < nums.size(); y++)
        {
            for (auto z = y + 1; z < nums.size(); z++)
            {
                uint32_t sum = nums[x] + nums[y] + nums[z];

                // 소수 계산
                for (auto i = 2; i < sum; i++)
                {
                    if (!(sum % i))
                    {
                        break;
                    }

                    if (i == (sum-1))
                    {
                        res++;
                    }
                }
            }
        }
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({1, 2, 3, 4}) << std::endl;
    std::cout << "Out : " << solution({1, 2, 7, 6, 4}) << std::endl;
    return 0;
}