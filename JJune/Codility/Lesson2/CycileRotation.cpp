// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K)
{
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty())
    {
        return {};
    }
    
    K %= A.size();

    std::vector<int> result {};

    for (auto i = A.size() - K; i < A.size(); i++)
    {
        result.emplace_back(A[i]);
    }

    for (auto i = 0; i < A.size() - K; i++)
    {
        result.emplace_back(A[i]);
    }

    return result;
}

int main()
{
    std::vector<int> vec {};
    solution(vec, 4);
}