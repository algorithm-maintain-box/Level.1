// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

int solution(std::vector<int> &A, int K, int L)
{
    int result = 0;
    // write your code in C++14 (g++ 6.2.0)
    if (static_cast<std::size_t>(K + L) > A.size())
    {
        return -1;
    }
    std::size_t max_val = std::max(K, L);
    std::size_t min_val = std::min(K, L);

    int max_sum = 0;
    int index = 0;
    for (std::size_t i = min_val - 1; i < A.size(); i++)
    {
        int new_val = 0;
        for (std::size_t j = 0; j < min_val; j++)
        {
            new_val += A[i - j];
        }

        if (max_sum < new_val)
        {
            index = i;
            max_sum = new_val;
        }
    }

    for (std::size_t i = 0; i < min_val; i++)
    {
        A[index - i] = 0;
    }
    result += max_sum;

    max_sum = 0;
    for (std::size_t i = max_val - 1; i < A.size(); i++)
    {
        int new_val = 0;
        for (std::size_t j = 0; j < max_val; j++)
        {
            new_val += A[i - j];
        }

        if (max_sum < new_val)
        {
            index = i;
            max_sum = new_val;
        }
    }

    return result += max_sum;
}

#include <iostream>
int main()
{
    std::vector<int> vec{6, 1, 4, 6, 3, 2, 7, 4};
    std::cout << solution(vec, 3, 2) << " / A : 24" << std::endl;

    std::vector<int> vec2{6, 1, 4, 6, 3, 2, 7, 4};
    std::cout << solution(vec2, 2, 3) << " / A : 24" << std::endl;

    std::vector<int> vec3{1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << solution(vec3, 6, 3) << " / A : 63" << std::endl;

    std::vector<int> vec4{9, 3, 5, 3, 4, 5, 8};
    std::cout << solution(vec4, 3, 2) << " / A : 30" << std::endl;

    std::vector<int> vec5{500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};
    std::cout << solution(vec5, 3, 2) << " / A : 2500" << std::endl;
}