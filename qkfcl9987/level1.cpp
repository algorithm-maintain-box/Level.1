#include <string>
#include <vector>

using namespace std;
//2016
string solution(int a, int b) {
    string week[7] = { "SUN","MON","TUE","WED","THU", "FRI","SAT" };
    int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int day = 4;
    for (int i = 0; i < a - 1; i++)
    {
        day += month[i];
    }

    return week[(day + b) % 7];
}

//�� ���� ������ ��
long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) {
        for (int i = b; a >= i; i++)
        {
            answer += i;
        }
    }
    else if (a <= b) {
        for (int i = a; b >= i; i++)
        {
            answer +=
        }
    }
    return answer;
}

//���ڼ��ڼ�
string solution(int n) {
    string answer = "";
    for (int i = 0; i < n / 2; i++)
    {
        answer += "����";
    }

    if (n % 2 == 1)
    {
        answer += "��";
    }
    return answer;
}

//�������
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            answer += i;
        }
    }
    return answer;
}

//�ڿ��� ������ �迭�� �����
vector<int> solution(long long n) {
    vector<int> answer;

    while (true)
    {
        answer.push_back(n % 10);
        n /= 10;

        if (n == 0)
            break;
    }

    return answer;
}

//���� ������ �Ǻ�
long long solution(long long n) {
    long long answer = 0;
    return n == pow((int)sqrt(n), 2) ? (long)pow((int)sqrt(n) + 1, 2) : -1;
}

//¦���� Ȧ��
string solution(int num) {
    string answer = "";
    return num % 2 == 0 ? "Even" : "Odd";
}
//�ݶ��� ����
int solution(int num) {
    int count = 0;
    while (num != 1)
    {
        num = num % 2 == 0 ? num / 2 : num * 3 + 1;
        count++;
        if (count > 450) break;
    }
    return count > 450 ? -1 : count;
}

//��� ���ϱ�
double solution(vector<int> arr) {
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    answer /= arr.size();
    return answer;
}

//�ϻ��� ��
bool solution(int x) {
    vector<int> vec;
    int x1 = x;
    while (true)
    {
        vec.push_back(x % 10);
        x /= 10;

        if (x == 0)
            break;
    }
    return x1 % accumulate(vec.begin(), vec.end(), 0) == 0 ? true : false;
}

//���簢�� �����
int main(void) {
    int a;
    int b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        for (int i = 0; i < a; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}