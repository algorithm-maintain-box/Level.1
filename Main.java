package com.company;

import java.util.ArrayList;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        Solution solution = new Solution();

        solution.solution(new String[]{"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan",
        "Leave uid1234"});

    }

    static class Solution {
        public String[] solution(String[] record) {
            HashMap<String, String> map = new HashMap<>();
            int count=0; int idx=0;

            for(int i=0; i<record.length; i++){  // key, value 값 만들기
                String[] recordSplit = record[i].split(" ");
                if(!recordSplit[0].equals("Leave")){
                    map.put(recordSplit[1], recordSplit[2]);
                }

                if(!recordSplit[0].equals("Change")){
                    count++;
                }
            }

            String[] answer = new String[count]; // answer 생성

            for(int j=0; j<record.length; j++){
                String[] recordSplit = record[j].split(" ");
                if(recordSplit[0].equals("Enter")){
                    answer[idx] = map.get(recordSplit[1])+"님이 들어왔습니다.";
                    idx++;
                } else if(recordSplit[0].equals("Leave")){
                    answer[idx] = map.get(recordSplit[1])+"님이 나갔습니다.";
                    idx++;
                }
            }

            return answer;
        }
    }


}
