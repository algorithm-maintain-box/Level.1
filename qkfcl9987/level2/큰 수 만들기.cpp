#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> temp;
    int digits = number.size() - k;

    for (int i = digits; 0 < i; i--)
    {
        int dump = 0;
        int index = 0;
        //높은 숫자 뽑기
        for (int j = 0; j < number.size() - i + 1; j++)
        {
            if (dump < number[j])
            {
                dump = number[j];
                index = j;
            }
        }
        //높은 숫자까지 전부 공백
        number.replace(0, index + 1, " ");
        temp.push_back(dump);
    }
    for (int i = 0; i < temp.size(); i++)
        answer += temp[i];
    return answer;
}