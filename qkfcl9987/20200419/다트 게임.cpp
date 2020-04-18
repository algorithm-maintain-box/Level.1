#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> num;
    int numcount = 0;

    for (int i = 0; i < dartResult.size(); i++) 
    {
        if (isdigit(dartResult[i]) != 0) 
        {
            if (isdigit(dartResult[i + 1]) != 0 && dartResult[i] == '1' && dartResult[i + 1] == '0')
            {
                num.push_back(10);
                i++;
                numcount++;
            }
            else 
            {
                num.push_back((int)dartResult[i] - '0');
                numcount++;
            }
        }
        else if (dartResult[i] == '*') 
        {
            if (numcount > 1) 
            {
                num[numcount - 1] = num[numcount - 1] * 2;
                num[numcount - 2] = num[numcount - 2] * 2;
            }
            else 
            {
                num[numcount - 1] = num[numcount - 1] * 2;
            }
        }
        else if(dartResult[i] == '#')
        {
            num[numcount - 1] = num[numcount - 1] * -1;
        }
        else 
        {
            if (dartResult[i] == 'D') 
            {
                num[numcount - 1] = num[numcount - 1] * num[numcount - 1];
            }
            else if(dartResult[i] == 'T')
            {
                num[numcount - 1] = num[numcount - 1] * num[numcount - 1] * num[numcount - 1];
            }
        }
    }

    for (int i = 0; i < num.size(); i++) 
    {
        answer += num[i];
    }
    return answer;
}