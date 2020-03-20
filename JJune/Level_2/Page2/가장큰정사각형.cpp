#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solution(vector<vector<int>> board)
{
    uint32_t max = 0;
    for (auto iter : board)
    {
        for (auto iter_ : iter)
        {
            iter_ ? max++ : max;
        }
    }

    auto x_max = board[0].size();
    auto y_max = board.size();
    auto square_max_size = floor(sqrt(max));
    
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << " / A : 9" << std::endl;
    std::cout << "Out : " << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << " / A : 4" << std::endl;
    return 0;
}