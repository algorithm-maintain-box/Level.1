#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); i++)
	{
		if (participant[i] != completion[i])
		{
			answer = participant[i];
			break;
		}
	}




	/*for (int i = 0; i <  participant.size(); i++)
	{
		for (int j = 0; j < completion.size(); j++)
		{
			if (completion[j] != "" && participant[i] == completion[j])
			{
				participant[i] = "";
				completion[j] = "";
				break;
			}
		}
		if (participant[i] != "")
		{
			answer = participant[i];
			break;
		}
	}*/

	return answer;
}