#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
    // uuid, name
    unordered_map<string, string> name_history{};
    // cmd, uuid
    vector<pair<string, string>> history{};

    for (auto iter : record)
    {
        // 0 : cmd / 1 : uuid / 2 : name
        vector<string> info{};
        auto pos = iter.find_first_of(' ');
        while (pos != string::npos)
        {
            info.emplace_back(iter.substr(0, pos));
            iter = iter.substr(pos + 1);
            pos = iter.find_first_of(' ');
        }
        info.emplace_back(iter);

        if (info[0] == "Enter")
        {
            if (name_history.find(info[1]) != name_history.end())
            {
                name_history.at(info[1]) = info[2];
            }
            else
            {
                name_history.emplace(info[1], info[2]);
            }

            history.emplace_back(info[0], info[1]);
        }
        else if (info[0] == "Leave")
        {
            history.emplace_back(info[0], info[1]);
        }
        else if (info[0] == "Change")
        {
            if (name_history.find(info[1]) != name_history.end())
            {
                name_history.at(info[1]) = info[2];
            }
        }
    }

    vector<string> answer{};
    for (auto iter : history)
    {
        answer.emplace_back(name_history.at(iter.second) + "님이" + (iter.first == "Enter" ? " 들어왔습니다." : " 나갔습니다."));
    }

    return answer;
}

#include <iostream>
template <typename T>
void vector_printer(vector<T> vec)
{
    for (auto iter : vec)
    {
        cout << iter << endl;
    }
    cout << endl;
}

int main()
{
    vector_printer(solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"}));
    cout << "Prodo님이 들어왔습니다." << endl;
    cout << "Ryan님이 들어왔습니다." << endl;
    cout << "Prodo님이 나갔습니다." << endl;
    cout << "Prodo님이 들어왔습니다." << endl;
    return 0;
}