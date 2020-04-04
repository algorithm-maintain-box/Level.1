#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int back = 0;
	int front = 0;
	int index = 0;
	int count = 0;
	int len = people.size();
	while (!people.empty())
	{
		back = people.back();
		people.pop_back();
		count++;
		//if (people.empty())
		//{
		//	answer++;
		//	break;
		//}
		if (index >= people.size())
		{
			answer++;
			break;
		}

		if (back + people[index] <= limit)
		{
			answer++;
			//people.erase(people.begin());
			index++;
		}
		else
		{
			answer++;
		}

		if (len - count == index)
		{
			break;
		}
	}

	return answer;
}