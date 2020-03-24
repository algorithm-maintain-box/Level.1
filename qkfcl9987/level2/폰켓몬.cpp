#include <vector>
using namespace std;

int solution(vector<int> nums)
{
	int answer = nums.size() / 2;
	vector<int> dump;
	bool flag = false;
	dump.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++)
	{
		flag = false;
		for (int j = 0; j < dump.size(); j++)
		{
			if (dump[j] == nums[i])
			{
				flag = true;
			}
		}
		if (!flag) dump.push_back(nums[i]);
	}
	if (answer > dump.size()) answer = dump.size();
	return answer;
}