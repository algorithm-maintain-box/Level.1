#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> const &numbers, int const &target, uint32_t &result, uint32_t cnt = 0, int sum = 0)
{
    if (cnt == numbers.size())
    {
        if (target == sum)
        {
            result++;
        }
        return;
    }

    dfs(numbers, target, result, cnt + 1, sum + numbers[cnt]);
    dfs(numbers, target, result, cnt + 1, sum - numbers[cnt]);
}

int solution(vector<int> numbers, int target)
{
    uint32_t result = 0;
    dfs(numbers, target, result, 0, 0);
    return result;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({1, 1, 1, 1, 1}, 3) << " / A : 5" << std::endl;
    return 0;
}