#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    int32_t min = (a < b) ? a : b;
    int32_t max = (a > b) ? a : b;

    int64_t res = 0;
    while(max >= min)
    {
        res += max--;
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(3, 5) << std::endl;
    std::cout << "Out : " << solution(3, 3) << std::endl;
    std::cout << "Out : " << solution(5, 3) << std::endl;
    return 0;
}