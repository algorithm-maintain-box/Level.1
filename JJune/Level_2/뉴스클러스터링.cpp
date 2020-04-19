#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(string str1, string str2)
{
    transform(str1.begin(), str1.end(),
              str1.begin(),
              ::tolower);
    transform(str2.begin(), str2.end(),
              str2.begin(),
              ::tolower);

    auto check = [](string str) {
        multiset<string> str_set{};
        for (auto i = 1; i < str.size(); i++)
        {
            if (isalpha(str[i - 1]) && isalpha(str[i]))
            {
                string temp{};
                temp += str[i - 1];
                temp += str[i];

                str_set.emplace(temp);
            }
        }

        return str_set;
    };

    multiset<string> str1_set = check(str1);
    multiset<string> str2_set = check(str2);

    vector<string> union_vec{};
    set_union(str1_set.begin(),
              str1_set.end(),
              str2_set.begin(),
              str2_set.end(),
              back_inserter(union_vec));

    vector<string> intersection_vec{};
    set_intersection(str1_set.begin(),
                     str1_set.end(),
                     str2_set.begin(),
                     str2_set.end(),
                     back_inserter(intersection_vec));

    double union_size = union_vec.size();
    double intersection_size = intersection_vec.size();

    int pad = 65536;
    if (!union_size && !intersection_size)
    {
        return pad * 1;
    }
    else if (!intersection_size)
    {
        return pad * 0;
    }

    return (intersection_size / union_size) * pad;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("FRANCE", "french") << " / A : 16384" << std::endl;
    return 0;
}