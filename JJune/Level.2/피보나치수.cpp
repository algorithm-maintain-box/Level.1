#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    uint64_t frist = 0;
    uint64_t second = 1;

    for (auto i = 3; i <= n; i++)
    {
        auto thrid = (frist + second) % 1234567;
        frist = second;
        second = thrid;
    }

    return (frist + second) % 1234567;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(3) << std::endl;
    std::cout << "Out : " << solution(5) << std::endl;
    return 0;
}