#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> frist{1, 2, 3, 4, 5};
    vector<int> second{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> point(3, 0);
    for (auto i = 0; i < answers.size(); i++)
    {
        if (answers[i] == frist[i % frist.size()])
        {
            point[0]++;
        }
        if (answers[i] == second[i % second.size()])
        {
            point[1]++;
        }
        if (answers[i] == third[i % third.size()])
        {
            point[2]++;
        }
    }

    vector<int> result {};
    int max_val = *max_element(point.begin(), point.end());
    for (auto i =1;i<4;i++)
    {
        if (point[i-1] == max_val)
        {
            result.emplace_back(i);
        }
    }

    return result;
}

#include <iostream>
template <typename T>
void vector_printer(vector<T> vec)
{
    for (auto iter : vec)
    {
        cout << iter << endl;
    }
    cout << endl;
}

#include <iostream>
int main()
{
    vector_printer(solution({1, 2, 3, 4, 5}));
    std::cout << "A : 1" << std::endl;

    vector_printer(solution({1, 3, 2, 4, 2}));
    std::cout << "A : 1,2,3" << std::endl;
    return 0;
}