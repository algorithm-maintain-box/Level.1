#include <string>
#include <vector>
#include <locale>

using namespace std;

string solution(string s)
{
    string answer = "";
#if 0
    string temp{};

    while (!s.empty())
    {
        if (s[0] == ' ')
        {
            answer += ' ';
            s = s.substr(1);
            continue;
        }

        auto pos = s.find_first_of(' ');
        if (pos == string::npos)
        {
            temp = s;
        }
        else
        {
            temp = s.substr(0, pos);
        }

        temp[0] = toupper(temp[0]);
        for (auto i = 1; i < temp.size(); i++)
        {
            temp[i] = tolower(temp[i]);
        }

        answer += temp;
        temp.clear();
        if (pos == string::npos)
        {
            break;
        }
        s = s.substr(pos);
    }

#else

    answer += toupper(s[0]);
    for (auto i = 1; i < s.size(); i++)
    {
        answer += s[i - 1] == ' ' ? toupper(s[i]) : tolower(s[i]);
    }

#endif
    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("3people unFollowed me") << " / A : 3people Unfollowed Me" << std::endl;
    std::cout << "Out : " << solution("for the last week") << " / A : For The Last Week" << std::endl;
    std::cout << "Out : " << solution("a") << " / A : A" << std::endl;
    std::cout << "Out : " << solution("aA") << " / A : Aa" << std::endl;
    return 0;
}