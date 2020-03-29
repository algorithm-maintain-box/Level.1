#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int column = 0;
vector<string> all_case{};

// DP
void MakeCase(int start = 0, string pre_case = "")
{
    for (auto i = start; i < column; i++)
    {
        auto new_case = pre_case + to_string(i);
        all_case.emplace_back(new_case);
        MakeCase(i + 1, new_case);
    }
}

void RemoveAll(string const str, int const point_index)
{
    for (auto x = point_index; x < all_case.size(); x++)
    {
        bool check = true;
        for (auto iter : str)
        {
            if (all_case[x].find(iter) == string::npos)
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            all_case.erase(all_case.begin() + x);
            x--;
        }
    }
}

int solution(vector<vector<string>> relation)
{
    column = relation.front().size();
    MakeCase();

    // sort 기준 작은값 true
    sort(all_case.begin(), all_case.end(), [](string a, string b) {
        if (a.size() == b.size())
        {
            return a < b;
        }
        else
        {
            return a.size() < b.size();
        }
    });

    int answer = 0;
    for (auto loop = 0; loop < all_case.size(); loop++)
    {
        auto pk = true;
        // 후보키 가능 유무 확인
        multiset<string> point{};
        for (auto i = 0; i < relation.size(); i++)
        {
            string temp{};
            for (auto k = 0; k < all_case[loop].size(); k++)
            {
                temp += relation[i][all_case[loop][k] - '0'];
            }

            if (point.find(temp) != point.end())
            {
                pk = false;
                break;
            }

            point.insert(temp);
        }

        // 후보키라면 삭제
        if (pk)
        {
            RemoveAll(all_case[loop], loop);
            answer++;
            loop--;
        }
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}}) << " / A : 2" << std::endl;
    return 0;
}