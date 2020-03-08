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

//두 정수 사이의 합
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

//수박수박수
string solution(int n) {
    string answer = "";
    for (int i = 0; i < n / 2; i++)
    {
        answer += "수박";
    }

    if (n % 2 == 1)
    {
        answer += "수";
    }
    return answer;
}

//약수의합
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

//자연수 뒤집어 배열로 만들기
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

//정수 제곱근 판별
long long solution(long long n) {
    long long answer = 0;
    return n == pow((int)sqrt(n), 2) ? (long)pow((int)sqrt(n) + 1, 2) : -1;
}

//짝수와 홀수
string solution(int num) {
    string answer = "";
    return num % 2 == 0 ? "Even" : "Odd";
}
//콜라츠 추측
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

//평균 구하기
double solution(vector<int> arr) {
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    answer /= arr.size();
    return answer;
}

//하샤드 수
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

//직사각형 별찍기
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