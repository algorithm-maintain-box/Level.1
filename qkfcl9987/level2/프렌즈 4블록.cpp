#include <string>
#include <vector>

using namespace std;
//비쥬얼스튜디오로되는데 프로그래머스에서 안됨...
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<vector<char>> board2(m, vector<char>(n, '_'));
	vector<vector<int>> dump(m, vector<int>(n, 0));
	bool flag = true;
	//블록배열만들기
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board2[i][j] = board[i].at(j);
		}
	}

	while (flag)
	{
		flag = false;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (board2[i][j] != '_')
				{
					if (board2[i][j] == board2[i - 1][j] && board2[i - 1][j] == board2[i][j - 1])
					{
						if (board2[i - 1][j - 1] == board2[i - 1][j] && board2[i][j - 1] == board2[i - 1][j - 1])
						{
							if (board2[i - 1][j - 1] == board2[i][j] && board2[i][j - 1] == board2[i][j])
							{
								dump[i][j] = dump[i][j]++;
								dump[i - 1][j] = dump[i - 1][j]++;
								dump[i][j - 1] = dump[i][j - 1]++;
								dump[i - 1][j - 1] = dump[i - 1][j - 1]++;
							}
						}
					}
				}
			}
		}

		for (int q = 0; q < m; q++)
		{
			for (int k = 0; k < n; k++)
			{
				if (dump[q][k] > 0)
				{
					dump[q][k] = 0;
					board2[q][k] = '_';
					answer += 1;
					flag = true;
				}
			}
		}

		for (int t = m - 1; 0 < t; t--)
		{
			for (int w = 0; w < n; w++)
			{
				if (board2[t][w] == '_')
				{
					for (int k = t - 1; -1 < k; k--)
					{
						if (board2[k][w] != '_')
						{
							board2[t][w] = board2[k][w];
							board2[k][w] = '_';
							break;
						}
					}
				}

			}
		}
	}
	return answer;
}