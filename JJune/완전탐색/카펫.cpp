#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red)
{
    vector<int> result{};

    auto max = brown + red;
    for (auto h = 3;; h++)
    {
        // 가로, 세로 체크
        if (!(max % h))
        {
            auto w = max / h;

            // red 값 체크
            if ((h - 2)*(w - 2) == red)
            {
                result.emplace_back(w);
                result.emplace_back(h);
                break;
            }
        }
    }

    return result;
}