#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<double> stage(N);

	for (int i = 0; i < N; i++)
	{
		double chall = 0;
		double loss = 0;
		for (int j = 0; j < stages.size(); j++)
		{
			if (stages[j] >= i + 1)
			{
				chall++;
			}

			if (stages[j] == i + 1)
			{
				loss++;
			}
		}
		if (chall == 0 || loss == 0)
		{
			stage[i] = 0;
		}
		else
		{
			stage[i] = loss / chall;
		}
	}
	for (int i = 0; i < N; i++)
	{
		double dump = stage[0];
		int count = 0;
		for (int j = 1; j < stage.size(); j++)
		{
			if (dump < stage[j])
			{
				dump = stage[j];
				count = j;
			}
		}
		stage[count] = -1;
		answer.push_back(count + 1);
	}

	return answer;
}