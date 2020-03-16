#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// priority queue를 써야지 됨
int solution(vector<int> scoville, int K)
{
    priority_queue<int,
                   vector<int>,
                   greater<int>>
        q{scoville.begin(),
          scoville.end()};

    int result = 0;
    while (true)
    {
        if (q.top() >= K)
        {
            return result;
        }

        if (q.size() < 2)
        {
            return -1;
        }

        auto smaller = q.top();
        q.pop();

        auto lager = q.top();
        q.pop();

        q.emplace(smaller + lager*2);
        result++;
    }
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({1, 2, 3, 9, 10, 12}, 7) << " A : 2" << std::endl;
    return 0;
}