#include <iostream>

int solution(int n)
{
    auto str = std::to_string(n);

    uint64_t res = 0;
    for (auto const iter : str)
    {
        res += std::atoi(&iter);
    }

    return res;
}

int main()
{
    std::cout << "Out : " << solution(123) << std::endl;
    std::cout << "Out : " << solution(987) << std::endl;
    return 0;
}