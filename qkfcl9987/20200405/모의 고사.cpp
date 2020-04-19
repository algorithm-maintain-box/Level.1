#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> count(3, 0);
	vector<int> index1 = { 1,2,3,4,5 };
	vector<int> index2 = { 1,3,4,5 };
	int index3 = 0;
	vector<int> index4 = { 3,3,1,1,2,2,4,4,5,5 };
	int index5 = 0;
	for (int i = 0; i < answers.size(); i++)
	{
		if (index1[i % 5] == answers[i]) count[0]++;

		if (i % 2 == 0)
		{
			if (answers[i] == 2) count[1]++;
		}
		else
		{

			if (index2[index3 % 4] == answers[i]) count[1]++;
			index3++;
		}


		if (i < 9)
		{
			index5 = i;
		}
		else
		{
			index5 = i % 10;
		}
		if (index4[index5] == answers[i]) count[2]++;
	}

	for (int i = 0; i < count.size(); i++)
	{
		if (max({ count[0],count[1],count[2] }) == count[i])
		{
			answer.push_back(i + 1);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}