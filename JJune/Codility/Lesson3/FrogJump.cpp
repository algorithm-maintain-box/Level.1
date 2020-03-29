// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>

int solution(int X, int Y, int D)
{
    // write your code in C++14 (g++ 6.2.0)
    return ceil(double(Y - X) / D);

    // auto result = 0;
    // while (true)
    // {
    //     if (X >= Y)
    //     {
    //         break;
    //     }
    //     X += D;
    //     result++;
    // }

    // return result;
}

#include <iostream>
int main()
{
    std::cout << solution(10, 85, 30) << " / A : 3" << std::endl;
}