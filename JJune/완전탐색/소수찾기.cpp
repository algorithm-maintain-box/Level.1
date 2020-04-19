#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//에라토스테네스의 체
int solution(string numbers)
{
    vector<int> vec{};
    for (auto iter : numbers)
    {
        vec.push_back(stoi(string(1, iter)));
    }

    // 가장 큰 값 계산
    sort(vec.begin(),
         vec.end(),
         greater<int>());

    int max = 0;
    for (auto i = 0; i < vec.size(); i++)
    {
        max += vec[i] * pow(10, vec.size() - 1 - i);
    }

    // 큰 값까지 모든 케이스 계산
    vector<bool> val_vec{};
    val_vec.emplace_back(false);
    val_vec.emplace_back(false);
    for (auto i = 2; i <= max; i++)
    {
        bool is_prime = true;
        for (auto k = 2; k <= sqrt(i); k++)
        {
            if ((i % k) == 0)
            {
                is_prime = false;
                break;
            }
        }

        val_vec.emplace_back(is_prime);
    }

    // 모든 케이스에서 카드로 구성가능한 소수인지 확인
    int res = 0;
    for (auto i = 2; i <= max; i++)
    {
        if (val_vec[i])
        {
            string temp_numbers = numbers;
            string str{to_string(i)};
            bool have = true;

            for (auto i = 0; i < str.size(); i++)
            {
                auto pos = temp_numbers.find(str[i]);
                if (pos != string::npos)
                {
                    temp_numbers.erase(pos, 1);
                    continue;
                }

                have = false;
                break;
            }

            if (have)
            {
                res++;
            }
        }
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution("2") << " A : 1" << std::endl;
    std::cout << "MINE : " << solution("17") << " A : 3" << std::endl;
    std::cout << "MINE : " << solution("011") << " A : 2" << std::endl;
    std::cout << "MINE : " << solution("7843") << " A : 12" << std::endl;
    return 0;
}