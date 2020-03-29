#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
    // max 2^20 => uint32_t (2^32)
    double x = min(a, b);
    double y = max(a, b);

    int result = 0;
    while (true)
    {
        result++;

        if (x + 1 == y && ((int)x % 2))
        {
            return result;
        }

        x = ceil(x / 2);
        y = ceil(y / 2);
    }
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(8, 4, 7) << " / A : 3" << std::endl;
    std::cout << "Out : " << solution(8, 1, 8) << " / A : 3" << std::endl;
    return 0;
}