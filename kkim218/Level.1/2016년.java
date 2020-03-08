import java.util.Calendar;

class Solution {
    public String solution(int a, int b) {
        String answer = "";
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        
        Calendar cal = Calendar.getInstance(); // 현재 날짜
        cal.set(Calendar.YEAR, 2016); // 현재 년도
        cal.set(Calendar.MONTH, a - 1); // 현재 월 (1월은 0) 
        cal.set(Calendar.DAY_OF_MONTH, b); // 현재 월의 날짜
        answer = week[cal.get(Calendar.DAY_OF_WEEK) - 1]; // 현재 요일 (일요일은 1)
        
        return answer;
    }
}
