#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

int solution(string str1, string str2)
{
    for (auto i = 0; i < str1.size(); i++)
    {
        str1[i] = tolower(str1[i]);
    }

    for (auto i = 0; i < str2.size(); i++)
    {
        str2[i] = tolower(str2[i]);
    }

    unordered_map<string, int> str1_map{};
    for (auto i = 1; i < str1.size(); i++)
    {
        if (('a' <= str1[i - 1] && 'z' >= str1[i - 1]) &&
            ('a' <= str1[i] && 'z' >= str1[i]))
        {
            string str{};
            str += str1[i - 1];
            str += str1[i];

            str1_map[str]++;
        }
    }

    unordered_map<string, int> str2_map {};
    for (auto i = 1; i < str2.size(); i++)
    {
        if (('a' <= str2[i - 1] && 'z' >= str2[i - 1]) &&
            ('a' <= str2[i] && 'z' >= str2[i]))
        {
            string str{};
            str += str2[i - 1];
            str += str2[i];

            str2_map[str]++;
        }
    }

    unordered_map<string, int> same_map{};
    unordered_map<string, int> min_map{};
    for (auto iter : str1_map)
    {
        same_map[iter.first] = max(iter.second, str2_map[iter.first]);
        min_map[iter.first] = min(iter.second, str2_map[iter.first]==0?std::numeric_limits<int>::max():str2_map[iter.first]);
    }

    return 0;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("FRANCE", "french") << " / A : 3" << std::endl;
    return 0;
}