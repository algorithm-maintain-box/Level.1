#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    priority_queue<int, vector<int>> supply;

    int result = 0;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        if (dates[j] == i)
        {
            supply.push(supplies[j]);
            if (j < supplies.size())
            {
                j++;
            }
        }

        if (stock == 0)
        {
            stock += supply.top();
            supply.pop();
            result++;
        }
        stock--;
    }
    return result;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(4, {4, 10, 15}, {20, 5, 10}, 30) << " A : 2" << std::endl;
    std::cout << "Out : " << solution(4, {1, 2, 3, 4}, {10, 40, 20, 30}, 100) << " A : 4" << std::endl;
    return 0;
}