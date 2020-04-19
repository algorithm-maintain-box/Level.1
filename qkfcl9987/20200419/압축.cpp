#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> map;
    int count = 26;
    for (int i = 65; i < 91; i++)
    {
        char ctr = i;
        string s(1,ctr);
        map.insert(make_pair(s,i - 64));
    }

    for (int i = 0; i < msg.size(); i++) 
    {
        char ctr1 = msg[i];
        string s1(1, ctr1);
        
        for (int j = i+1; j < msg.size(); j++) 
        {
            char ctr2 = msg[j];
            string s2(1, ctr2);
            s2 = s1 + s2;
            if (map.find(s2) == map.end())
            {
                i = j - 1;
                break;
            }
            else 
            {
                s1 = s2;
                if (j == msg.size() - 1) 
                {
                    i = j;
                    break;
                } 
            }
        }

        if (i < msg.size() - 1)
        {
            char ctr2 = msg[i + 1];
            string s2(1, ctr2);
            s2 = s1 + s2;
            map.insert(make_pair(s2, count + 1));
            count++;
        }

        answer.push_back(map.find(s1)->second);
    }

    return answer;
}