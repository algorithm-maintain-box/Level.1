#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    answer.resize(arr2.size());

    // index로 변경해서 다시 풀어볼것
    for (auto iter : arr1)
    {
        for (auto i = 0; i < arr2[0].size(); i++)
        {
            int sum = 0;

            for (auto k = 0; k < arr2.size(); k++)
            {
                sum += iter[k] * arr2[k][i];
            }

            answer[i].push_back(sum);
        }
    }

    return answer;
}

#include <iostream>
template <typename T>
void vector_printer(vector<T> vec)
{
    for (auto iter : vec)
    {
        for (auto iter_ : iter)
        {
            cout << iter_ << " ";
        }
        cout << ", ";
    }

    cout << endl;
}

int main()
{
    vector_printer(solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}}));
    cout << "A : {{15,15},{15,15},{15,15}}" << endl;

    vector_printer(solution({{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}));
    cout << "A : {{22,22,11},{36,28,18},{29,20,14}}" << endl;
    return 0;
}