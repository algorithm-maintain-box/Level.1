#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int value = 0;
	vector<int> temp;
	map<string, int> hash;
	for (int i = 0; i < clothes.size(); i++) {
		hash[clothes[i][1]]++;
	}
	map<string, int>::iterator iter = hash.begin();
	for (iter = hash.begin(); iter != hash.end(); iter++) 
	{
		answer *= (iter->second + 1);  //의상 종류수 * (의상 이름 수 +1) -1
	}
	return answer -1;
}

int main()
{
    vector<vector<string>> t = { {"yellow_hat", "headgear54"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear54"},{"green_turban2", "eyewear"},{"green_turba3n", "headgear"},{"green_turba233n", "headgear"} };
    solution(t);
}