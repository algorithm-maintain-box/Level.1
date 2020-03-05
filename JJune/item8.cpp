#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
    uint64_t cal_num = num;
    uint16_t max_cnt = 0;
    while (cal_num != 1)
    {
        if (max_cnt++ >= 500)
        {
            return -1;
        }

        if (cal_num % 2)
        {
            cal_num = cal_num * 3 + 1;
        }
        else
        {
            cal_num = cal_num / 2;
        }
    }

    return max_cnt;
}


#include <iostream>
int main()
{
    cout << "Out :" << sizeof(long) << endl;
    cout << "Out :" << sizeof(int) << endl;
    cout << "Out :" << solution(6) << endl;
    cout << "Out :" << solution(16) << endl;
    cout << "Out :" << solution(626331) << endl;

    return 0;
}