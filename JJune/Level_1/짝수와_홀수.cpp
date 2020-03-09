#include <string>
#include <vector>

using namespace std;

string solution(int num)
{
    return (num % 2) ? "Odd" : "Even";
}

#include <iostream>
int main()
{
    std::cout << "Out : " << solution(0) << std::endl;
    std::cout << "Out : " << solution(3) << std::endl;
    std::cout << "Out : " << solution(4) << std::endl;
    return 0;
}