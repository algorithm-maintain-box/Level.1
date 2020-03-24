#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < nums_len - 2; i++) {
		for (int j = i + 1; j < nums_len - 1; j++) {
			for (int k = j + 1; k < nums_len; k++) {
				int prime_yes = 0; // 주어진 수가 소수이면 0반환
				sum = nums[i] + nums[j] + nums[k];
				for (int l = 2; l < sum; l++) {
					if ((sum%l) == 0)
						prime_yes = 1;
				}
				if (prime_yes == 0)
					answer++;
			}
		}
	}
	return answer;
}
