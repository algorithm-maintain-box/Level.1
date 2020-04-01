#include <string>
#include <vector>

using namespace std;

int column = 0;
int row = 0;

bool dfs(vector<vector<int>> &computers, int start_pos = 0)
{
    // 현재 노드 검사
    if (!computers[start_pos][start_pos])
    {
        return false;
    }
    computers[start_pos][start_pos] = 0;

    // 연결된 노드 검사
    for (auto i = 0; i < row; i++)
    {
        // 연결된 노드가 있으면 dfs 탐색 시작
        if (computers[start_pos][i])
        {
            dfs(computers, i);
        }
    }

    return true;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    row = computers.size();
    column = computers.front().size();

    // row를 순회하면서 dfs 탐색
    for (auto i = 0; i < row; i++)
    {
        if (dfs(computers, i))
        {
            answer++;
        }
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << " / A : 2" << std::endl;
    std::cout << "Out : " << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << " / A : 1" << std::endl;
    std::cout << "Out : " << solution(4, {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}}) << " / A : 2" << std::endl;
    return 0;
}