#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    uint32_t start = 1;

    while (true)
    {
        uint32_t sum = 0;
        for (auto i = start; i <= n; i++)
        {
            sum += i;
            if (sum == n)
            {
                answer++;
                if (start == n)
                {
                    return answer;
                }
                
                start++;
                break;
            }
            else if (sum > n)
            {
                start++;
                break;
            }
        }
    }
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(15) << " A : 4" << std::endl;
    return 0;
}