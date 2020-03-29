#include <string>
#include <vector>

using namespace std;

// 진법 변환
// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
string solution(int n, int t, int m, int p)
{
    std::vector<std::string> alpha{"A", "B", "C", "D", "E", "F"};
    std::vector<std::string> vec{};
    vec.reserve(t);
    vec.emplace_back("0");

    auto cnt = t * m - 1;
    auto value = 1;
    while (cnt >= vec.size())
    {
        auto res = value;
        std::vector<std::string> temp_vec{};
        while (res)
        {
            auto temp = res % n;
            temp_vec.push_back((temp >= 10 ? alpha[temp - 10] : to_string(temp)));
            res /= n;
        }

        for (auto iter = temp_vec.rbegin(); iter != temp_vec.rend(); iter++)
        {
            vec.emplace_back(*iter);
        }

        value++;
    }

    string answer = "";
    p -= 1;
    for (auto i = 0; i < t; i++)
    {
        answer += vec[p];
        p += m;
    }

    return answer;
}

void temp()
{
    int a = 10;
    string temp = to_string(a);        // 10
    char temp2 = 'z' - a;              // p
    int temp3 = 'z' - a;               // 112
    string temp4 = string(1, 'z' - a); // p
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(2, 4, 2, 1) << " / A : 0111" << std::endl;
    std::cout << "Out : " << solution(16, 16, 2, 1) << " / A : 02468ACE11111111" << std::endl;
    std::cout << "Out : " << solution(16, 16, 2, 2) << " / A : 13579BDF01234567" << std::endl;
    return 0;
}