#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numbers)
{
    map<int, vector<string>> m{};

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (!numbers[i])
        {
            m[i].push_back("0");
            continue;
        }

        if (numbers[i] < 10)
        {
            m[numbers[i]].push_back(to_string(numbers[i]));
        }
        else if (numbers[i] < 100)
        {
            m[numbers[i] / 10].push_back(to_string(numbers[i]));
        }
        else
        {
            m[numbers[i] / 100].push_back(to_string(numbers[i]));
        }
    }

    string result{};
    for (auto i = 9; i > 0; i--)
    {
        sort(m[i].begin(), m[i].end());
        for (auto iter : m[i])
        {
            result += iter;
        }
    }

    return result;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({98, 9, 91, 93, 90}) << " A : 999891" << std::endl;
    std::cout << "MINE : " << solution({6, 10, 2}) << " A : 6210" << std::endl;
    std::cout << "MINE : " << solution({3, 30, 34, 5, 9}) << " A : 9534330" << std::endl;
    return 0;
}