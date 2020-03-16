#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    uint32_t w_cnt = 0;
    vector<int> vec{};
    for (auto iter : name)
    {
        if (iter - 'A' <= 'Z' - iter + 1)
        {
            w_cnt += iter - 'A';
            vec.push_back(iter - 'A');
        }
        else
        {
            w_cnt += 'Z' - iter + 1;
            vec.push_back('Z' - iter + 1);
        }
    }

    uint32_t up_res = 0;
    uint32_t w_cnt_temp = vec[0];
    for (auto i = 1; i < name.size(); i++)
    {
        if (w_cnt_temp == w_cnt)
        {
            break;
        }
        up_res++;
        w_cnt_temp += vec[i];
    }

    uint32_t down_res = 0;
    w_cnt_temp = vec[0];
    for (auto i = name.size() - 1; i > 0; i--)
    {
        if (w_cnt_temp == w_cnt)
        {
            break;
        }
        down_res++;
        w_cnt_temp += vec[i];
    }

    return w_cnt + std::min(down_res, up_res);
}


#include <iostream>
int main()
{
    std::cout << "MINE : " << solution("BBABA") << " A : 6" << std::endl;
    std::cout << "MINE : " << solution("BBBAAB") << " A : 8" << std::endl;
    std::cout << "MINE : " << solution("BBAABAA") << " A : 7" << std::endl;
    std::cout << "MINE : " << solution("BBAABBB") << " A : 10" << std::endl;
    std::cout << "MINE : " << solution("AAEAA") << " A : 6" << std::endl;
    std::cout << "MINE : " << solution("BBAABB") << " A : 8" << std::endl;
    return 0;
}