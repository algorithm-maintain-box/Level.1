// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    std::vector<int> com{};
    int sum = 0;
    for (auto iter : A)
    {
        sum += iter;
        com.emplace_back(sum);
    }

    int result = std::numeric_limits<int>::max();
    sum = 0;
    for (int i = A.size() - 1; i > 0; i--)
    {
        sum += A[i];
        result = std::min(result, abs(com[i - 1] - sum));
    }

    return result;
}

#include <iostream>
int main()
{
    std::vector<int> vec{3, 1, 2, 4, 3};
    std::cout << solution(vec) << " / A : 1" << std::endl;

    std::vector<int> vec2{3, 1};
    std::cout << solution(vec2) << " / A : 2" << std::endl;
}