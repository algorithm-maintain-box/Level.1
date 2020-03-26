#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
#if 1
    vector<string> vec{};
    for (auto iter : numbers)
    {
        vec.push_back(to_string(iter));
    }

    sort(vec.begin(),
         vec.end(),
         [](string a, string b) {
             return a + b > b + a ? true : false;
         });

    if (vec[0] == "0")
    {
        return "0";
    }

    string result{};
    for (auto iter : vec)
    {
        result += iter;
    }

#else
    string result{};
    sort(numbers.begin(), numbers.end());

    do
    {
        string temp{};
        for (auto i = 0; i < numbers.size(); i++)
        {
            temp += to_string(numbers[i]);
        }

        result = max(result, temp);
    } while (next_permutation(numbers.begin(), numbers.end()));

#endif
    return result;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({0, 0, 0, 0, 0}) << " A : 0" << std::endl;
    std::cout << "MINE : " << solution({98, 9, 91, 9}) << " A : 999891" << std::endl;
    std::cout << "MINE : " << solution({6, 10, 2}) << " A : 6210" << std::endl;
    std::cout << "MINE : " << solution({3, 30, 34, 5, 9}) << " A : 9534330" << std::endl;
    return 0;
}