#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    //세로 최소 3
    int v = 3;
    while (true)
    {
        if ((brown + red) % v == 0)
        {
            //red = 가로 -2 * 세로 -2
            if (((brown + red) / v - 2) * (v - 2) == red)
            {
                answer = { (brown + red) / v,v };
                break;
            }
        }
        v++;
    }
    return answer;
}