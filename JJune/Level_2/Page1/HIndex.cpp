#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> citations)
{
    priority_queue<int, vector<int>>
        q{citations.begin(), citations.end()};

    for (auto i = 1; i <= citations.size(); i++)
    {
        auto memtion = q.top();
        q.pop();

        if (memtion >= i && q.top() <= i)
        {
            return i;
        }
        else if (memtion < i)
        {
            return memtion;
        }
    }

    return citations.size();
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({3, 3, 3, 3}) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({3, 0, 6, 1, 5}) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({22,42}) << " A : 2" << std::endl;
    std::cout << "MINE : " << solution({20,19,18,1}) << " A : 3" << std::endl;
    return 0;
}