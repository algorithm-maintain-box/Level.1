#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// DP를 사용하여 순차적으로 확인
int solution(vector<vector<int>> board)
{
    int max_value = 0;
    for (auto row = 0; row < board.size(); row++)
    {
        for (auto column = 0; column < board[0].size(); column++)
        {
            if (board.size() >= 2 || board[0].size() >= 2)
            {
                if (row == 0 || column == 0 || board[row][column] == 0)
                {
                    continue;
                }

                board[row][column] = min(min(board[row][column - 1],
                                             board[row - 1][column]),
                                         board[row - 1][column - 1]) +
                                     1;
            }

            max_value = max(board[row][column], max_value);
        }
    }

    return pow(max_value, 2);
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << " / A : 9" << std::endl;
    std::cout << "Out : " << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << " / A : 4" << std::endl;
    return 0;
}