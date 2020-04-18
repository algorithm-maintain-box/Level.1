#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<string> combination;
int column = 0;
vector<string> answercom;

void Combination(int k = 0, string temp = "") {
	for (int i = k; i < column; i++) {
		temp += to_string(i);
		bool flag = true;
		for (int j = 0; j < answercom.size(); j++)
		{
			if (temp.find(answercom[j]) != string::npos) flag = false;
		}
		if (flag) combination.push_back(temp);

		Combination(i + 1, temp);
		temp = temp.substr(0, temp.length() - 1);
	}
}
bool compare(string& a, string& b) {
	if (a.length() != b.length())     return a.length() < b.length();
	return a < b;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	column = relation[0].size();

	vector<int> dump(relation[0].size(), 0);

	for (int i = 0; i < relation.size(); i++)
	{
		for (int j = 0; j < relation[i].size(); j++)
		{
			for (int k = 0; k < relation.size(); k++)
			{
				if (k == i) continue;
				if (relation[i][j] == relation[k][j])
				{
					dump[j]--;
					break;
				}
			}
		}
	}
	for (int i = 0; i < dump.size(); i++)
	{
		if (dump[i] == 0)
		{
			answercom.push_back(to_string(dump[i]));
			answer++;
		}
	}
	Combination();
	sort(combination.begin(), combination.end(), compare);
	map<string, int>aa;
	for (int i = 0; i < combination.size(); i++)
	{
		aa.clear();
		for (int t = 0; t < relation.size(); t++)
		{
			string dump = "";
			for (int j = 0; j < combination[i].size(); j++)
			{
				dump += relation[t][(int)combination[i][j]];
			}
			aa[dump];
		}
		if (aa.size() == relation.size())
		{
			bool flag = true;
			for (int t = 0; t < answercom.size(); t++)
			{
				if (combination[i].find(answercom[t]) != string::npos) flag = false;
			}
			if (flag)
			{
				answer++;
				answercom.push_back(combination[i]);

			}
		}



	}


	return answer;
}