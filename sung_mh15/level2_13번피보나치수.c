#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {

	int answer = 0;
	int previous_vlaue = 0;

	for(int i = 0 ; i <=n ; i ++){
		if (i == 0)
			answer += 0;
		else if (i == 1) {
			answer += 1;
			previous_vlaue = 0;
		}
		else {
			int temp = previous_vlaue;
			previous_vlaue = answer % 1234567;
			answer = answer %1234567 + temp;
		}
	}

	return answer %1234567;
}
