#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n)
{
    uint64_t val = 1;
    while (val <= n)
    {
        if (pow(val, 2) != n)
        {
            val++;
        }
        else
        {
            return pow((val + 1), 2);
        }
    }
    return -1;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(121) << std::endl;
    std::cout << "Out : " << solution(3) << std::endl;
    return 0;
}