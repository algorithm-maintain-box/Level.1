
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
	long answer = 1;
	int sw = 0;
	while (sw != 1) {//계속더해가면서 그 수가 모든 배열의 수로 처음나눠질때 멈춤
		//최소공배수 = 구성수들로 나누어지는가장 작은 수
		for (int j = 0; j < arr_len; j++) {
			if (answer % arr[j] != 0) sw = 1;
		}
		if (sw == 0) {
			break;
		}
		else {
			answer++;
		}
		sw = 0;
	}
	return answer;
}
