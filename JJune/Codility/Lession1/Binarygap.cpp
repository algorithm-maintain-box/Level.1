// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>

int solution(int N)
{
    // write your code in C++14 (g++ 6.2.0)
    int max = 0;
    std::stack<int> st{};
    int cnt = 0;

    while (N)
    {
        if (N % 2)
        {
            st.emplace(1);
            max = std::max(max, cnt);
            cnt = 0;
        }
        else
        {
            if (!st.empty())
            {
                cnt++;
            }
        }
        N /= 2;
    }

    return max;
}

int main()
{
    solution(1);
}