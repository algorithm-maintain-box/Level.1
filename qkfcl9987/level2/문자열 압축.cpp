#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.size() / 2; i++)
    {
        int len = s.size();
        for (int j = 0; j < s.size(); j++)
        {
            for (int count = 0, k = i; j + k < s.size(); k += i)
            {
                if (s.substr(j, i) == s.substr(j + k, i))
                {
                    count++;
                }
                else
                {
                    len -= count * i;
                    if (count != 0)
                    {
                        len += to_string(count + 1).size();
                    }
                    j += k - 1;
                    break;
                }

                if (i + j + k >= s.size())
                {
                    len -= i * count;
                    len += to_string(count + 1).size();
                    j += k;
                }
            }
        }
        if (answer > len) answer = len;
    }
    return answer;
}