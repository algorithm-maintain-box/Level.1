//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
//	int answer = 0;
//	priority_queue<int, vector<int>> pq;
//	int index = 0;
//	while (k > stock)
//	{
//		//��ƿ�� �ִ� ������ ���� pq �ֱ�
//		for (int i = index; i < dates.size() && stock >= dates[i]; i++)
//		{
//			pq.push(supplies[i]);
//			index = i + 1;
//		}
//
//		stock += pq.top();
//		pq.pop();
//		answer++;
//	}
//	return answer;
//}