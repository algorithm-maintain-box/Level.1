#include<string>
#include <iostream>

using namespace std;

bool answer = true;
int dump = 0;
for (int i = 0; i < s.length(); i++)
{
    if (s.at(i) == '(')
    {
        dump++;
    }
    else if (s.at(i) == ')')
    {
        if (dump <= 0)
        {
            return false;
        }
        else
        {
            dump--;
        }
    }
}
if (dump == 0)
{
    return true;
}
else
{
    return false;
}