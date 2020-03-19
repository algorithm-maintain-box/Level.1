#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	stack<pair<int, int>> truck;
	queue<pair<int, int>> dump;
	int weightcount = 0;

	for (int i = truck_weights.size() - 1; i >= 0; i--)
	{
		truck.push(make_pair(truck_weights[i], 0));
	}

	while (true)
	{
		int dumpsize = dump.size();
		for (int i = 0; i < dumpsize; i++)
		{
			if (dump.front().second >= bridge_length)
			{
				weightcount -= dump.front().first;
				dump.pop();
				continue;
			}
			int weightque = dump.front().first;
			int bridgecount = dump.front().second + 1;
			dump.pop();
			dump.push(make_pair(weightque, bridgecount));
		}

		if (truck.size() > 0 && weightcount + truck.top().first <= weight)
		{
			weightcount += truck.top().first;
			dump.push(make_pair(truck.top().first, truck.top().second + 1));
			truck.pop();
		}
		answer++;

		if (dump.size() == 0 && truck.size() == 0)
		{
			break;
		}
	}
	return answer;
}