#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
	vector<string> dump;
    vector<string> answerv;
    int index = 0;
    int minute = 0;
    string playm = "";
    int difftime = 0;

    if (m.size() > 1) 
    {
        for (int i = 1; i < m.size(); i++)
        {
            if (m[i] == '#')
            {
                string s(1, tolower(m[i - 1]));
                m.replace(i - 1, 2, s);
            }
        }
    }

	for (int i = 0; i < musicinfos.size(); i++)
	{
        dump.clear();
		index = 0;
        minute = 0;
        playm = "";

		for (int j = 0; j < musicinfos[i].size(); j++) 
		{
            if(musicinfos[i][j] == ',' || j + 1 == musicinfos[i].size())
            {
                if (j + 1 == musicinfos[i].size())
                {
                    dump.push_back(musicinfos[i].substr(index, musicinfos[i].size() - index));
                }
                else
                {
                    dump.push_back(musicinfos[i].substr(index, j - index));
                }
                index = j + 1;
            }
		}

        if (dump[3].size() > 1) 
        {
            for (int j = 1; j < dump[3].size(); j++)
            {
                if (dump[3][j] == '#')
                {
                    string s(1, tolower(dump[3][j - 1]));
                    dump[3].replace(j - 1, 2, s);
                }
            }
        }
       
        minute = stoi(dump[1].substr(3, 2)) - stoi(dump[0].substr(3, 2)) + ((stoi(dump[1].substr(0, 2)) - stoi(dump[0].substr(0, 2))) * 60);
        difftime = minute;
        for (int j = 0; j < difftime; j++)
        {
            if (j >= dump[3].size()) 
            {
                playm += dump[3][j - (dump[3].size() * (j / dump[3].size()))];
            }
            else 
            {
                playm += dump[3][j];
            }

        }

        if (!(playm.find(m) == string::npos) && playm[playm.find(m) + m.size()] != '#')
        {
            if (answerv.empty())
            {
                answerv.push_back(dump[2]);
                answerv.push_back(to_string(minute));
            }
            else if (stoi(answerv[1]) < minute)
            {
                answerv.clear();
                answerv.push_back(dump[2]);
                answerv.push_back(to_string(minute));
            }
        }
	}
    if (!answerv.empty()) 
    {
        answer = answerv[0];
    }
    else 
    {
        answer = "(None)";
    }
    return answer;
}
