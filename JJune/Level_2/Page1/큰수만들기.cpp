#include <string>
#include <vector>

using namespace std;

// 앞에서부터 하나씩 비교하며 작은수 지우기
string solution(string number, int k)
{
    while (k)
    {
        for (auto i = 0; i < number.size(); i++)
        {
            if (i + 1 < number.size() && number[i] >= number[i + 1])
            {
                continue;
            }
            else
            {
                number.erase(number.begin() + i);
                k--;
                break;
            }
        }
    }

    return number;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution("1924", 2) << " A : 94" << std::endl;
    std::cout << "MINE : " << solution("1231234", 3) << " A : 3234" << std::endl;
    std::cout << "MINE : " << solution("4177252841", 4) << " A : 775841" << std::endl;

    return 0;
}