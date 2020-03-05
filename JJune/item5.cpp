#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
    auto str = to_string(n);
    vector<int> res{};

    auto start_pos = str.size();

    while (start_pos != 0)
    {
        auto str2 = str.substr(--start_pos, 1);
        res.push_back(stoi(str2));
    }
    return res;
}

#include <iostream>
int main()
{
    std::cout << "Out : ";
    for (auto it : solution(12345))
    {
        std::cout << to_string(it);
    }
    std::cout << std::endl;
    return 0;
}