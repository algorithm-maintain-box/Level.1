#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    int count = 0;
    //��Ʈ�� -> int �迭
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == ' ') 
        {
            num.push_back(stoi(s.substr(count, i)));
            count = i + 1;
        }
    }
    //������ ����
    num.push_back(stoi(s.substr(count, s.length())));
    sort(num.begin(), num.end());
    answer = to_string(num.front()) + " " + to_string(num.back());
    return answer;
}