#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j])
			{
				lost[i] = 0;
				reserve[j] = 0;
				answer++;
				break;
			}
		}
	}


	for (int i = 0; i < lost.size(); i++)
	{
		if (lost[i] == 0) continue;
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == 0) continue;
			if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1)
			{
				reserve[j] = 0;
				answer++;
				break;
			}
		}
	}

	return answer;
}