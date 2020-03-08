#include <cstdint>
#include <iostream>

using namespace std;

long long solution(int w, int h)
{
    uint64_t max_block = w * h;
    double lean = h / w;

    uint64_t res = 0;
    uint64_t pre_point = 0;
    for (auto i = 1; i <= w; i++)
    {
        for (auto k = 0; k <= h; k++)
        {
            if ((lean * i) > k)
            {
                continue;
            }

            std::cout << "K : " << k << std::endl;
            std::cout << "Count : " << pre_point << std::endl;

            res += k - pre_point;
            pre_point = k;
            break;
        }
    }

    return max_block - res;
}

int main()
{
    std::cout << "Out : " << solution(8, 12) << std::endl;
    return 0;
}