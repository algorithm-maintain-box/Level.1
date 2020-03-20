#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 작은값 x 큰값
int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(),
         A.end(),
         less<int>());

    sort(B.begin(),
         B.end(),
         greater<int>());

    int answer = 0;

    for (auto i = 0; i < A.size(); i++)
    {
        answer += (A[i] * B[i]);
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution({1, 4, 2}, {5, 4, 4}) << " A : 29" << std::endl;
    std::cout << "Out : " << solution({1, 2}, {3, 4}) << " A : 10" << std::endl;
    return 0;
}