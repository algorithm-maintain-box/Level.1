// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    auto result = 0;

    for (auto iter : A)
    {
        result ^= iter;
    }

    return result;
}

#include <iostream>
int main()
{
    std::vector<int> vec{9, 3, 9, 3, 9, 7, 9};
    std::cout << solution(vec) << std::endl;
}