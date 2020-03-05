#include <string>
#include <vector>

using namespace std;

vector<string> day_vec{"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
vector<uint8_t> mon_vec{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b)
{
    uint16_t max_day = b;

    while (--a)
    {
        max_day += mon_vec[a - 1];
    }

    return day_vec[((max_day -1) % 7)];
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(1, 1) << std::endl;
    std::cout << "Out : " << solution(1, 7) << std::endl;
    std::cout << "Out : " << solution(5, 24) << std::endl;
    std::cout << "Out : " << solution(8, 24) << std::endl;
    return 0;
}