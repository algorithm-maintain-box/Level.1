#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    string num;
    string diffnum;
    int s, b;
    bool flag = true;
    for (int t = 123; t <= 987; t++)
    {
        num = to_string(t);
        //같은 숫자 제외,0 제외
        if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2] || num[0] == '0' || num[1] == '0' || num[2] == '0')
            continue;

        flag = true;
        //스트라이크,볼 체크
        for (int i = 0; i < baseball.size(); i++)
        {
            diffnum = to_string(baseball[i][0]);
            s = 0;
            b = 0;
            for (int j = 0; j < num.size(); j++)
            {
                for (int k = 0; k < num.size(); k++)
                {
                    if (num[j] == diffnum[k] && j == k)
                    {
                        s++;
                        break;
                    }
                    else if (num[j] == diffnum[k])
                    {
                        b++;
                        break;
                    }
                }
            }
            if (baseball[i][1] != s || baseball[i][2] != b)
            {
                flag = false;
            }
        }

        if (flag) answer++;
    }
    return answer;
}
