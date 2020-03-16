#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//구글링
int solution(string name) {
    int answer = 0;
    int index = 0;
    string dump(name.size(), 'A');
    while (dump != name)
    {
        dump[index] = name[index];
        //ASCII 알파벳 비교
        answer += min(name[index] - 'A', 'Z' - name[index] + 1);
        //같으면종료
        if (dump == name)    break;
        //오른쪽 갈지 왼쪽 갈지
        for (int move = 1; move < name.size(); move++) {
            if (name[(index + move) % name.size()] != dump[(index + move) % name.size()]) {
                index = (index + move) % name.size();
                answer += move;
                break;
            }
            else if (name[(index + name.size() - move) % name.size()] != dump[(index + name.size() - move) % name.size()]) {
                index = (index + name.size() - move) % name.size();
                answer += move;
                break;
            }
        }
    }
    return answer;
}