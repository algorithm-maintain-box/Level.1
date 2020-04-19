#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<uint32_t> running{};
    uint32_t sum = 0;
    uint32_t time = 1;
    uint16_t end = 0;

    for (auto iter : truck_weights)
    {
        while (weight < sum + iter || bridge_length == running.size())
        {
            time = time > bridge_length + running.front() ? time : bridge_length + running.front();
            sum -= truck_weights[end++];
            running.pop();
        }

        sum += iter;
        running.push(time);

        time++;
    }

    return running.back() + bridge_length;
}

#include <iostream>
int main()
{
    // std::cout << "Out : " << solution(1, 2, {1, 1, 1}) << std::endl;
    // std::cout << "Out : " << solution(1, 1, {1, 1, 1}) << std::endl;
    // std::cout << "Out : " << solution(4, 2, {1, 1, 1, 1}) << std::endl;
    // std::cout << "Out : " << solution(3, 3, {1, 1, 1}) << std::endl;
    // std::cout << "Out : " << solution(3, 1, {1, 1, 1}) << std::endl;

    // std::cout << "Out : " << solution(5, 5, {1, 1, 1, 1, 1, 2, 2}) << std::endl;
    // std::cout << "Out : " << solution(7, 7, {1, 1, 1, 1, 1, 3, 3}) << std::endl;
    // std::cout << "Out : " << solution(5, 5, {1, 1, 1, 1, 1, 2, 2, 2, 2}) << std::endl;
    std::cout << "Out : " << solution(5, 5, {2, 2, 2, 2, 1, 1, 1, 1, 1}) << std::endl;

    return 0;
}