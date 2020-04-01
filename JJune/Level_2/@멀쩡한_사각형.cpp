#include <cstdint>
#include <algorithm>

using namespace std;

long long solution(int w, int h)
{
    uint64_t gcd = 0;

    // 유클리우드 알고리즘
    int a = w;
    int b = h;
    if (a > b)
    {
        swap(a, b);
    }

    while (a)
    {
        auto n = b%a;
        b=a;
        a=n;
    }

    gcd = b;

    uint64_t max = (uint64_t)w * h;
    return max - (w + h - gcd);
}

#include <iostream>
int main()
{
    std::cout << solution(8, 12) << std::endl;
    return 0;
}