#include <cmath>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY wallPositions
 *  2. INTEGER_ARRAY wallHeights
 */

#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <iostream>
#include <functional>

using namespace std;

int maxHeight(vector<int> wallPositions, vector<int> wallHeights)
{
    int max_val = 0;
    for (auto i = 1; i < wallPositions.size(); i++)
    {
        auto space = wallPositions[i] - wallPositions[i - 1] - 1;
        if (space <= 0)
        {
            continue;
        }

        auto range = abs(wallHeights[i] - wallHeights[i - 1]);
        auto forward = space - range;
        if (forward <= 0)
        {
            max_val = max(max_val, max(wallHeights[i], wallHeights[i - 1]));
        }
        else
        {
            range = max(wallHeights[i], wallHeights[i - 1]);

            if (forward % 2)
            {
                max_val = max(max_val, range + static_cast<int>(ceil((double)forward / 2)));
                // max_val = max(max_val, range + (forward / 2) +1);
            }
            else
            {
                max_val = max(max_val, range + (forward / 2));
            }
        }
    }

    return max_val;
}

int main()
{
    ofstream fout("/Users/jjune/Sources/Github/algorithm-maintain-box/Programers/JJune/Temporary/Temp1");

    string wallPositions_count_temp;
    getline(cin, wallPositions_count_temp);

    int wallPositions_count = stoi(ltrim(rtrim(wallPositions_count_temp)));

    vector<int> wallPositions(wallPositions_count);

    for (int i = 0; i < wallPositions_count; i++) {
        string wallPositions_item_temp;
        getline(cin, wallPositions_item_temp);

        int wallPositions_item = stoi(ltrim(rtrim(wallPositions_item_temp)));

        wallPositions[i] = wallPositions_item;
    }

    string wallHeights_count_temp;
    getline(cin, wallHeights_count_temp);

    int wallHeights_count = stoi(ltrim(rtrim(wallHeights_count_temp)));

    vector<int> wallHeights(wallHeights_count);

    for (int i = 0; i < wallHeights_count; i++) {
        string wallHeights_item_temp;
        getline(cin, wallHeights_item_temp);

        int wallHeights_item = stoi(ltrim(rtrim(wallHeights_item_temp)));

        wallHeights[i] = wallHeights_item;
    }

    int result = maxHeight(wallPositions, wallHeights);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}