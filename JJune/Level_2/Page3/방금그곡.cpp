#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos)
{
    for (auto i = 0; i < m.size(); i++)
    {
        if (m[i] == '#')
        {
            m[i - 1] = tolower(m[i - 1]);
            m.erase(i, 1);
            i--;
        }
    }

    string pick_name{"(None)"};
    std::size_t pick_size{};

    // for (auto iter : musicinfos)
    for (auto k = 0; k < musicinfos.size(); k++)
    {
        // parsing
        uint32_t run_time = 0;
        string name{};
        string context{};
        {
            uint16_t pos = musicinfos[k].find_first_of(",");
            auto start_time = musicinfos[k].substr(0, pos);
            musicinfos[k] = musicinfos[k].substr(pos + 1);

            pos = musicinfos[k].find_first_of(",");
            auto end_time = musicinfos[k].substr(0, pos);
            musicinfos[k] = musicinfos[k].substr(pos + 1);

            run_time = (stoi(end_time.substr(0, 2)) - stoi(start_time.substr(0, 2))) * 60 + stoi(end_time.substr(3)) - stoi(start_time.substr(3));

            pos = musicinfos[k].find_first_of(",");
            name = musicinfos[k].substr(0, pos);
            context = musicinfos[k].substr(pos + 1);

            for (auto i = 0; i < context.size(); i++)
            {
                if (context[i] == '#')
                {
                    context[i - 1] = tolower(context[i - 1]);
                    context.erase(i, 1);
                    i--;
                }
            }
        }

        if (run_time > context.size())
        {
            uint16_t repeat = run_time / context.size();
            uint16_t remain = run_time % context.size();

            for (auto i = 1; i < repeat; i++)
            {
                context += context;
            }

            for (auto i = 0; i < remain; i++)
            {
                context += context[i];
            }
        }
        else
        {
            context = context.substr(0, run_time);
        }

        // check
        std::size_t ck_pos = 0;
        if ((ck_pos = context.find(m)) != context.npos)
        {
            if (pick_size < context.size())
            {
                pick_name = name;
                pick_size = context.size();
            }
        }
    }

    return pick_name;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("ABCDEFG", {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << " / A : HELLO" << std::endl;
    std::cout << "Out : " << solution("CC#BCC#BCC#BCC#B", {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"}) << " / A : FOO" << std::endl;
    std::cout << "Out : " << solution("ABC", {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << " / A : WORLD" << std::endl;

    return 0;
}