#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer[i] += " ";
		}
	}

	for (int i = 0; i < n; i++)
	{
		int count = n - 1;
		while (arr1[i] != 0)
		{
			if (arr1[i] % 2 != 0)
			{
				answer[i][count] = '#';
			}
			count--;
			arr1[i] = arr1[i] / 2;
		}
		count = n - 1;
		while (arr2[i] != 0)
		{
			if (arr2[i] % 2 != 0)
			{
				answer[i][count] = '#';
			}
			count--;
			arr2[i] = arr2[i] / 2;
		}
	}
	return answer;
}