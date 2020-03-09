class Solution {
  public boolean solution(int x) {
    int sum = 0;
    int tmpX = x;
    while (tmpX > 0) {
        sum += tmpX % 10;
        tmpX /= 10; 
    }
		
    return x % sum == 0 ? true : false;
  }
}