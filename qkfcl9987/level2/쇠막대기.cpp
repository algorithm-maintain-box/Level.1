#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int laser = 0;
    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement.at(i) == '(' && arrangement.at(i + 1) == ')')
        {
            laser++;
            if (i != 0)
            {
                for (int j = i - 1; 0 <= j; j--)
                {
                    if (arrangement.at(j) == '(')
                    {
                        answer++;
                    }
                    else
                    {
                        answer--;
                    }
                }
            }
        }
    }
    return answer + ((arrangement.size() - laser * 2) / 2);
}