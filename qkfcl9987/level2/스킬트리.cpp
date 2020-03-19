#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	while (skill_trees.size() != 0)
	{
		queue<string> sk;
		for (int i = 0; i < skill.length(); i++)
		{
			string str(1, skill[i]);
			sk.push(str);
		}

		queue<string> skilltree;
		for (int i = 0; i < skill_trees[0].size(); i++)
		{
			string str(1, skill_trees[0].at(i));
			skilltree.push(str);
		}

		int skilltreesize = skilltree.size();
		bool skillflag = true;
		for (int i = 0; i < skilltreesize; i++)
		{
			if (!sk.empty())
			{
				int sksearch = sk.size();
				bool searchflag = false;
				for (int j = 0; j < sk.size(); j++)
				{
					if (sk.front() == skilltree.front())
					{
						searchflag = true;
					}
					string dump = sk.front();
					sk.pop();
					sk.push(dump);
				}

				if (searchflag)
				{
					if (sk.front() == skilltree.front())
					{
						skilltree.pop();
						sk.pop();
					}
					else
					{
						skillflag = false;
						break;
					}
				}
				else
				{
					skilltree.pop();
				}
			}

		}

		if (skillflag)
		{
			answer++;
		}
		skill_trees.erase(skill_trees.begin());
	}


	return answer;
}