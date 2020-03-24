#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
	int idx = 0;
	int length = strlen(s);
	int count = 0;
	char * stack = (char *)malloc(sizeof(char)*length);

	while (s[idx]) {
		if (s[idx++] == '(') {
			stack[count++] = '(';
		}
		else {
			if (stack[count - 1] == '(') {
				count--;
			}
			else { stack[count++] = ')'; }
		}
	}

	bool answer = true;

	if (count!=0)
		return false;
	return answer;
}
