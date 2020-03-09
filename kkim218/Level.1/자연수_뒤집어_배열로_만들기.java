class Solution {
  public int[] solution(long n) {
    int[] answer = new int[String.valueOf(n).length()];

    long temp;
    int idx = 0;

    while (n > 0) {
        temp = n % 10;
        n /= 10;

        answer[idx] = (int) temp;
        idx++;
    }

    return answer;

    }
}