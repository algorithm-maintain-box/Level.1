#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    uint32_t res = 0;
    string input {to_string(x)};

    for (auto const iter : input)
    {
        res += atoi(&iter);
    }

    return x % res ? false : true;
}

#include <iostream>
int main()
{
    cout << "Out :" << solution(10) << endl;
    cout << "Out :" << solution(12) << endl;
    cout << "Out :" << solution(11) << endl;
    cout << "Out :" << solution(13) << endl;
    return 0;
}