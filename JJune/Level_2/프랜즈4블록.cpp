#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    // 좌로 보드를 변경함
    vector<vector<int>> new_board(n);
    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (auto j = 0; j < n; j++)
        {
            new_board[j].emplace_back(board[i][j]);
        }
    }

    // vector init with create
    vector<vector<int>> mapping_board(new_board.size(),
                                      vector<int>(new_board[0].size(), 0));
    int answer = 0;

    while (true)
    {
        bool checked = false;
        for (auto i = 1; i < n; i++)
        {
            if (i >= new_board.size())
            {
                break;
            }

            for (auto j = 1; j < m; j++)
            {
                if (j >= new_board[i].size())
                {
                    break;
                }

                if ((new_board[i][j] == new_board[i][j - 1]) &&
                    (new_board[i][j] == new_board[i - 1][j]) &&
                    (new_board[i][j] == new_board[i - 1][j - 1]))
                {
                    mapping_board[i][j] = 1;
                    mapping_board[i][j - 1] = 1;
                    mapping_board[i - 1][j] = 1;
                    mapping_board[i - 1][j - 1] = 1;
                    checked = true;
                }
            }
        }

        if (checked)
        {
            for (auto i = 0; i < new_board.size(); i++)
            {
                for (auto j = 0; j < new_board[i].size(); j++)
                {
                    if (mapping_board[i][j])
                    {
                        new_board[i].erase(new_board[i].begin() + j);
                        mapping_board[i].erase(mapping_board[i].begin() + j);
                        answer++;
                        j--;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << " / A : 14" << std::endl;
    std::cout << "Out : " << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << " / A : 15" << std::endl;
    return 0;
}