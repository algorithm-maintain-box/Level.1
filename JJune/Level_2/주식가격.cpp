#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> res{};

    for (auto i = 0; i < prices.size(); i++)
    {
        int sum = 0;
        for (auto k = i + 1; k < prices.size(); k++)
        {
            sum++;
            if ((prices[i] > prices[k]) || prices.size() == k + 1)
            {
                res.push_back(sum);
                break;
            }
        }
    }
    res.push_back(0);

    return res;
}

#include <iostream>
int main()
{
    for (auto iter : solution({1, 2, 3, 2, 3}))
    {
        std::cout << "Out : " << iter << std::endl;
    }
    return 0;
}