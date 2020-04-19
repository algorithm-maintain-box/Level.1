#include <string>
#include <vector>

std::string solution(int n)
{
    std::string res{};

    // while (n > 2)
    // {
    //     auto rest = n % 3;
    //     n /= 3;

    //     if (rest == 0)
    //     {
    //         rest = 4;
    //         n--;
    //     }

    //     res = std::to_string(rest) + res;
    // }

    // return n ? std::to_string(n) + res : res;

    while (n > 0)
    {
        auto rest = n % 3;
        n = n / 3;

        if (rest == 0)
        {
            n--;
        }

        res = "412"[rest] + res;
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(1) << std::endl;
    std::cout << "Out : " << solution(2) << std::endl;
    std::cout << "Out : " << solution(3) << std::endl;
    std::cout << "Out : " << solution(4) << std::endl;
    std::cout << "Out : " << solution(5) << std::endl;
    std::cout << "Out : " << solution(6) << std::endl;
    std::cout << "Out : " << solution(40) << std::endl;
    return 0;
}