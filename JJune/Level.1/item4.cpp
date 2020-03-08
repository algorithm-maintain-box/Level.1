#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    uint32_t res = 0;
    uint16_t increase_num = 1;

    while (increase_num <= n)
    {
        res += (n % increase_num) ? 0 : increase_num;
        increase_num++;
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(5) << std::endl;
    std::cout << "Out : " << solution(12) << std::endl;
    return 0;
}