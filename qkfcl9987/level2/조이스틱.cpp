#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//���۸�
int solution(string name) {
    int answer = 0;
    int index = 0;
    string dump(name.size(), 'A');
    while (dump != name)
    {
        dump[index] = name[index];
        //ASCII ���ĺ� ��
        answer += min(name[index] - 'A', 'Z' - name[index] + 1);
        //����������
        if (dump == name)    break;
        //������ ���� ���� ����
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