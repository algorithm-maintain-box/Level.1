#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		int index = 0;
		while (sum < n)
		{
			sum += i + index;
			index++;
			if (sum == n)
			{
				answer++;
				break;
			}
		}
	}

	return answer;
}