/* Language - C++14 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input_cnt = 0;
    cin >> input_cnt;
    input_cnt *= 2;

    vector<map<string, vector<string>>> input{};

    map<string, vector<string>> temp_input{};
    vector<string> temp_song{};
    int temp_idx = 0;

    while (input_cnt)
    {
        string str{};
        getline(cin, str);

        stringstream ss(str);

        string name{};
        while (ss >> name)
        {
            if (!(input_cnt % 2))
            {
                temp_song.emplace_back(name);
            }
            else
            {
                temp_input[name].push_back(temp_song[temp_idx++]);
            }
        }

        if (input_cnt % 2)
        {
            input.push_back(temp_input);
            temp_song.clear();
        }

        if (!str.empty())
        {
            input_cnt--;
        }
    }

    for (auto i = 0; i < input.size(); i++)
    {
        size_t max_size = 0;
        for (auto iter : input[i])
        {
            max_size = max(iter.second.size(), max_size);
        }

        for (auto detail : input[i])
        {
            for (auto k = detail.second.size(); k < max_size; k++)
            {
                input[i][detail.first].emplace_back("");
            }

            shuffle(input[i][detail.first].begin(),
                    input[i][detail.first].end(),
                    default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        }
    }

    for (auto i = 0; i < input.size(); i++)
    {
        auto map_iter = input[i].begin();
        map_iter->second.size();
        for (auto k = 0; k < map_iter->second.size(); k++)
        {
            for (auto iter : input[i])
            {
                cout << iter.second[k] << " ";
            }
        }
        
        cout << endl;
    }

    return 0;
}