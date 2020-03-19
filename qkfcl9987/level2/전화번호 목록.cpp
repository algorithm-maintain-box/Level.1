#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), less<string>());
    for (int i = 0; i < phone_book.size(); i++) 
    {
        for (int j = 0; j < phone_book.size(); j++)
        {
            if (phone_book[i] == phone_book[j]) continue;

            if (phone_book[j].size() > phone_book[i].size() && phone_book[j].substr(0, phone_book[i].size()) == phone_book[i])
            {
                return false;
            }
        }
    }
    return answer;
}


