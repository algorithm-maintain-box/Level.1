void quick_sort(int data[], int left, int right){

	int i, j, key, temp;
	if (left < right) {
		i = left;
		j = right + 1;
		key = data[left];
		do {
			do {
				i++;
			} while (data[i] < key);
			do{
				j--;
			} while (data[j] > key);
			if (i < j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		} while (i < j);
		temp = data[left];
		data[left] = data[j];
		data[j] = temp;
		quick_sort(data, left, j - 1);
		quick_sort(data, j + 1, right);
	}
}


int solution(int a[], size_t a_len, int b[], size_t b_len) {

	//a 는 오름차순 정렬 , b는 내림차순정렬
	quick_sort(a, 0, a_len-1);
	quick_sort(b, 0, b_len-1);
	int answer = 0;
	for (int k = 0; k < a_len; k++) {
		answer += a[k] * b[b_len-(k)-1];
	}
	return answer;
}
