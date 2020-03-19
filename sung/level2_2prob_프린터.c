#include <stdio.h>
#include <stdlib.h>

int solution(int * priorities, int location, int size) {

	int numberOfOut = 0;//나간 것의 갯수
	int index = location ;//우리가 지정한 원소가 몇 번째 출력되는 알기 위해서는 위치를 index로 저장하고 추적해야한다.

	while (size > 0) {
		int yes_or_no = 1; //priorities의 첫 번째 것보다 우선 순위 높은 것이 없어서 인쇄되면
		//yes == 1(default) 인쇄되지 못하고 맨뒤로 가면 no == 0

		for (int i = 0; i < size; i++) {
			if (priorities[0] < priorities[i]) {
				int temp = priorities[0];
				int j = 0;
				while (j < size-2) {
					priorities[j] = priorities[j + 1];
					j++;
				}
				priorities[size-1] = temp;

				if (index == 0) {
					index = size-1;//맨 앞이였을 경우 맨뒤로 밀리므로
				}
				else {
					index--;// 앞으로 한칸 땡겨 졌으므로
				}

				yes_or_no = 0;
				break;
			}
		}

		if (yes_or_no == 0) {
			continue;//맨 앞것 보다 우선 순위 높은 것이 있기 때문에 다음 차례로 가야됨
		}
		else {
			numberOfOut++;
			if (0 == index) {//지정한 것이 인쇄되면 인쇄된 순서, 즉 여태 인쇄된것의 개수를 반환하면 된다
				return numberOfOut;
			}


			//맨앞에 있는 것을 인쇄하고 그 나머지를 한칸씩 땡기기

			for (int k = 0; k < size-1; k++) {
				priorities[k] = priorities[k + 1];
			}

			index--;//앞으로 한칸 땡겨 졌으므로
			size--;
		}

	}

}


int main(void) {

	int a[] = { 1, 1,9 ,1, 1,1};
	printf("%d\n\n", solution(a, 0, sizeof(a)/sizeof(int)));

	int b[] = { 2,1,3,2 };
	printf("%d\n\n", solution(b, 2, sizeof(b)/sizeof(int)));

}
