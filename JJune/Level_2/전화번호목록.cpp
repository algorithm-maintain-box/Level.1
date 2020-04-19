#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(),
         phone_book.end());

    for (auto i = 0; i < phone_book.size() - 1; i++)
    {
        auto pos = phone_book[i + 1].find(phone_book[i]);
        if (pos != string::npos && pos == 0)
        {
            return false;
        }
    }

    return true;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({"119", "97674223", "1195524421"}) << " A : 0" << std::endl;
    std::cout << "MINE : " << solution({"123", "456", "789"}) << " A : 1" << std::endl;
    std::cout << "MINE : " << solution({"12", "123", "1235", "567", "88"}) << " A : 0" << std::endl;
    std::cout << "MINE : " << solution({"1192456", "119"}) << " A : 0" << std::endl;
    std::cout << "MINE : " << solution({"119", "1192456"}) << " A : 0" << std::endl;
    return 0;
}