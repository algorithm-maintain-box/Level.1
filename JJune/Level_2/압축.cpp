#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> all_case{};
int pos = 27;

// 못찾는 위치까지 전진후 실패지점에서 후진
vector<int> solution(string msg)
{
    for (auto i = 1; i < 27; i++)
    {
        all_case.emplace(string(1, 'A' + i - 1), i);
    }

    vector<int> answer{};

    string str{msg[0]};
    for (auto i = 1; i < msg.size(); i++)
    {
        str += msg[i];

        // not found
        if (all_case.find(str) == all_case.end())
        {
            all_case.emplace(str, pos++);
            str = str.substr(0, str.size() - 1);
            answer.emplace_back(all_case[str]);
            i--;
            str.clear();
        }
    }

    answer.emplace_back(all_case[str]);
    return answer;
}

#include <iostream>
template <typename T>
void vector_printer(vector<T> vec)
{
    for (auto iter : vec)
    {
        cout << iter << ", ";
    }
    cout << endl;

    all_case.clear();
    pos = 27;
}

#include <iostream>
int main()
{
    vector_printer(solution("KAKAO"));
    std::cout << "11, 1, 27, 15" << std::endl;

    vector_printer(solution("TOBEORNOTTOBEORTOBEORNOT"));
    std::cout << "20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34" << std::endl;

    vector_printer(solution("ABABABABABABABAB"));
    std::cout << "1, 2, 27, 29, 28, 31, 30" << std::endl;

    return 0;
}