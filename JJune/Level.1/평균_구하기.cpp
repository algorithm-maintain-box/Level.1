#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
    double res = 0;

    for (auto it : arr)
    {
        res += it;
    }

    res /= arr.size();

    return res;
}

#include <iostream>
int main()
{
    cout << "Out :" << solution(std::vector<int>{1,2,3,4}) << endl;
    cout << "Out :" << solution(std::vector<int>{5,5}) << endl;
    cout << "Out :" << solution(std::vector<int>{-5,5}) << endl;
    cout << "Out :" << solution(std::vector<int>{5}) << endl;
    return 0;
}