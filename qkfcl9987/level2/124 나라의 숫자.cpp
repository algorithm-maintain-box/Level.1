#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int Remainder;

    while (n != 0)
    {
        Remainder = n % 3;
        n = n / 3;

        if (Remainder == 0)
        {
            Remainder = 4;
            n -= 1;
        }
        answer = to_string(Remainder) + answer;
    }
    return answer;
}