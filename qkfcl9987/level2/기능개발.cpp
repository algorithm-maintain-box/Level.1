#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<pair<int, int>> q;

	for (int i = 0; i < progresses.size(); i++)
	{
		q.push(make_pair(progresses[i], speeds[i]));
	}

	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			pair<int, int> n = q.front();
			q.pop();
			n.second += speeds[i];
			q.push(n);
		}

		int returncount = 0;
		int quecount = q.size();
		for (int i = 0; i < quecount; i++)
		{
			if ((q.front().first + q.front().second) >= 100)
			{
				q.pop();
				speeds.erase(speeds.begin());
				returncount++;
			}
		}

		if (returncount != 0)
		{
			answer.push_back(returncount);
		}
	}

	return answer;
}