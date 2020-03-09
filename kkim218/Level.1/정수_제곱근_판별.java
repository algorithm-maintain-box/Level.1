class Solution {
  public long solution(long n) {
      long sqrt = (int)Math.sqrt(n); // 제곱근 값을 계산 ex) 121의 제곱근은 11 
      
      if (Math.pow(sqrt, 2) == n) // 거듭제곱 값을 계산 pow([대상 숫자], [거듭제곱 횟수])
          return (long)Math.pow((sqrt + 1), 2);
            
      return -1;
  }
}