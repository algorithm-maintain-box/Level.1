#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    auto pick = nums.size() / 2;

    sort(nums.begin(), nums.end(), greater<int>());

    auto cnt = 1;
    uint32_t type = nums[0];
    for (auto iter : nums)
    {
        if (iter != type)
        {
            type = iter;
            cnt++;
        }
    }

    return pick > cnt ? cnt : pick;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({3, 1, 2, 3}) << " / A : 2" << std::endl;
    std::cout << "Out : " << solution({3, 3, 3, 2, 2, 4}) << " / A : 3" << std::endl;
    std::cout << "Out : " << solution({3, 3, 3, 2, 2, 2}) << " / A : 2" << std::endl;
    return 0;
}