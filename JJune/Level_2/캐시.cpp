#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    transform(cities.begin(),
              cities.end(),
              cities.begin(),
              [](string &str) {
                  for (auto &iter : str)
                  {
                      iter = tolower(iter);
                  }

                  return str;
              });

    int answer = 0;
    if (!cacheSize)
    {
        return 5 * cities.size();
    }

    vector<string> cache{};
    for (auto iter : cities)
    {
        auto pos = find(cache.begin(), cache.end(), iter);
        if (pos != cache.end())
        {
            answer++;
            cache.erase(pos);
        }
        else
        {
            answer += 5;
            if (cache.size() >= cacheSize)
            {
                cache.erase(cache.begin());
            }
        }

        cache.emplace_back(iter);
    }

    return answer;
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << " / A : 50" << std::endl;
    return 0;
}