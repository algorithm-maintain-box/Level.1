#include <vector>

using namespace std;

int result = 0;

void dfs(vector<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }

    int odd = 0;
    int even = 0;
    for (auto i = 0; i < arr.size(); i++)
    {
        if (i % 2)
        {
            odd += arr[i];
        }
        else
        {
            even += arr[i];
        }
    }

    if (odd == even)
    {
        result++;
    }

    for (auto i = 0; i < arr.size(); i++)
    {
        vector<int> temp{};
        temp = arr;
        temp.erase(temp.begin() + i);
        dfs(temp);
    }
}

int countBalancingElements(vector<int> arr)
{
    dfs(arr);
}

#include <iostream>
int main()
{
    countBalancingElements({1, 2, 6, 4});
    cout << result << endl;
    result = 0;

    countBalancingElements({3, 2, 2, 2});
    cout << result << endl;
    result = 0;

    countBalancingElements({5, 5, 5, 2, 5, 8});
    cout << result << endl;
    result = 0;
}