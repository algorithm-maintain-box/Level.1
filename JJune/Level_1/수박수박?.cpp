#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string const str1 = "수";
    string const str2 = "박";

    string res{};
    uint16_t cnt = 1;

    while (cnt <= n)
    {
        if (cnt++ % 2)
        {
            res += str1;
        }
        else
        {
            res += str2;
        }
    }

    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(3) << std::endl;
    return 0;
}