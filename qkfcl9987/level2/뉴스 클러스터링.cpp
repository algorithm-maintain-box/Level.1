#include <string>
#include <vector>
using namespace std;
int solution(string str1, string str2) {
	int answer = 0;
	vector<string> st1;
	vector<string> st2;
	vector<string> _Intersection;
	//공백 특문 제거,대문자 변경
	int count = 0.1;
	string dump;
	for (int i = 0; i < str1.size(); i++)
	{
		if (isalpha(static_cast<int>(str1[i])))
		{
			count++;
			string s(1, toupper(str1[i]));
			dump += s;
			if (count == 2)
			{
				st1.push_back(dump);
				count = 0;
				dump = "";
				i--;
			}
		}
		else
		{
			count = 0;
			dump = "";
		}
	}
	count = 0;
	dump = "";
	for (int i = 0; i < str2.size(); i++)
	{
		if (isalpha(static_cast<int>(str2[i])))
		{
			count++;
			string s(1, toupper(str2[i]));
			dump += s;
			if (count == 2)
			{
				st2.push_back(dump);
				count = 0;
				dump = "";
				i--;
			}
		}
		else
		{
			count = 0;
			dump = "";
		}
	}

	int allCount = st1.size() + st2.size();
	int sameCount = 0;

	for (int i = 0; i < st1.size(); i++)
	{
		for (int j = 0; j < st2.size(); j++)
		{
			if (st1.at(i).compare(st2.at(j)) == 0)
			{
				sameCount++;
				st2.erase(st2.begin() + j);
				break;
			}
		}
	}

	answer = 65536;
	if (sameCount > 0)
	{
		float f = (float)sameCount / (allCount - sameCount);
		f *= 65536;
		answer = f;
	}

	if (sameCount == 0)
	{
		answer = 0;
	}

	if (allCount - sameCount == 0)
	{
		answer = 65536;
	}

	return (int)answer;
}