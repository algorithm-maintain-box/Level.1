// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

std::vector<int> solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    std::vector<int> vec{};

    for (auto i = 0; i < N; i++)
    {
        vec.emplace_back(i + 1);
    }

    return vec;
}

#include <iostream>
int main()
{
    // std::vector<int> vec{3, 1, 2, 4, 3};
    // std::cout << solution(vec) << " / A : 1" << std::endl;

    std::cout << "Test run1 file" << std::endl;
}