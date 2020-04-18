#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> dump;
	for (int i = 0; i < commands.size(); i++)
	{
		dump.clear();
		for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
		{
			dump.push_back(array[j]);
		}
		sort(dump.begin(), dump.end());
		answer.push_back(dump[commands[i][2] - 1]);
	}
	return answer;
}