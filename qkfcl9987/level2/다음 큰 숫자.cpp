#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int count = 0;
    int diffcount = 0;
    //n 1갯수 구하기
    while (true)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n = n / 2;
        if (n == 0)
        {
            break;
        }
        else if (n == 1)
        {
            count++;
            break;
        }
    }
    //n++ 반복 1갯수 맞으면 그만
    while (true)
    {
        answer++;
        diffcount = 0;
        int num = answer;
        while (true)
        {
            if (num % 2 == 1)
            {
                diffcount++;
            }
            num = num / 2;
            if (num == 0)
            {
                break;
            }
            else if (num == 1)
            {
                diffcount++;
                break;
            }
        }
        if (diffcount == count) break;
    }
    return answer;
}