#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP 동적 계획법
// row 는 행(가로)이고 column 은 열(세로)
int solution(vector<vector<int>> land)
{
    vector<vector<int>> result{land.size(), vector<int>(4, 0)};
    result[0] = land[0];

    // 제일 큰 값을 1행부터 끝까지 순차적으로 계산하여 따로 저장 (i에 i-1중에 가장 큰값을 구해서 누산)
    for (auto i = 1; i < land.size(); i++)
    {
        for (auto k = 0; k < 4; k++)
        {
            for (auto j = 0; j < 4; j++)
            {
                if (k == j)
                {
                    continue;
                }

                result[i][k] = max(result[i][k], land[i][k] + result[i-1][j]);
            }
        }
    }

    auto max_vec = result[result.size() - 1];
    return *max_element(max_vec.begin(), max_vec.end());
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << " / A : 16" << std::endl;
    std::cout << "Out : " << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}, {100, 0, 9, 8}}) << " / A : 115" << std::endl;
    return 0;
}