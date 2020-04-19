#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement)
{
    stack<std::string> s{};
    uint64_t res = 0;
    bool fired = false;

    for (auto iter : arrangement)
    {
        if (iter == '(')
        {
            fired = false;
            s.emplace("(");
        }

        if (iter == ')')
        {
            s.pop();

            if (fired)
            {
                res += 1;
            }
            else
            {
                fired = true;
                res += s.size();
            }
        }
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << solution("()(((()())(())()))(())") << std::endl;
    std::cout << solution("(()()())") << std::endl;
    return 0;
}