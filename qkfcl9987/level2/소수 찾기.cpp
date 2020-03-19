#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector <int> v;
bool allUsed(int i, string numbers);
//���۸���
int solution(string numbers) {
    int answer = 0;
    int max = 0;

    // numbers �� �ڸ� ���� v�� �ֱ�
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(stoi(numbers.substr(i, 1)));
    }

    // numbers ���ڸ� ������������ ����
    sort(v.begin(), v.end(), greater<int>());

    // max ���ϱ�
    for (int i = 0; i < v.size(); i++) {
        max = max + (v[i] * pow(10, v.size() - 1 - i));
    }

    vector <bool> isPrime(max + 1, true);

    // ���� Ž��
    for (int i = 2; i <= max; i++) {
        if (isPrime[i]) {
            // i�� numbers�� ��Ÿ�������� ���ڸ� answer++ 
            if (allUsed(i, numbers)) {
                answer++;
            }

            // �Ҽ� �ƴ� �͵� false��
            for (int j = 2; i * j <= max; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    return answer;
}
bool allUsed(int i, string numbers) {
    string si = to_string(i);

    for (int j = 0; j < si.size(); j++) {
        int index = numbers.find(si.substr(j, 1));
        int ss = numbers.size();
        // ���ؾȵ�
        if (index >= numbers.size()) {
            return false;
        }
        else {
            numbers = numbers.substr(0, index) + numbers.substr(index + 1);
        }
    }

    return true;
}