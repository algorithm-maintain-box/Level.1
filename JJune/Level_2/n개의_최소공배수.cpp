#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

int solution(vector<int> arr)
{

    int result = arr[0];
    for (auto i = 1; i < arr.size(); i++)
    {
        result = lcm(result, arr[i]);
    }

    return result;

    // uint8_t max = 0;

    // for (auto &iter : arr)
    // {
    //     if (max < iter)
    //     {
    //         max = iter;
    //     }
    // }

    // uint32_t res = max;
    // while (true)
    // {
    //     for (auto i = 0; i < arr.size(); i++)
    //     {
    //         if (res % arr[i])
    //         {
    //             break;
    //         }

    //         if (i == (arr.size() - 1))
    //         {
    //             return res;
    //         }
    //     }

    //     res++;
    // }

    // return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({2, 6, 8, 14}) << std::endl;
    std::cout << "Out : " << solution({1, 2, 3}) << std::endl;
    return 0;
}