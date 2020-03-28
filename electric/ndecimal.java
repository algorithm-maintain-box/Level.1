package com.company;


public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(4,4,2,1);
    }

    static class Solution {
        public String solution(int n, int t, int m, int p) {
            String answer = ""; String entire = "";
            StringBuilder sb = new StringBuilder();
            int idx = p;
            int value = 0;
            while(true){
                sb.append(conveter(n, value));
                value++;
                if(sb.length() > t*m)
                    break;
            }
            entire = sb.toString();
            for(int i=0; i<t; i++){
                answer = entire.charAt(idx) + answer;
                idx = idx+m;
            }
            System.out.println(answer);
            return answer;
        }

    public static String conveter(int n, int value){
        String result ="";
        StringBuilder sb = new StringBuilder();
        while(value != 0){

            if ( (value % n) < 10){ // 나머지 10 이하
                sb.append((value%n));
                value = value/n;
            } else {
                int alpha = (char) ((value%n) + 55);
                sb.append(Integer.toString(alpha));
            }
            sb.reverse();
        }

        return sb.toString();
    }


}}
