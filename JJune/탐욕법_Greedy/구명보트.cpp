#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end(), less<int>());

    auto k = people.size() - 1;
    for (auto i = 0; i <= k; i++)
    {
        if (i==k)
        {
            answer++;
            break;
        }

        if (people[i] + people[k] <= limit)
        {
            k--;
        }
        else
        {
            i--;
            k--;
        }
        answer++;
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({70, 50, 80, 50}, 100) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({70, 80, 50}, 100) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({10, 10, 10, 10, 10, 10}, 60) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({10, 10, 10, 10, 10, 10}, 50) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({20, 30, 70, 70, 80}, 100) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({50, 50, 60, 60}, 100) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution({10, 20, 30, 40, 50, 60, 70, 80, 90}, 100) << " A : 5" << std::endl;
    return 0;
}