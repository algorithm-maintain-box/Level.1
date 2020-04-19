#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s)
{
#if 0
    stringstream ss(s);
    int value = 0;
    vector<int> vec {};

    while(ss >> value)
    {
        vec.emplace_back(value);
    }

    sort(vec.begin(), vec.end(), less<int>());

    return string(to_string(vec[0]) + " " + to_string(vec[vec.size()-1]));
#else

    vector<int> vec{};
    size_t pos = 0;
    while ((pos = s.find_first_of(" ")) != string::npos)
    {
        auto str = s.substr(0, pos);
        vec.emplace_back(stoi(str));
        s = s.substr(pos + 1);
    }

    vec.emplace_back(stoi(s));
    sort(vec.begin(), vec.end(), less<int>());

    return string(to_string(vec[0]) + " " + to_string(vec[vec.size() - 1]));
#endif
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution("1 2 3 4") << " A : 1 4" << std::endl;
    std::cout << "Out : " << solution("-1 -2 -3 -4") << " A : -4 -1" << std::endl;
    std::cout << "Out : " << solution("-1 -1") << " A : -1 -1" << std::endl;
    return 0;
}