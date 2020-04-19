#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// '독립시행 횟수 + 1(아무것도 초이스 안할 확률)'을 전부 곱하고 -1
int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> map{};

    for (auto iter : clothes)
    {
        map[iter[1]]++;
    }

    uint32_t result = 1;
    for (auto iter : map)
    {
        result *= (iter.second + 1);
    }

    return result - 1;
}

#include <iostream>
int main()
{
    std::cout << "MINE : " << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << " A : 5" << std::endl;
    std::cout << "MINE : " << solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}) << " A : 3" << std::endl;
    return 0;
}