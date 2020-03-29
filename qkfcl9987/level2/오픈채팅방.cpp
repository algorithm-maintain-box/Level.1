#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    int count = 0;
    int index = 0;
    queue<pair<string, string>> dump1;
    map<string,string> dump2;
    vector<string> dump;
    for (int i = 0; i < record.size(); i++)
    {
        dump.clear();
        index = 0;
        for (int j = 0; j < record[i].size(); j++) 
        {
            if (record[i][j] == ' ' || j + 1 == record[i].size())
            {
                if (j + 1 == record[i].size()) 
                {
                    dump.push_back(record[i].substr(index, record[i].size() - index));
                }
                else 
                {
                    dump.push_back(record[i].substr(index, j - index));
                }
                index = j+1;
            }
        }

        if (dump[0] == "Enter" || dump[0] == "Leave") 
        {
            dump1.push(make_pair(dump[0], dump[1]));
        }
        if (dump[0] != "Leave") 
        {
            if (dump2.find(dump[1]) == dump2.end())
            {
                dump2.insert(make_pair(dump[1],dump[2]));
            }
            else 
            {
                dump2.erase(dump[1]);
                dump2.insert(make_pair(dump[1], dump[2]));
            }
        }
    }
    int dsize = dump1.size();
    string dstring = "";
    for (int i = 0; i < dsize; i++) 
    {
        dstring = dump2.find(dump1.front().second)->second + "님이";
        if (dump1.front().first == "Enter") 
        {
            answer.push_back(dstring + " 들어왔습니다.");
        }
        else 
        {
            answer.push_back(dstring + " 나갔습니다.");
        }
        dump1.pop();
    }

    return answer;
}
