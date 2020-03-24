#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//구글참조
int solution(vector<vector<int>> board)
{
	int answer = 0;
	int dump = 0;
	for (int i = 1; i < board.size(); i++)
	{
		for (int j = 1; j < board[i].size(); j++)
		{
			if (board[i][j] == 1)
			{
				dump = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
				board[i][j] = dump;
				answer = max(board[i][j], answer);
			}
		}
	}
	if (answer == 0)
	{
		//추가 안하면 오류발생함...
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == 1) {
					answer = 1;
				}
			}
		}
	}
	else
	{
		answer = pow(answer, 2);
	}
	return answer;
}