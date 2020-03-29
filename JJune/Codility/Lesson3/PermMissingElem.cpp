// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(std::vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    double result = 0;
    for (auto i = 0; i < A.size(); i++)
    {
        result = result + i + 1 - A[i];
    }

    return result + A.size() + 1;
}

#include <iostream>
int main()
{
    std::vector<int> vec{2, 3, 1, 5};
    std::cout << solution(vec) << " / A : 4" << std::endl;
}