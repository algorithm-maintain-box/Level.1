#include <string>
#include <vector>

using namespace std;

int solution(vector<int> s1, vector<int> s2)
{
    for (auto iter1 : s1)
    {
        bool checked = false;
        for (auto iter2 : s2)
        {
            if (iter1 == iter2)
            {
                checked = true;
                break;
            }
        }

        if (!checked)
        {
            return iter1;
        }
    }
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({4,99,2,6,7,13,88,76}, {6,88,13,4,99,2,7}) << " A : 76" << std::endl;
    return 0;
}