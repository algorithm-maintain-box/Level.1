#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    //내림 차순
    sort(A.begin(), A.end());
    //오름 차순
    sort(B.begin(), B.end(), greater<int>());
    
    for (int i = 0; i < A.size(); i++) 
    {
        answer += A[i] * B[i];
    }


    return answer;
}