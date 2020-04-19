#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    auto cal = n;
    uint32_t cnt = 0;
    while (cal)
    {
        if (cal % 2)
        {
            cnt++;
        }
        else
        {
        }
        cal /= 2;
    }
    cout << endl;

    for (auto i = n + 1;; i++)
    {
        auto result = i;
        auto result_cnt = 0;
        while (result)
        {
            if (result % 2)
            {
                result_cnt++;
            }
            result /= 2;
        }

        if (cnt == result_cnt)
        {
            return i;
        }
    }
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(78) << " A : 83" << std::endl;
    std::cout << "Out : " << solution(15) << " A : 23" << std::endl;
    return 0;
}