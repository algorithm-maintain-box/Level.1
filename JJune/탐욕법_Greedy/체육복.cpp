#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    vector<int> vec(n + 2, 0);

    for (auto iter : lost)
    {
        vec[iter]--;
    }

    for (auto iter : reserve)
    {
        vec[iter]++;
    }

    for (auto i = 1; i <= n; i++)
    {
        if (vec[i] == -1)
        {
            if (vec[i - 1] == 1)
            {
                vec[i] = 0;
                vec[i - 1] = 0;
            }
            else if (vec[i + 1] == 1)
            {
                vec[i] = 0;
                vec[i + 1] = 0;
            }
            else
            {
                answer--;
            }
        }
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution(5, {2, 4}, {1, 3, 5}) << " A : 5" << std::endl;
    std::cout << "MINE : " << solution(5, {2, 4}, {3}) << " A : 4" << std::endl;
    std::cout << "MINE : " << solution(3, {3}, {1}) << " A : 2" << std::endl;
    std::cout << "MINE : " << solution(8, {3, 7}, {2, 4}) << " A : 7" << std::endl;
    std::cout << "MINE : " << solution(8, {4, 5}, {5, 6}) << " A : 7" << std::endl;
    std::cout << "MINE : " << solution(3, {1, 2, 3}, {1, 2, 3}) << " A : 3" << std::endl;
    std::cout << "MINE : " << solution(5, {2, 3, 4}, {3, 4, 5}) << " A : 4" << std::endl;
    return 0;
}