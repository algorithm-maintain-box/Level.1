#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(priorities[i], i));
    }

    while (!q.empty())
    {
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        bool outflag = false;

        for (int i = 0; i < priorities.size(); i++)
        {
            if (f < priorities[i])
            {
                outflag = true;
                break;
            }
        }

        if (outflag)
        {
            q.push(make_pair(f, s));
            int t = priorities[0];
            priorities.erase(priorities.begin() + 0);
            priorities.push_back(t);
        }
        else
        {
            answer++;
            priorities.erase(priorities.begin() + 0);
            if (s == location)
                break;
        }
    }

    return answer;
}